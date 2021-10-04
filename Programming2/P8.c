#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 20
int main(){
	char *str1;
	char *str2;
	char array[MAX_STR];
	printf("Enter first word.\n");
	scanf("%s", array);
	str1 = (char*)malloc(strlen(array)*sizeof(char));
	strcpy(str1,array);
	printf("Enter second word.\n");
	scanf("%s",array);
	str2 = (char*)malloc(strlen(array)*sizeof(char));
	strcpy(str2,array);
	int i = 0;
	char temp;
	while(i<strlen(str1) && i<strlen(str2)){
		temp = str1[i];
		str1[i]=str2[i];
		str2[i]=temp;
		i = i+1;
	}
	printf("after flipping characters the resulting strings are %s and %s\n",str1,str2);
	return 0;

} 

