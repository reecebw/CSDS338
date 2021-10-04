#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>
#define MAX_LINE 80
#define MAX_OPTS 20
char *myopts[MAX_OPTS];
void *concurrent(void *test){
  char *wordstring;
  char *str = (char *)test;
  int ac;
  ac = 0;
  wordstring = strtok(str," "); // might overflow
  while (wordstring != NULL) {
    printf("\tstoring token (%s)",wordstring);
    myopts[ac] = malloc(MAX_LINE*sizeof(char));
    strcpy(myopts[ac],wordstring);
    printf(" = (%s)\n", myopts[ac]);
    ac++;
    wordstring = strtok(NULL," ");
  }
  myopts[ac] = NULL; // last wordstring was NULL, so store it for execvp
  printf(" --> done \n");
  fflush(stdout);
  pid_t pid;
  pid = fork();
  if(pid == 0){
    execvp(myopts[0],myopts);
    //free(myopts)
  }
  else{
    wait(NULL);
  }
}
int main()
{
  //char *myopts[MAX_OPTS];
  //char *myopts2[MAX_OPTS];
  char tempstring[MAX_LINE];
  char tempstring2[MAX_LINE];	
  char newlinestring[MAX_LINE];
  int should_run = 1;
  printf("%d\n",sizeof(char));//return 0;
  while (should_run) {
    printf("osh1> ");
    scanf("%[^\n]",tempstring); // might overflow
    fgets(newlinestring,MAX_LINE,stdin);
    printf("osh2> ");
    scanf("%[^\n]",tempstring2);
    fgets(newlinestring,MAX_LINE,stdin); // clear the stdin newline
    printf("\treceived (%s)\n", tempstring);
    printf("\tnow scanning tokens\n");
   
    pthread_t thread_id;
    pthread_t thread_id2;
    pthread_create(&thread_id,NULL,concurrent,(void *)tempstring);
    pthread_create(&thread_id2,NULL,concurrent,(void *)tempstring2);
    pthread_join(thread_id,NULL);
    pthread_join(thread_id2,NULL);    
  }
  
}

