#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *ptr2 = calloc(100, sizeof(char));
	if(ptr2 == NULL){
		printf("ERROR – calloc failure!");
		return 1;
	}
	strncpy(ptr2, "Example using calloc", 100);
	printf("\n %s", ptr2);

	char * ptr3 = realloc(ptr2, 200*sizeof(char));
	if(ptr3 == NULL){
		printf("ERROR – realloc failure!");
	return 1;
	}
	strncpy(ptr3, "New text", 100);
	printf("\n %s", ptr3);

	free(ptr3); 
//	free(ptr2); 

}