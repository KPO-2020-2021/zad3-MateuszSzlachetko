#include "gtest/gtest.h"
#include "Vector2D.h"

TEST(Vector2d_constructor, test1)
{
    Vector2D w;

    EXPECT_EQ(w, Vector2D(0, 0));
}

TEST(Vector2d_constructor, test2)
{
    Vector2D w1(10, 10), w2(-5, -5);

    EXPECT_EQ(w1, Vector2D(10, 10));
    EXPECT_EQ(w2, Vector2D(-5.000001, -5));
}

TEST(Vector2d_translation, test1)
{
    Vector2D w1(25, -12);
    Vector2D w2(3, 4);

    EXPECT_EQ(w1 + w2, Vector2D(27.9999, -7.9999));
    EXPECT_EQ(w1 + w2, Vector2D(28, -8));
}

TEST(Vector2d_translation, test2)
{
    Vector2D w1(15, 5);
    Vector2D w2(1.222, 3);

    EXPECT_EQ(w1 + w2, Vector2D(16.222, 8));
    EXPECT_EQ(w1 + w2, Vector2D(16.2221, 8.0001));
}

TEST(Vector2d_translation, test3)
{
    Vector2D w1;
    Vector2D w2;
    Vector2D c3(0.00001, 0);
    Vector2D c4(0.00009, 0);

    EXPECT_EQ(w1 + w2, Vector2D(0, 0));
    EXPECT_EQ(w1 + w2, Vector2D(0.0001, 0.0001));
    EXPECT_EQ(c3 + c4, Vector2D(0.00001, 0));
}

TEST(Vector2d_subtraction, test1)
{
    Vector2D w1(10, -12);
    Vector2D w2(3, 4);

    EXPECT_EQ(w1 - w2, Vector2D(7, -16));
}

TEST(Vector2d_show, test3)
{
    std::stringstream stream;

    stream << Vector2D();

    EXPECT_EQ(stream.str(), "0 0");
    stream.str(std::string());

    stream << Vector2D(10, -5);

    EXPECT_EQ(stream.str(), "10 -5");
    stream.str(std::string());

    stream << Vector2D(-0.0001, -25);

    EXPECT_EQ(stream.str(), "-0.0001 -25");
    stream.str(std::string());

    stream << Vector2D(12.77, 6);

    EXPECT_EQ(stream.str(), "12.77 6");
    stream.str(std::string());
}

TEST(Vector2d_read, test1)
{
    std::stringstream stream;
    Vector2D w;

    stream << "0 15\n";
    stream >> w;
    EXPECT_EQ(w, Vector2D(0, 15));

    stream << "11 1\n";
    stream >> w;
    EXPECT_EQ(w, Vector2D(11, 1));

    stream << "6 -2\n";
    stream >> w;
    EXPECT_EQ(w, Vector2D(6, -2));

    stream << "5.555 -4.778\n";
    stream >> w;
    EXPECT_EQ(w, Vector2D(5.555, -4.778));

    stream << "p 15\n";
    stream >> w;
    EXPECT_EQ(w, Vector2D(0, 0)); // if failed set (0,0)

    stream << "8 x\n";
    stream >> w;
    EXPECT_EQ(w, Vector2D(0, 0));
}

TEST(Vector2d_indexop, test1)
{
    Vector2D w(5, 0);

    EXPECT_EQ(w[0], 5);
    EXPECT_EQ(w[1], 0);
    EXPECT_THROW(w[-1], std::invalid_argument);
    EXPECT_THROW(w[2], std::invalid_argument);
}

TEST(Vector2d_length, test1)
{
    Vector2D w(10, 5);
    Vector2D w1(0, 5);
    Vector2D w2(12, 1);

    EXPECT_EQ(5 * sqrt(5), w.Length());
    EXPECT_EQ(5, w1.Length());
    EXPECT_EQ(sqrt(145), w2.Length());
}

TEST(Vector2d_multiplication, test1_scalar) // scalar value as a product
{
    Vector2D w(10, 5);
    Vector2D w1(0, 5);
    Vector2D w2(12, 1);

    EXPECT_EQ(25, w * w1);
    EXPECT_EQ(5, w1 * w2);
    EXPECT_EQ(125, w * w2);
}

TEST(Vector2d_multiplication, test1_vector) // vector2d as a product
{
    Vector2D w(10, 5);
    Vector2D w1(0, 3);
    Vector2D w2(12.111, -3);
    double a = 2.5;

    EXPECT_EQ(Vector2D(25, 12.5), w * a);
    EXPECT_EQ(Vector2D(0, 7.5), w1 * a);
    EXPECT_EQ(Vector2D(30.2775, -7.5), w2 * a);
}
