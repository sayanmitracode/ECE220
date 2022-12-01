#include <iostream>

using namespace std;

class twodvec{
public:
	twodvec(double _x, double _y){x = _x; y= _y;howmany++;}
	twodvec(){x = 0; y =0;howmany++;}
	twodvec operator +(twodvec b){twodvec temp; temp.x = x + b.x; temp.y = y + b.y; return temp;}
	twodvec operator -(const twodvec& b){
		double newx = this->x -  b.x; 
		double newy = this->y - b.y; 
		return twodvec(newx,newy);
	}
	double operator [](int z){if (z==0) return x; if (z==1) return y; retun 0;}
	void show(){cout << x << " " << y << endl; cout << "We have " << howmany << " instances of twodvec" << endl;}
	double get_x() const {return x;}
private:
	double x, y;
	static int howmany;
};

int twodvec::howmany;

towdvec::newfunction(){};

int main()
{
	twodvec a(1,0);
	twodvec b(0,1);
	twodvec zero;
	zero.show();
	printf (" %lf ", a.get_x());
	twodvec res = a + b;
	twodvec c(8,9.0);
	cout << a.get_x();
	res = a + c;
	res.show();
}







