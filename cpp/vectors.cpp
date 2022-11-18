#include<iostream>
using namespace std;
class twodvec {
public:	
	twodvec(double _x, double _y){x = _x; y = _y;howmany++;}
	twodvec operator+(twodvec b){ twodvec tmp(x+b.x, y+b.y); return tmp;	}
	double operator[](int z) const {if (!z) return x; if (z==1) return y; return 0;}
	void show() { cout << x << " " << y << endl;
		cout << "we have made " << howmany << " twodvecs";}
private:
 double x,y;	
 static int howmany;
};

int twodvec::howmany;

class Rectangle{
	int width, hegiht;
public:
	Rectangle() {width = hegiht =0;}
	Rectangle(int, int);
	int area() const {return hegiht*width;}

};

Rectangle::Rectangle(int w, int h){
	width = w; hegiht =h;
}

int main() {
	twodvec xbasis(1,0);
	twodvec ybasis(0,1);
	twodvec tmp = xbasis + ybasis;
	tmp.show();
	cout << xbasis[0] << " " << xbasis[1] << endl;

	Rectangle a(3,4);
	Rectangle b;
	Rectangle *rptr1, *rptr2;
	rptr1 = &a;
	rptr2 = new Rectangle(5,6);
	cout << a.area() << endl;
	cout << b.area() << endl;
	cout << rptr2->area() << endl;
	cout << rptr1->area() << endl;
	delete rptr2;
	return 0;
}





