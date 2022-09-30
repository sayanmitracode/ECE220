#include <stdio.h>
#include <math.h>
int findRoots(float a, float b, float c);

int main(){
    float a, b, c;
    printf("\n Enter the coefficients for ax^2 + bx + c = 0 \n");
    scanf("%f %f %f", &a, &b, &c);
    

    printf("%0.2fx^2 + %0.2fx + %0.2f = 0 has ", a, b, c);
    findRoots(a, b, c);

    return 0;
}

int findRoots(float a, float b, float c)
{
  float d = b*b - (4*a*c);
  if (d == 0)
    {
      printf(" repeated real roots at: %f \n", -b/(2*a));
    }
  else if (d > 0)
    {
      printf(" two real roots at: %f and %f \n", (-b + sqrt(d))/(2*a),  (-b - sqrt(d))/(2*a));
    }
  else
    {
      printf(" two complex roots at: %f + i%f and %f - i%f \n",-b/(2*a),  sqrt(-d)/(2*a),-b/(2*a), sqrt(-d)/(2*a) );
    }
  return 0;
}
