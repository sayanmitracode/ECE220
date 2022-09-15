// Compute area of a circle
#include <stdio.h>
#define PI 3.141  // preprocessor directive
 static int x, y;
int foo();

int main(){
  float r = 7.3;
  float area;
  area = PI*r*r;
  printf("\n area of circle with radius %0.3f is %0.3f \n", r, area); // %d %x %s
  r = foo();
  return 0;
}

int foo()
{
  float r;
  r = 7.0;
  return 5.60;
}






