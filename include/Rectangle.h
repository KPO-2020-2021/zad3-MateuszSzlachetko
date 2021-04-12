#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Matrix2x2.h"

class Rectangle
{
private:
    Vector2D vector1; //   4. o____________o 3.         Constructors are checking if input is valid
    Vector2D vector2; //      |            |            if shape other than rectangle is passed
    Vector2D vector3; //      |            |            they will throw an exception.
    Vector2D vector4; //   1. o____________o 2.         Automatically assign correct value to expected corner

public:
    Rectangle();
    Rectangle(Vector2D, Vector2D);
    Rectangle(double, double, double, double);
    Rectangle(Vector2D, Vector2D, Vector2D, Vector2D); // testing constructor

    Rectangle Rotation(Matrix2x2 r_matrix);
    Rectangle Translate(Vector2D t_vector);
    void Side_length();
    void Write_to_file(std::string filename, int mode); // mode-1:overwrite      mode-2:append
    bool Check_Collision(Rectangle r2);

    friend bool operator==(const Rectangle &r1, const Rectangle &r2);
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &r);
    friend std::ofstream &operator<<(std::ofstream &fs, const Rectangle &r);
};

#endif // RECTANGLE_H