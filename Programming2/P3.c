#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int* arr1;
	int* arr2;
	arr1 = (int*)calloc(1000,sizeof(int));
	for (int i = 0; i < 1000;i=i+1){
		printf("%d ",arr1[i]);
	}
	free(arr1);
	printf("\n");
	arr2 = (int*)malloc(1000*sizeof(int));
	for (int i = 0;i <1000;i=i+1){
		printf("%d ",arr2[i]);
	}
	free(arr2);
	return 0;
}
