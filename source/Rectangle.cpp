#include "Rectangle.h"

Rectangle::Rectangle()
{
    vector1 = Vector2D(0, 0);
    vector2 = Vector2D(1, 0);
    vector3 = Vector2D(1, 1);
    vector4 = Vector2D(0, 1);
}

Rectangle::Rectangle(Vector2D w1, Vector2D w2, Vector2D w3, Vector2D w4)
{
    vector1 = w1;
    vector2 = w2;
    vector3 = w3;
    vector4 = w4;
}

Rectangle::Rectangle(Vector2D w1, Vector2D w2)
{
    if (w1[0] != w2[0] && w1[1] != w2[1])
    {
        if (w1[0] < w2[0])
        {
            if (w1[1] < w2[1])
            {
                vector1 = w1;
                vector2 = Vector2D(w2[0], w1[1]);
                vector3 = w2;
                vector4 = Vector2D(w1[0], w2[1]);
            }
            else
            {
                vector1 = Vector2D(w1[0], w2[1]);
                vector2 = w2;
                vector3 = Vector2D(w2[0], w1[1]);
                vector4 = w1;
            }
        }
        else
        {
            if (w1[1] < w2[1])
            {
                vector1 = Vector2D(w2[0], w1[1]);
                vector2 = w1;
                vector3 = Vector2D(w1[0], w2[1]);
                vector4 = w2;
            }
            else
            {
                vector1 = w2;
                vector2 = Vector2D(w1[0], w2[1]);
                vector3 = w1;
                vector4 = Vector2D(w2[0], w1[1]);
            }
        }
    }
    else
    {
        throw std::invalid_argument("[Rectangle]Invalid parameters -> not oposing vertices");
    }
}

Rectangle::Rectangle(double _x1, double _y1, double _x2, double _y2)
{

    if (_x1 != _x2 && _y1 != _y2)
    {
        if (_x1 < _x2)
        {
            if (_y1 < _y2)
            {
                vector1 = Vector2D(_x1, _y1);
                vector2 = Vector2D(_x2, _y1);
                vector3 = Vector2D(_x2, _y2);
                vector4 = Vector2D(_x1, _y2);
            }
            else
            {
                vector1 = Vector2D(_x1, _y2);
                vector2 = Vector2D(_x2, _y2);
                vector3 = Vector2D(_x2, _y1);
                vector4 = Vector2D(_x1, _y1);
            }
        }
        else
        {
            if (_y1 < _y2)
            {
                vector1 = Vector2D(_x2, _y1);
                vector2 = Vector2D(_x1, _y1);
                vector3 = Vector2D(_x1, _y2);
                vector4 = Vector2D(_x2, _y2);
            }
            else
            {
                vector1 = Vector2D(_x2, _y2);
                vector2 = Vector2D(_x1, _y2);
                vector3 = Vector2D(_x1, _y1);
                vector4 = Vector2D(_x2, _y1);
            }
        }
    }
    else
    {
        throw std::invalid_argument("[Rectangle]Invalid parameters -> not oposing vertices");
    }
}

Rectangle Rectangle::Rotation(Matrix2x2 r_matrix)
{
    this->vector1 = r_matrix * vector1;
    this->vector2 = r_matrix * vector2;
    this->vector3 = r_matrix * vector3;
    this->vector4 = r_matrix * vector4;
    return *this;
}

void Rectangle::Side_length()
{
    double side1, side2, side3, side4;
    Vector2D tmp;

    tmp = vector1 - vector2;
    side1 = tmp.Length();
    tmp = vector4 - vector3;
    side2 = tmp.Length();
    tmp = vector1 - vector4;
    side3 = tmp.Length();
    tmp = vector2 - vector3;
    side4 = tmp.Length();

    std::cout << std::setprecision(10) << std::fixed;

    if (side1 > side3) // check which side is longer
    {
        if (std::abs(side1 - side2) <= 0.0000000001)
        {
            std::cout << "Longer sides are equal" << std::endl;
            std::cout << "First: " << side1 << std::endl;
            std::cout << "Second: " << side2 << std::endl;
        }
        else
        {
            std::cout << "Longer sides are not equal" << std::endl;
            std::cout << "First: " << side1 << std::endl;
            std::cout << "Second: " << side2 << std::endl;
        }
        if (std::abs(side3 - side4) <= 0.0000000001)
        {
            std::cout << "Shorter sides are equal" << std::endl;
            std::cout << "First: " << side3 << std::endl;
            std::cout << "Second: " << side4 << std::endl;
        }
        else
        {
            std::cout << "Shorter sides are not equal" << std::endl;
            std::cout << "First: " << side3 << std::endl;
            std::cout << "Second: " << side4 << std::endl;
        }
    }
    else
    {
        if (std::abs(side3 - side4) <= 0.0000000001)
        {
            std::cout << "Longer sides are equal" << std::endl;
            std::cout << "First: " << side3 << std::endl;
            std::cout << "Second: " << side4 << std::endl;
        }
        else
        {
            std::cout << "Longer sides are not equal" << std::endl;
            std::cout << "First: " << side3 << std::endl;
            std::cout << "Second: " << side4 << std::endl;
        }
        if (std::abs(side1 - side2) <= 0.0000000001)
        {
            std::cout << "Shorter sides are equal" << std::endl;
            std::cout << "First: " << side1 << std::endl;
            std::cout << "Second: " << side2 << std::endl;
        }
        else
        {
            std::cout << "Shorter sides are not equal" << std::endl;
            std::cout << "First: " << side1 << std::endl;
            std::cout << "Second: " << side2 << std::endl;
        }
    }
}

bool operator==(const Rectangle &r1, const Rectangle &r2)
{
    if (r1.vector1 == r2.vector1 && r1.vector2 == r2.vector2 && r1.vector3 == r2.vector3 && r1.vector4 == r2.vector4)
    {
        return true;
    }
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Rectangle &r)
{
    os << std::setprecision(10) << std::fixed;
    os << r.vector1 << std::endl;
    os << r.vector2 << std::endl;
    os << r.vector3 << std::endl;
    os << r.vector4 << std::endl;
    return os;
}

std::ofstream &operator<<(std::ofstream &fs, const Rectangle &r)
{
    fs << std::setprecision(10) << std::fixed;
    fs << r.vector1 << std::endl;
    fs << r.vector2 << std::endl;
    fs << r.vector3 << std::endl;
    fs << r.vector4 << std::endl;
    fs << r.vector1 << std::endl;
    return fs;
}

void Rectangle::Write_to_file(std::string filename, int mode)
{
    std::ofstream Data_file;

    if (mode == 1)
        Data_file.open(filename, std::ios::trunc); // overwrite mode
    else
        Data_file.open(filename, std::ios::app); // append mode

    if (Data_file.is_open())
    {
        if (mode == 1)
            Data_file << *this;
        else
        {
            Data_file << std::endl; // newline for cleaner output in the file
            Data_file << *this;
        }
    }
    else
    {
        throw std::invalid_argument("[Rectangle]file opening error\n");
    }

    Data_file.close();
}

Rectangle Rectangle::Translate(Vector2D t_vector)
{
    vector1 = vector1 + t_vector;
    vector2 = vector2 + t_vector;
    vector3 = vector3 + t_vector;
    vector4 = vector4 + t_vector;
    return *this;
}

bool Rectangle::Check_Collision(Rectangle r2)
{
    // 4-1 4-3
    //  .______
    //  |
    //  |

    Vector2D Axis1, Axis2, Axis3, Axis4;
    Axis1 = vector4 - vector1; // 4 1
    Axis2 = vector4 - vector3;

    Axis3 = r2.vector1 - r2.vector2;
    Axis4 = r2.vector1 - r2.vector4;

    Vector2D ProjectionA, ProjectionB;                           // two projections from points which created the axis
    Vector2D Projection1, Projection2, Projection3, Projection4; // four projections from the second rectangle

    double minFirst, maxFirst, minSecond, maxSecond; // min,maxes of projected values of each rectangle

    ProjectionA = Axis1 * ((vector4 * Axis1) / (Axis1.Length() * Axis1.Length()));
    ProjectionB = Axis1 * ((vector1 * Axis1) / (Axis1.Length() * Axis1.Length()));
    Projection1 = Axis1 * ((r2.vector1 * Axis1) / (Axis1.Length() * Axis1.Length()));
    Projection2 = Axis1 * ((r2.vector2 * Axis1) / (Axis1.Length() * Axis1.Length()));
    Projection3 = Axis1 * ((r2.vector3 * Axis1) / (Axis1.Length() * Axis1.Length()));
    Projection4 = Axis1 * ((r2.vector4 * Axis1) / (Axis1.Length() * Axis1.Length()));

    minFirst = std::min(ProjectionA * Axis1, ProjectionB * Axis1);
    maxFirst = std::max(ProjectionA * Axis1, ProjectionB * Axis1);

    minSecond = std::min(Projection1 * Axis1, Projection2 * Axis1);
    minSecond = std::min(minSecond, Projection3 * Axis1);
    minSecond = std::min(minSecond, Projection4 * Axis1);

    maxSecond = std::max(Projection1 * Axis1, Projection2 * Axis1);
    maxSecond = std::max(maxSecond, Projection3 * Axis1);
    maxSecond = std::max(maxSecond, Projection4 * Axis1);

    if (!(minSecond <= maxFirst && maxSecond >= minFirst))
        return false;
    //FIRST

    ProjectionA = Axis2 * ((vector4 * Axis2) / (Axis2.Length() * Axis2.Length()));
    ProjectionB = Axis2 * ((vector3 * Axis2) / (Axis2.Length() * Axis2.Length()));
    Projection1 = Axis2 * ((r2.vector1 * Axis2) / (Axis2.Length() * Axis2.Length()));
    Projection2 = Axis2 * ((r2.vector2 * Axis2) / (Axis2.Length() * Axis2.Length()));
    Projection3 = Axis2 * ((r2.vector3 * Axis2) / (Axis2.Length() * Axis2.Length()));
    Projection4 = Axis2 * ((r2.vector4 * Axis2) / (Axis2.Length() * Axis2.Length()));

    minFirst = std::min(ProjectionA * Axis2, ProjectionB * Axis2);
    maxFirst = std::max(ProjectionA * Axis2, ProjectionB * Axis2);

    minSecond = std::min(Projection1 * Axis2, Projection2 * Axis2);
    minSecond = std::min(minSecond, Projection3 * Axis2);
    minSecond = std::min(minSecond, Projection4 * Axis2);

    maxSecond = std::max(Projection1 * Axis2, Projection2 * Axis2);
    maxSecond = std::max(maxSecond, Projection3 * Axis2);
    maxSecond = std::max(maxSecond, Projection4 * Axis2);

    if (!(minSecond <= maxFirst && maxSecond >= minFirst))
        return false;
    //SECOND

    ProjectionA = Axis3 * ((r2.vector1 * Axis3) / (Axis3.Length() * Axis3.Length()));
    ProjectionB = Axis3 * ((r2.vector2 * Axis3) / (Axis3.Length() * Axis3.Length()));
    Projection1 = Axis3 * ((vector1 * Axis3) / (Axis3.Length() * Axis3.Length()));
    Projection2 = Axis3 * ((vector2 * Axis3) / (Axis3.Length() * Axis3.Length()));
    Projection3 = Axis3 * ((vector3 * Axis3) / (Axis3.Length() * Axis3.Length()));
    Projection4 = Axis3 * ((vector4 * Axis3) / (Axis3.Length() * Axis3.Length()));

    minFirst = std::min(ProjectionA * Axis3, ProjectionB * Axis3);
    maxFirst = std::max(ProjectionA * Axis3, ProjectionB * Axis3);

    minSecond = std::min(Projection1 * Axis3, Projection2 * Axis3);
    minSecond = std::min(minSecond, Projection3 * Axis3);
    minSecond = std::min(minSecond, Projection4 * Axis3);

    maxSecond = std::max(Projection1 * Axis3, Projection2 * Axis3);
    maxSecond = std::max(maxSecond, Projection3 * Axis3);
    maxSecond = std::max(maxSecond, Projection4 * Axis3);

    if (!(minSecond <= maxFirst && maxSecond >= minFirst))
        return false;
    //THIRD

    ProjectionA = Axis4 * ((r2.vector1 * Axis4) / (Axis4.Length() * Axis4.Length()));
    ProjectionB = Axis4 * ((r2.vector4 * Axis4) / (Axis4.Length() * Axis4.Length()));
    Projection1 = Axis4 * ((vector1 * Axis4) / (Axis4.Length() * Axis4.Length()));
    Projection2 = Axis4 * ((vector2 * Axis4) / (Axis4.Length() * Axis4.Length()));
    Projection3 = Axis4 * ((vector3 * Axis4) / (Axis4.Length() * Axis4.Length()));
    Projection4 = Axis4 * ((vector4 * Axis4) / (Axis4.Length() * Axis4.Length()));

    minFirst = std::min(ProjectionA * Axis4, ProjectionB * Axis4);
    maxFirst = std::max(ProjectionA * Axis4, ProjectionB * Axis4);

    minSecond = std::min(Projection1 * Axis4, Projection2 * Axis4);
    minSecond = std::min(minSecond, Projection3 * Axis4);
    minSecond = std::min(minSecond, Projection4 * Axis4);

    maxSecond = std::max(Projection1 * Axis4, Projection2 * Axis4);
    maxSecond = std::max(maxSecond, Projection3 * Axis4);
    maxSecond = std::max(maxSecond, Projection4 * Axis4);

    if (!(minSecond <= maxFirst && maxSecond >= minFirst))
        return false;
    //FOURTH

    return true;
}