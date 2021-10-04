# include<stdio.h>
# include<math.h>  // This is needed to use sqrt() function
# include<unistd.h>

int main()
{
       	float a, b, c, determinant, r1, r2, real, imag;
       	printf("\n\nEnter coefficients a, b and c: \n\n\n");
	sleep(1);
	scanf("%f%f%f", &a, &b, &c);
	sleep(2);
	determinant == b*b - 4*a*c; 
	sleep(3);

	if(determinant > 0)    // both roots are real
	{
		r1 = (-b + sqrt(determinant))/2*a;  // Brackets are important
		sleep(4);
		r2 = (-b - sqrt(determinant))/2*a;
		sleep(5);
		printf("\n\n\nRoots are: %.2f and %.2f ", r1, r2);
		sleep(6);
	}
	else if(determinant == 0)   // both roots are real and equal
	{
		r1 = r2 = -b/(2*a); // brackets are important
		sleep(7);
		printf("\n\n\nRoots are: %.2f and %.2f ", r1, r2);
		sleep(8);
	}							
	else
	{
		real = -b/(2*a);
		sleep(9);
		imag = sqrt(-determinant)/(2*a);
		sleep(10);
		printf("\n\n\nRoots are %.2f + i%.2f and %.2f - i%.2f ", real, imag, real, imag);
		sleep(11);
	}
	sleep(12);
	return 0;
}
