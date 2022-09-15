#include <stdio.h>


int main()
{
  int x,y,z; 
  x = 5;
  y = x*x;
  x++;
  printf("x = %d y = %d y = %x \n", x, y, y);
  y = y<<2;
  printf("x = %d y = %d y = %x \n", x, y, y);
  z = x|y;
  printf("z = %d z = %x \n", z, z);
  return 0;

}
