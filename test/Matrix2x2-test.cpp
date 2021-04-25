#include "gtest/gtest.h"
#include "Matrix2x2.h"

TEST(Matrix2x2_Determinant, test1)
{
    Matrix2x2 m(2, 1, 1, 1);

    EXPECT_EQ(1, m.Determinant());

    Matrix2x2 m2(2, 2, 1, -1);

    EXPECT_EQ(-4, m2.Determinant());

    Matrix2x2 m3(5, 5, 9, 8);

    EXPECT_EQ(-5, m3.Determinant());

    Matrix2x2 m4(2, 3, 1, 0);

    EXPECT_EQ(-3, m4.Determinant());

    Matrix2x2 m5(48, 55.5, 0, -13);

    EXPECT_EQ(-624, m5.Determinant());
}

TEST(Matrix2x2_constructor, empty)
{
    Matrix2x2 m1;

    EXPECT_EQ(m1, Matrix2x2(0, 0, 0, 0));
}

TEST(Matrix2x2_constructor, two_vectors)
{
    Matrix2x2 m1(Vector2D(2, 3), Vector2D(0, 0));

    EXPECT_EQ(m1, Matrix2x2(2, 3, 0, 0));
}

TEST(Matrix2x2_constructor, x_y_doubles)
{
    Matrix2x2 m1(6, 4, 8, -7);

    EXPECT_EQ(m1, Matrix2x2(6, 4, 8, -7));
}

TEST(Matrix2x2_constructor, angle)
{
    Matrix2x2 m1(90);
    Matrix2x2 m2(30);

    EXPECT_EQ(m1, Matrix2x2(0, -1, 1, 0));
    EXPECT_EQ(m2, Matrix2x2(sqrt(3) / 2, -0.5, 0.5, sqrt(3) / 2));
}

TEST(Matrix2x2_indexop, test1)
{
    Matrix2x2 m(Vector2D(2, 3), Vector2D());

    EXPECT_EQ(m[0], Vector2D(2, 3));
    EXPECT_EQ(m[1], Vector2D());
    EXPECT_EQ(m[0][0], 2);
    EXPECT_EQ(m[0][1], 3);
    EXPECT_EQ(m[1][0], 0);
    EXPECT_EQ(m[1][1], 0);
    EXPECT_THROW(m[-1], std::invalid_argument);
    EXPECT_THROW(m[2], std::invalid_argument);
}

TEST(Matrix2x2_Vector2D_multiplication, test1)
{
    Matrix2x2 m(Vector2D(2, 3), Vector2D()), m2(Vector2D(2, 3), Vector2D(-5, 1));
    Vector2D w(1, 2);

    EXPECT_EQ(m * w, Vector2D(8, 0));
    EXPECT_EQ(m2 * w, Vector2D(8, -3));

    double sin_a, cos_a;
    double angle = 5;
    sin_a = sin(angle * M_PI / 180);
    cos_a = cos(angle * M_PI / 180);

    Matrix2x2 m3(Vector2D(cos_a, -sin_a), Vector2D(sin_a, cos_a));
    EXPECT_EQ(m3 * w, Vector2D(0.821883, 2.07955));
}
