# MATRIX2x2

```Java
class Matrix2x2


private:

Vector2D vector1;

Vector2D vector2;


public:

 1. Matrix2x2();
 2. Matrix2x2(Vector2D, Vector2D);
 3. Matrix2x2(double _x1, double _y1, double _x2, double _y2);
 4. Matrix2x2(double angle);
 5. Vector2D operator*(const Vector2D &w);
 6. friend bool operator==(const Matrix2x2 &m1, const Matrix2x2 &m2);
 7. const Vector2D &operator[](int index) const;

```

**1**-Set default values for matrix cells ( 0 , 0 , 0 , 0 )

**2**- Create a matrix from two 2D Vectors

**3**-Set value for each of matrix cells

**4**-Create a direct matrix for rotation purposes from passed angle

```c++
sin_a = sin(angle * M_PI / 180); // M_PI 20 decimal places
cos_a = cos(angle * M_PI / 180);
```

There are two double values,made inside the constructor body,using formula to calculate radians from degrees,
then the values are applied within below formula

| Vector  | x value | y value |
| ------- | ------- | ------- |
| Vector1 | cos_a   | -sin_a  |
| Vector2 | sin_a   | cos_a   |

**5**-Overloaded multiplication of Matrix and Vector. The product is a new Vector

**6**-Comparison between two Matrices,if both of theirs Vectors are equal,then returned value is true,else false

**7**-Array operator for taking out specific values of Matrix.If index is [**0**] it refers to first Vector.
If it is [**1**] it refers to second Vector,other values are considered as incorrect
