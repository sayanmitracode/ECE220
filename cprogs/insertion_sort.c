#include <stdio.h>
#define SIZE 5
int main(){
  int array[] = {7,4,6,3,1};
  //sort array in ascending order
  int i, j, item, empty = 0;
  for(i=1;i<SIZE;i++){
    item = array[i];
    for(j=i-1;j>=0;j--){
      if(item < array[j]){
	//shift array[j] to right; place for item possibly j
	array[j+1] = array[j];
	//update empty position
	empty = j;
      }
    }
    //insert item at the proper location
    array[empty] = item;
  }
  printf("sorted array: \n");
  for(i=0;i<SIZE;i++){
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
