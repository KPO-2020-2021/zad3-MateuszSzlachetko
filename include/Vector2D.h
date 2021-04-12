#ifndef VECTOR2D_H
#define VECTOR2D_H
#define MINDIFF 0.000105

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D();
    Vector2D(double _x, double _y);

    Vector2D operator+(const Vector2D &w);
    Vector2D operator-(const Vector2D &w);
    double operator*(const Vector2D &w); // Vector*Vector ~~> scalar
    Vector2D operator*(double scalar);
    double Length();

    friend bool operator==(const Vector2D &w1, const Vector2D &w2);
    friend std::ostream &operator<<(std::ostream &os, const Vector2D &w);
    friend std::istream &operator>>(std::istream &is, Vector2D &w);
    const double &operator[](int index) const;
};

#endif // VECTOR2D_H