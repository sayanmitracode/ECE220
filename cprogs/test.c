#include <stdio.h>


int global_x = 5;
int main()
{
	int local_x = 10;
	printf("global=%d, local=%d\n", global_x, local_x);
	// { 
		local_x = 15;
		global_x = 20; 
		// }
	printf("global=%d, local=%d\n", global_x, local_x);
	return 0;
}
