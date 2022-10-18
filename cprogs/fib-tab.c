#include <stdio.h>

long table[100];
long fib(long n);
int main(){
	
	long i;
	for (i=0;i<100;i++)
		table[i] = -1;

	for (i=30;i<70;i++)
		printf (" \n Fib %ld = %ld", i, fib(i));

	return 0;
}

long fib(long n)
{	
	int fn;
	if (table[n] != -1) return table[n];
	else{
		if (n==0) return 0;
		else if (n==1) return (1);
		else{
			fn = fib(n-1) + fib(n-2);
			table[n] = fn; 
			return(fn);			
		} 
	}
}








