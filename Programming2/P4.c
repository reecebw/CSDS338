#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int* arr;
	
	arr=(int*)malloc(100000000*sizeof(int));
	clock_t begin = clock();
	for (int i = 0;i<100000000;i = i+1){
		arr[i] = 1;
	}
	clock_t end = clock();
	double time_spent =(double)(end - begin)/CLOCKS_PER_SEC;
	printf("%f seconds\n",time_spent);
	begin = clock();
	for (int i = 0;i<100000000;i=i+1){
		arr[i] = 2;
	}
	end = clock();
	time_spent =(double)(end - begin)/CLOCKS_PER_SEC;
	printf("%f seconds\n",time_spent);
	return 0;
}
