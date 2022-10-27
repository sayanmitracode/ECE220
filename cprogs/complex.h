#include <stdio.h>


typedef struct ComplexStruct{
	double real;
	double img;
} complex;

// typedef struct ComplexStruct complex;

// initialize
complex complexInit(double r, double i);
complex add(complex a, complex b); 
void print(complex c);

// multiply
// magnitude / arg
// print / show

int main(){
	complex a, b, c, d;
	complex CA[10];
	complex * c_ptr; 
	c_ptr = CA;
	a = complexInit(7.00,5.90);
	b = complexInit(7.00,-5.90);
	c = add(a,b);
	d = multiply(a,b);
	print(c);
	print(d);

	return 0;
}

complex add(complex a, complex b){
	complex c;
	c.real = a.real + b.real;
	c.img = a.img + b.img;
	return c;
}

complex multiply(complex a, complex b){
	complex c;
	c.real = a.real*b.real - a.img*b.img;
	c.img = a.real*b.img + a.img*b.real;
	return c;
}

void print(complex c)
{
	printf("\n %lf + j%lf",c.real,c.img);
	return;
}

complex complexInit(double r, double i)
{
	complex c;
	c.real = r;
	c.img = i;
	return c;
}
