#include <stdio.h>

typedef struct twodvecStruct{
	double x, y;
}twodvec;

twodvec add(twodvec a, twodvec b){
	twodvec temp = {a.x+b.x, a.y+b.y};
	return temp;
}

void show(twodvec a){printf ("\n %lf %lf", a.x,a.y);}

int main()
{
	twodvec xbasis = {1,0};
	twodvec ybasis = {0,1};
	twodvec res = add(xbasis, ybasis);
	show(res);
	return 0;
}