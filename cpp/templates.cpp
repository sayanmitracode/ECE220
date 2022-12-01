#include <iostream>

using namespace std;

class twodvec{
public:
	twodvec(double _x, double _y){x = _x; y= _y;howmany++;}
	twodvec(){x = 0; y =0;howmany++;}
	twodvec(twodvec & obj){x = obj.x; y = obj.y;howmany++;}

	twodvec operator +(twodvec b){twodvec temp; temp.x = x + b.x; temp.y = y + b.y; return temp;}
	friend ostream& operator<<(ostream& os, twodvec const & v) {
        return os << v.x << " + i" << v.y ;
    }
	twodvec operator -(const twodvec& b){
		twodvec temp;
		temp.x = this->x -  b.x; 
		temp.y = this->y - b.y; 
		return temp;
	}
	double operator [](int z){if (z==0) return x; if (z==1) return y; return 0;}
	void show(){cout << x << " " << y << endl; cout << "We have " << howmany << " instances of twodvec" << endl;}
	double get_x() const {return x;}
private:
	double x, y;
	static int howmany;
};

int twodvec::howmany;


template <class T>
T sum (T a, T b){
	T temp;
	temp = a + b;
	return temp;
}

int main()
{
	twodvec a(1,1);
	twodvec b(2,2);

	cout << sum(4,5) << endl;
	cout << sum(4.51, 5.09) << endl;
	cout << sum(a,b); 


}