# RECTANGLE

```Java
class Rectangle

private:

Vector2D vector1;

Vector2D vector2;

Vector2D vector3;

Vector2D vector4;

public:

 1. Rectangle();
 2. Rectangle(Vector2D, Vector2D);
 3. Rectangle(double, double, double, double);
 4. Rectangle(Vector2D, Vector2D, Vector2D, Vector2D);
 5. Rectangle Rotation(Matrix2x2 r_matrix);
 6. Rectangle Translate(Vector2D t_vector);
 7. void Side_length();
 8. void Write_to_file(std::string filename, int mode); // mode-1:overwrite mode-2:append
 9. bool Check_Collision(Rectangle r2);
 10. friend bool operator==(const Rectangle &r1, const Rectangle &r2);
 11. friend std::ostream &operator<<(std::ostream &os, const Rectangle &r);
 12. friend std::ofstream &operator<<(std::ofstream &fs, const Rectangle &r);

```

The created Rectangle object has it's vertices oriented in the following way

```
	4. o____________o 3. Constructors are checking if input is valid
	   |			| 	 if shape other than rectangle is passed
	   | 			|    they will throw an exception.
	1. o____________o 2. Automatically assign correct value to expected corner
```

**1**-Default values,small square 1x1

**2**-Constructor from two oposing vertices (2 vectors)

**3**-First two values are x and y for first vector,and the other values are for the third vector

**4**-Testing constructor without checking if the input is valid,every value passed is for the vectors from 1-2-3-4

**5**-Rotation method,every vector of the rectangle is rotated by the passed matrix( Matrix2x2 \* Vector2D)

**6**-Move each vertice of rectangle,by adding passed vector to them

**7**-Check the lengths of the rectangle sides (subtract one vertice from another,and then calculate it's length)

**8**-Writing to file method mainly for animations,if passing the value in "1" mode it clears the file's content,while passing rectangle in "2" mode appends it's values to existing data in the file

**9**-Function which check if there is a collision between two rectangles.Mainly it is an implementation of the SAT algorithm from this website [[link]](https://www.gamedev.net/tutorials/_/technical/game-programming/2d-rotated-rectangle-collision-r2604/) .Basically optimised if there was not a collision on one axis,there surely will not be any collision at all so when such situation occurs the returned value is false,in other way true

**10**-Comparison method between two rectangles,if their vertices are the same,returned value is true

**11 and 12**-Both methods are basically passing each value of the vector to the prefered stream,the decimal places which are shown are set to _10_ and in the file stream method the first vertice is passed also at the end of the stream,for GNUPlot purposes
