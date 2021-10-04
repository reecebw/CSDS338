#include <stdio.h>
#include <unistd.h>
#define MAX_STR 20
int  main(){
	char third_word[MAX_STR];
	printf("Please enter a series of words and I will return the third one.\n");
	scanf("%*s%*s%s",third_word);
	printf("the third word was %s.\n",third_word);
	return 0;
}
