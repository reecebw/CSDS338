#include <unistd.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
int current_process_priority;
int current_process_queue;
int attempts;
// insert an item at the appropriate position of the
// queue so that the queue is always ordered
void enqueue(int item,int queue[],int n) {
        // Check if the queue is full
        if (n == MAX_SIZE - 1) {
                printf("%s\n", "ERROR: Queue is full");
                return;
        }

        int i = n - 1;
        while (i >= 0 && item > queue[i]) {
                queue[i + 1] = queue[i];
                i--;
        }
        queue[i + 1] = item;
}

// remove the last element in the queue
int dequeue(int queue[],int n) {
        int item;
        // Check if the queue is empty
        if (n == 0) {
                printf("%s\n", "ERROR: Queue is empty");
                return -999999;
        }
        item = queue[n - 1];
        return item;
}
int main(){
	int PQ1[100][2];
	int capacity1 = 0;
	int PQ2[100][2];
	int capacity2 = 0;
	int complexity = 0;
	int random;
	int priority;
	srand(time(NULL));
	while(TRUE){
		//Simulate new processes arriveing in Queue
		random = rand() % 10;
		priority = (rand() % 256) +1;
		if (random==0 && capacity1 <= MAX_SIZE){
			enqueue(priority,PQ1,capacity1);
			capacity1 ++;
			printf("Process with priority %d added to Priority Queue 1.\n",priority);
		}
		else if (random==1 && capacity2 <= MAX_SIZE){
			enqueue(priority,PQ2,capacity2);
			capacity2 ++;
			printf("Process with priority %d added to Priority Queue 2.\n",priority);
		}
		//Choose new process to begin processing or attempt to finish current process
		if((capacity1!=0 || capacity2!=0) && complexity == 0){
			if (capacity2 == 0){
				current_process_priority = dequeue(PQ1,capacity1);
				current_process_queue = 1;
				capacity1 --;
			}else if(capacity1 == 0){
				current_process_priority = dequeue(PQ2,capacity2);
				current_process_queue = 2;
				capacity2 --;
			}else if(PQ1[capacity1-1]<=PQ2[capacity2-1]){
				current_process_priority = dequeue(PQ1,capacity1);
				current_process_queue = 1;
				capacity1 --;
			}else{
				current_process_priority = dequeue(PQ2,capacity2);
				current_process_queue = 2;
				capacity2 --;
			}
			complexity = (rand() % 20) + 1;
			printf("Process with priority %d and complexity %d has been dequeued from queue %d and is currently running.\n",current_process_priority,complexity,current_process_queue);
		}
		else if (complexity != 0) {
			random = rand() % (complexity+1);
			if(random == 0){
				printf("Process with priority %d and complexity %d has finished running.\n",current_process_priority,complexity);
				complexity = 0;
				attempts  = 0;
			}else if(attempts<complexity/2){
				printf("Process with priority %d and complexity %d is currently running.\n",current_process_priority,complexity);
				attempts ++;
			}else{
				printf("Process with priority %d and complexity %d has reached time slice expiration and is being requeued.\n",current_process_priority,complexity);
				complexity = 0;
				attempts  = 0;
				if(current_process_queue==1 && capacity1 <= MAX_SIZE){
					enqueue(current_process_priority,PQ1,capacity1);
					capacity1 ++;
				}else if(capacity2 <=MAX_SIZE){
					enqueue(current_process_priority,PQ2,capacity2);
					capacity2 ++;
				}
			}
		}
		sleep(1);
	}



}
