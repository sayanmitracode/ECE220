#include <iostream>

using namespace std;

class twodvec{
public:
	twodvec(double _x, double _y){x = _x; y= _y;howmany++;}
	twodvec(){x = 0; y =0;howmany++;}
	twodvec operator +(twodvec b){twodvec temp; temp.x = x + b.x; temp.y = y + b.y; return temp;}
	double operator [](int z){if (z==0) return x; if (z==1) return y; retun 0;}
	void show(){cout << x << " " << y << endl; cout << "We have " << howmany << " instances of twodvec" << endl;}
	double get_x(){return x;}
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
	res.show();
}