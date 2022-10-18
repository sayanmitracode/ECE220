#include <stdio.h>

int Running(int n);


int main(){
  int number = 5;
  int answer;
  answer = Running(number);
  return 0;
}

int Running(int n){
	int fn;
	if (n==1) {
		fn = 1;
		return fn;
	}
	else {
		fn =  n + Running(n-1);
		return fn;
	}
}