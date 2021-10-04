#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main(){
	FILE *fp;
	char Max_PID[32768];
	fp = popen("ps --no-headers -o pid=","r");
	while (fgets(Max_PID,sizeof(Max_PID),fp) !=NULL){
		kill(atoi(Max_PID),9);
	}
	pclose(fp);
	return 0;
}
