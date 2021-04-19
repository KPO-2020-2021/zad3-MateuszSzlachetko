# VECTOR2D

```c++
class Vector2D


private:

double x;

double y;

public:

 1. Vector2D();
 2. Vector2D(double _x, double _y);
 3. Vector2D operator+(const Vector2D &w);
 4. Vector2D operator-(const Vector2D &w);
 5. double operator*(const Vector2D &w);
 6. Vector2D operator*(double scalar);
 7. double Length();
 8. friend bool operator==(const Vector2D &w1, const Vector2D &w2);
 9. friend std::ostream &operator<<(std::ostream &os, const Vector2D &w);
 10. friend std::istream &operator>>(std::istream &is, Vector2D &w);
 11. const double &operator[](int index) const;

```

**1**-Empty constructor default values x=0, y=0

**2**-Constructor with 2 values x=\_x , y=\_y

**3**-Overloaded + operator. Sum two vectors

**4**-Overloaded - operator. Subtract two vectors

**5**-Overloaded \* operator. Multiplication of two vectors,scalar (double) value as a product

**6**-Overloaded \* operator. Multiplication of vector and scalar value,vector as a product

**7**-Length of the vector returned as a double value $\sqrt{x*x +y*y}$

**8**-Comparison between two vectors,if their x and y values are the same,returned value is true,else false

**9**-Overloaded << operator.Pass the vector values to the stream as "x y"

**10**-Overloaded >> operator.Read vector values from the stream,if incorrect data type is passed,there will be thrown an error

**11**-Array [ ] operator,for [**0**] value shows x value of vector and for [**1**] value shows y,other values are concerned as an error
