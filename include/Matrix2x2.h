#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include "Vector2D.h"

class Matrix2x2
{
private:
    Vector2D vector1;
    Vector2D vector2;

public:
    Matrix2x2();                                               // empty
    Matrix2x2(Vector2D, Vector2D);                             // 2 vectors
    Matrix2x2(double _x1, double _y1, double _x2, double _y2); // value of every cell
    Matrix2x2(double angle);                                   // Matrix for Rotation,from angle

    Vector2D operator*(const Vector2D &w);
    friend bool operator==(const Matrix2x2 &m1, const Matrix2x2 &m2);
    const Vector2D &operator[](int index) const;
};

#endif // MATRIX2X2_H