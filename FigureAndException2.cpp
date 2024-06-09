
#include <iostream>
#include <exception>
#include <string>

enum Shape
{
    figure,
    triangle,
    quadrilateral,
    rightAnglesTriangle,
    isoscelesTriangle,
    rectangle,
    equilateralTriangle,
    square,
    parallelogram,
    rhomb
};

class Bad_Figure : public std::exception
{
private:
    std::string s_exception;
public:
    Bad_Figure(std::string string) : s_exception(string) {}
    virtual const char* what() const override
    {
        return s_exception.c_str();
    }
};
void currect_Figure(Shape shape, float a, float b, float c, float d, float A, float B, float C, float D) {

    switch (shape)
    {
    case Shape::equilateralTriangle:
        if ((!((a == b) && (b == c) && (a == c))) && !((A == B) && (C == A) && (B == C))) throw Bad_Figure("Error creating a shape! Reason: The sides are not equal and the angles are not\n");
        else if (!((a == b) && (b == c) && (a == c))) throw Bad_Figure("Error creating a shape! Reason: The sides are not equal\n");
        else if (!((A == B) && (C == A) && (B == C))) throw Bad_Figure("Error creating a shape! Reason: The angles are not equal\n");
        break;
    case Shape::triangle:

        if ((A + B + C) != 180) throw Bad_Figure("Error creating a shape! Reason: The sum of the angles of a triangle is not equal to 180\n");
        break;
    case Shape::quadrilateral:
        if ((A + B + C + D) != 360) throw Bad_Figure("Error creating a shape! Reason: The sum of the angles of a quadrilateral is not equal to 360!\n");
        break;
    case Shape::isoscelesTriangle:
        if (a != c) throw Bad_Figure("Error creating a shape! Reason: Sides a and b are not equal!\n");
        else if (A != C) throw Bad_Figure("Error creating a shape! Reason: Angles a and b are not equal!\n");
        break;
    case Shape::parallelogram:
        if (!((a == c) && (b == d))) throw Bad_Figure("Error creating a shape! Reason: Sides a, c and b, d are not equal!\n");
        else if (!((A == C) && (B == D))) throw Bad_Figure("Error creating a shape! Reason: Angles A, C and B,D are not equal!\n");
        break;
    case Shape::rectangle:
        if (!((a == c) && (b == d))) throw Bad_Figure("Error creating a shape! Reason: Sides a, c and b, d are not equal!\n");
        else if (!((90 == A) && (90 == B) && (90 == C) && (90 == D))) throw Bad_Figure("Error creating a shape! Reason: Angles are not equal to 90!\n");
        break;
    case Shape::rhomb:
        if (!((a == c) && (c == b) && (b == d) && (c == d))) throw Bad_Figure("Error creating a shape! Reason: Sides are not equal!\n");
        else if (!((A == C) && (B == D))) throw Bad_Figure("Error creating a shape! Reason: Angles a,b and c,d are not equal!\n");
        break;
    case Shape::rightAnglesTriangle:
        if (C != 90) throw Bad_Figure("Error creating a shape! Reason: Angle C are not equal to 90!\n");
        break;
    case Shape::square:
        if (!((a == c) && (c == b) && (b == d) && (c == d))) throw Bad_Figure("Error creating a shape! Reason: Sides are not equal!\n");
        else if (!((90 == A) && (90 == B) && (90 == C) && (90 == D))) throw Bad_Figure("Error creating a shape! Reason: Angles are not equal to 90!\n");
        break;
    default:
        std::cout << "Nothing\n";
    }
}

class Figure
{
protected:
    int corners;
public:
    Figure()
    {
        this->corners = 0;
    }

};
class Triangle : public Figure
{
protected:

    std::string name_figure;
    float a, b, c;
    float A, B, C;
public:

    Triangle(float a, float b, float c, float A, float B, float C, std::string name = "Triangle", Shape shape = Shape::triangle)
    {
        try
        {
            currect_Figure(shape, a, b, c, 0, A, B, C, 0);
            this->name_figure = name;
            this->corners = 3;
            this->a = a; this->b = b; this->c = c;
            this->A = A; this->B = B; this->C = C;
            std::cout << name_figure << " (sides: a = " << a << ", b = " << b << ", c = " << c << "; angles: A = " << A << ", B = " << B << ", C = " << C << ";) is created!" << std::endl;

        }
        catch (const Bad_Figure& ex)
        {
            std::cerr << ex.what();
        }

    }

};
class Quadrilateral : public Figure
{
protected:

    std::string name_figure = "Quadrilateral";
    float a, b, c, d;
    float A, B, C, D;
public:
    Quadrilateral(float a, float b, float c, float d, float A, float B, float C, float D, std::string name = "Quadrilateral", Shape shape = Shape::quadrilateral)
    {
        try
        {
            currect_Figure(shape, a, b, c, d, A, B, C, D);
            this->name_figure = name;
            this->corners = 4;
            this->a = a; this->b = b; this->c = c; this->d = d;
            this->A = A; this->B = B; this->C = C; this->D = D;
            std::cout << name_figure << " (sides: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << "; angles: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << ";) is created!" << std::endl;

        }
        catch (const Bad_Figure& ex)
        {
            std::cerr << ex.what();
        }

    }
   
};

class RightAnglesTriangle : public Triangle
{
public:
    RightAnglesTriangle(float a, float b, float c, float A, float B) : Triangle(a, b, c, A, B, 90, "Right Angles Triangle", Shape::rightAnglesTriangle) { };
    
};
class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(float a, float b, float A, float B) : Triangle(a, b, a, A, B, A, "IsoscelesTriangle", Shape::isoscelesTriangle) {}
    
};
class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(float a) : Triangle(a, a, a, 60, 60, 60, "Equilateral Triangle",Shape::equilateralTriangle) { }

};
class Rectangle : public Quadrilateral
{
public:
    Rectangle(float a, float b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90, "Rectangle",Shape::rectangle) {}
};
class Square : public Quadrilateral
{
public:
    Square(float a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90, "Square", Shape::square) {
    }
   
};
class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(float a, float b, float A, float B) : Quadrilateral(a, b, a, b, A, B, A, B,"Parallelogram", Shape::parallelogram) {}
   
};
class Rhomb : public Quadrilateral
{
public:
    Rhomb(float a, float A, float B) : Quadrilateral(a, a, a, a, A, B, A, B, "Rhomb", Shape::rhomb) {
    }
    
};

int main()
{
    Triangle triangle = Triangle(42.f, 32.f, 43.f, 53.f, 53.f, 23.f);
    RightAnglesTriangle r_a_triagle = RightAnglesTriangle(23.f, 24.f, 35.f, 20.f, 43.f);
    IsoscelesTriangle isoscelesTriagle = IsoscelesTriangle(32.f, 43.f, 43.f, 65.f);
    EquilateralTriangle equilateralTriangle = EquilateralTriangle(32.f);
    Quadrilateral quadrilateral = Quadrilateral(50.f, 70.f, 32.f, 67.f, 85.f, 74.f, 54.f, 23.f);
    Rectangle rectangle = Rectangle(70.f, 30.f);
    Square square = Square(78.f);
    Parallelogram parallelogram = Parallelogram(32.f, 64.f, 70.f, 43.f);
    Rhomb rhomb = Rhomb(60.f, 64.f, 32.f);
}
