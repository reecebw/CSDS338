#include <stdio.h>

int main ()
{
	int i;
	int factorial = 1;
	printf("Int\tSquare\tFactorial\n");
	for (i = 1;i<=10;i++)
	{
		factorial *= i;
		printf("%d\t%d\t%d\n",i,i*i,factorial);
	}
	return 0;
}
