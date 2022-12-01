#include <iostream>

using namespace std;

class Shape{
public:	
	Shape(){width=1;height=1;}
	Shape(double a, double b): width(a), height(b) {}
	virtual double area() = 0 ;  // pure virtual function
	// {cout << "Base Shape cannot calculate area" << endl; return 0;}
	double get_Height(){return height;}
	double get_Width(){width = -1; return width;}
protected:
	double width;
	double height;
};


class Rectangle: public Shape{
public:
	Rectangle():Shape(){perimeter = 2*(width+height);} 
	Rectangle(double a, double b): Shape(a,b) {perimeter = 2*(width+height);}
	double area(){cout << "Rectangle area = " <<  width << " x " << height <<
		" = " << width * height << endl; return width * height;}
	void show(){cout << "Rectangle with width " << width << " height " << height;}
private:
	double perimeter;

};


class Triangle: public Shape{
public:
	Triangle():Shape(){} 
	Triangle(double a, double b): Shape(a,b) {}
	double area(){cout << "Triange area = 0.5 x" <<  width << " x " << height <<
		" = " << 0.5 * width * height << endl; return 0.5 *width * height;}

};

int main()
{
//	Shape s;
//	Shape s2(4,5);
// 	s2.area();
	Rectangle r1;
	Rectangle r2(4,5);
	r2.area();
	Triangle t1(3,5);
	t1.area();
	Shape * sptr = &t1;
	sptr->area();
	sptr = &r2;
	sptr->area();
	
	r2.get_Width();
	r2.show();
	

	return 0;

}
