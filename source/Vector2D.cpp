#include "Vector2D.h"

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double _x, double _y)
{
    this->x = _x;
    this->y = _y;
}

Vector2D Vector2D::operator+(const Vector2D &w)
{
    Vector2D result;
    result.x = x + w.x;
    result.y = y + w.y;
    return result;
}

Vector2D Vector2D::operator-(const Vector2D &w)
{
    Vector2D result;
    result.x = x - w.x;
    result.y = y - w.y;
    return result;
}

double Vector2D::operator*(const Vector2D &w)
{
    return (x * w.x + y * w.y);
}

Vector2D Vector2D::operator*(double scalar)
{
    Vector2D result;
    result.x = x * scalar;
    result.y = y * scalar;
    return result;
}

double Vector2D::Length()
{
    double result;
    result = sqrt(x * x + y * y);
    return result;
}

bool operator==(const Vector2D &w1, const Vector2D &w2)
{
    if (std::abs(w1.x - w2.x) <= MINDIFF && std::abs(w1.y - w2.y) <= MINDIFF)
    {
        return true;
    }
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Vector2D &w)
{
    os << w.x << " " << w.y;
    return os;
}

std::istream &operator>>(std::istream &is, Vector2D &w)
{
    is >> w.x >> w.y;
    if (is.fail())
    {
        w.x = 0;
        w.y = 0;
    }
    return is;
}

const double &Vector2D::operator[](int index) const
{
    if (index == 0)
    {
        return this->x;
    }
    if (index == 1)
    {
        return this->y;
    }
    else
    {
        throw std::invalid_argument("[Vector2D]Index out of range\n");
    }
}