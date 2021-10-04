#include <stdio.h>

int main () {
	int i = 5;
	int *j = &i;
	int **k = &j;

	printf("i: %d, address of i %d, address of the address of i %d\n",**k,*k,k);
	return 0;

}
