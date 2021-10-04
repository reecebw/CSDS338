#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#define MAX_LINE 80
#define MAX_OPTS 20
int main()
{
  char *myopts[MAX_OPTS];
  char *myopts2[MAX_OPTS];
  char tempstring[MAX_LINE];
  char tempstring2[MAX_LINE];	
  char *wordstring;
  char newlinestring[MAX_LINE];
  int should_run = 1;
  int ac;
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

    ac = 0;
    wordstring = strtok(tempstring," "); // might overflow
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
    
    ac = 0;
    wordstring = strtok(tempstring2," "); // might overflow
    while (wordstring != NULL) {
      printf("\tstoring token (%s)",wordstring);
      myopts2[ac] = malloc(MAX_LINE*sizeof(char));
      strcpy(myopts2[ac],wordstring);
      printf(" = (%s)\n", myopts2[ac]);
      ac++;
      wordstring = strtok(NULL," ");
    }
    myopts2[ac] = NULL; // last wordstring was NULL, so store it for execvp
    printf(" --> done \n");
    fflush(stdout);


    pid_t pid;
    pid = fork();

    if (pid == 0) {
      pid_t pid2;
      pid2 = fork();
      // should_run = 0;
      if (pid2 == 0){
        fflush(stdout);
        execvp(myopts2[0],myopts2);
      }
      else {
        printf("CHILD working on %s and %s\n", myopts[0],myopts2[0]);
        fflush(stdout);
        execvp(myopts[0], myopts);
      }
      // return 1;

    } else {
      should_run = 1;
      printf("PARENT finishing\n");
      wait(NULL); 
    }
  }
}

