#include "Matrix2x2.h"

Matrix2x2::Matrix2x2()
{
    vector1 = Vector2D(0, 0);
    vector2 = Vector2D(0, 0);
}

Matrix2x2::Matrix2x2(Vector2D w1, Vector2D w2)
{
    vector1 = w1;
    vector2 = w2;
}

Matrix2x2::Matrix2x2(double _x1, double _y1, double _x2, double _y2)
{
    vector1 = Vector2D(_x1, _y1);
    vector2 = Vector2D(_x2, _y2);
}

Matrix2x2::Matrix2x2(double angle)
{
    double sin_a, cos_a;
    sin_a = sin(angle * M_PI / 180); // M_PI 0. x20
    cos_a = cos(angle * M_PI / 180);

    vector1 = Vector2D(cos_a, -sin_a);
    vector2 = Vector2D(sin_a, cos_a);
}

Vector2D Matrix2x2::operator*(const Vector2D &w)
{
    return Vector2D(this->vector1 * w, this->vector2 * w);
}

bool operator==(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    if (m1.vector1 == m2.vector1 && m1.vector2 == m2.vector2)
    {
        return true;
    }
    else
        return false;
}

const Vector2D &Matrix2x2::operator[](int index) const
{
    if (index == 0)
    {
        return this->vector1;
    }
    else if (index == 1)
    {
        return this->vector2;
    }
    else
    {
        throw std::invalid_argument("[Matrix2x2]Index out of range\n");
    }
}