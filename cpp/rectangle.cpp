#include <iostream>

using namespace std;

class Rectangle{
	int width, height;
public:
	Rectangle();
	Rectangle(int a, int b);
	int area(){return width*height;}
	int get_height(){return height;};
	int get_width(){return width;}
};

Rectangle::Rectangle(){
	width = 1;
	height =1;
}

Rectangle::Rectangle(int a, int b){
	width = a;
	height = b;
}

int main()
{
	Rectangle r1;
	Rectangle r2(5,6);
	Rectangle * rptr;
	Rectangle * rptr2 = new Rectangle[2]{Rectangle(5,7),Rectangle()}; 
	// Above is possible in c++ ver 11 and onward use
	// g++ <filename> -std=c++11 to compile
	rptr = new Rectangle(4,5);
	cout <<  "Area = " << r1.area() << endl;
	cout <<  "Area = " << r2.area() << endl;
	cout <<  "Area = " << rptr->area() << endl;
	cout << "Area 1 = " << rptr[0].area() << "Area 2 = " << rptr[1].area(); ; 
 	delete rptr;
	return 0;
}

