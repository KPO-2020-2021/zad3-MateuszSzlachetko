#include "gtest/gtest.h"
#include "Rectangle.h"

TEST(Rectangle_constructor, test1)
{
    Rectangle r1;
    EXPECT_EQ(r1, Rectangle(Vector2D(0, 0), Vector2D(1, 0), Vector2D(1, 1), Vector2D(0, 1)));
}

TEST(Rectangle_constructor, test2)
{
    Vector2D w1(3, 4);
    Vector2D w2(5, 6);
    Vector2D w3(5, 4);
    Vector2D w4(3, 6);
    Rectangle r1(w1, w2);
    EXPECT_EQ(r1, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));
    Rectangle r6(w3, w4);
    EXPECT_EQ(r1, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));
    Rectangle r7(w2, w1);
    EXPECT_EQ(r1, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));
    Rectangle r8(w4, w3);
    EXPECT_EQ(r1, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));

    EXPECT_THROW(Rectangle r2(w1, w4), std::invalid_argument);
    EXPECT_THROW(Rectangle r3(w2, w3), std::invalid_argument);
    EXPECT_THROW(Rectangle r4(w1, w3), std::invalid_argument);
    EXPECT_THROW(Rectangle r5(w2, w4), std::invalid_argument);
}

TEST(Rectangle_constructor, test3)
{
    Rectangle r1(3, 4, 5, 6);
    EXPECT_EQ(r1, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));
    Rectangle r6(5, 4, 3, 6);
    EXPECT_EQ(r6, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));
    Rectangle r7(5, 6, 3, 4);
    EXPECT_EQ(r7, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));
    Rectangle r8(3, 6, 5, 4);
    EXPECT_EQ(r8, Rectangle(Vector2D(3, 4), Vector2D(5, 4), Vector2D(5, 6), Vector2D(3, 6)));

    EXPECT_THROW(Rectangle r2(3, 4, 3, 6), std::invalid_argument);
    EXPECT_THROW(Rectangle r3(5, 6, 5, 4), std::invalid_argument);
    EXPECT_THROW(Rectangle r4(3, 4, 5, 4), std::invalid_argument);
    EXPECT_THROW(Rectangle r5(5, 6, 3, 6), std::invalid_argument);
}

TEST(Rectangle_SideLength, test1)
{
    Rectangle r1(0, 0, 1, 1);
    Rectangle r2(0, 0, 5, 5);
    Rectangle r3(-3, 4, -2, -2);
    r2.Side_length();
    r3.Side_length();
    std::stringstream test;

    testing::internal::CaptureStdout();
    r1.Side_length();
    std::string output = testing::internal::GetCapturedStdout();

    test << "Longer sides are equal\nFirst: 1.0000000000\nSecond: 1.0000000000\nShorter sides are equal\nFirst: 1.0000000000\nSecond: 1.0000000000\n";
    EXPECT_EQ(output, test.str());
    test.str(std::string());

    testing::internal::CaptureStdout();
    r2.Side_length();
    output = testing::internal::GetCapturedStdout();

    test << "Longer sides are equal\nFirst: 5.0000000000\nSecond: 5.0000000000\nShorter sides are equal\nFirst: 5.0000000000\nSecond: 5.0000000000\n";
    EXPECT_EQ(output, test.str());
    test.str(std::string());

    testing::internal::CaptureStdout();
    r3.Side_length();
    output = testing::internal::GetCapturedStdout();

    test << "Longer sides are equal\nFirst: 6.0000000000\nSecond: 6.0000000000\nShorter sides are equal\nFirst: 1.0000000000\nSecond: 1.0000000000\n";
    EXPECT_EQ(output, test.str());
    test.str(std::string());
}

TEST(Rectangle_Collision, test1)
{
    Rectangle r1(0, 0, 1, 1), r2(-1, -1, -2, -2), r3(0.5, 0.5, 2, 2);

    EXPECT_FALSE(r1.Check_Collision(r2));
    EXPECT_FALSE(r2.Check_Collision(r3));
    EXPECT_TRUE(r1.Check_Collision(r3));

    Rectangle a1(0, 0, 1, 1), a2(0, 0, -2, -2), a3(1, 1, 2, 2), a4(-5, 5, 0, 1);

    EXPECT_TRUE(a1.Check_Collision(a2));
    EXPECT_TRUE(a1.Check_Collision(a3));
    EXPECT_TRUE(a1.Check_Collision(a4));
    EXPECT_FALSE(a2.Check_Collision(a3));
    EXPECT_FALSE(a3.Check_Collision(a2));

    Rectangle b1(0, 0, 1, 1), b2(-1, 1, -2, 2); // with rotation
    int i = 0;
    EXPECT_FALSE(b1.Check_Collision(b2));
    while (i < 90)
    {
        b1.Rotation(Matrix2x2(1));
        i++;
    }
    EXPECT_TRUE(b1.Check_Collision(b2));

    Rectangle c1(0, 0, 5, 5), c2(-1, 1, -2, 2); // with rotation from both rectangles
    i = 0;
    EXPECT_FALSE(c1.Check_Collision(c2));
    while (i < 5)
    {
        c1.Rotation(Matrix2x2(10));
        c2.Rotation(Matrix2x2(1));
        i++;
    }
    EXPECT_TRUE(c1.Check_Collision(c2));
}

TEST(Rectangle_Translation, test1)
{
    Rectangle r1(0, 0, 1, 1);
    r1.Translate(Vector2D(10, 10));

    EXPECT_EQ(r1, Rectangle(10, 10, 11, 11));

    Rectangle r2(-5, -13.33, 1, 1);
    r2.Translate(Vector2D(5, 5));

    EXPECT_EQ(r2, Rectangle(0, -8.33, 6, 6));
}

TEST(Rectangle_Rotation, test1)
{
    Rectangle r1(0, 0, 1, 1);
    int i = 0;
    while (i < 360)
    {
        r1.Rotation(Matrix2x2(1));
        i++;
    }
    EXPECT_EQ(r1, Rectangle(0, 0, 1, 1));

    r1 = Rectangle(0, 0, 1, 1);

    i = 0;
    while (i < 36000000)
    {
        r1.Rotation(Matrix2x2(-1));
        i++;
    }
    EXPECT_EQ(r1, Rectangle(0, 0, 1, 1));
}