#include <stdio.h>

typedef struct Proc{
	int id, arrival, burst, completion, waiting, turnaround, remaining;
}Proc ;

int main(){
	printf("\nNumber of Processes: ");
	int n;
	scanf("%d", &n); Proc p[n]; int tq = 3;int completed = 0;, current_time = 0;
	printf("\nEnter Details of %d proccess:\n", n);
	for(int i = 0; i < n;i++){
		printf("\nProccess %d:\n", i+1);
		printf("\tID: "); scanf("%d", &(p[i].id));
		printf("\tArrival: "); scanf("%d", &(p[i].arrival) );
		printf("\tBurst: "); scanf("%d", &(p[i].burst) );
		p[i].remaining = p[i].burst;
		printf("\tPriority: "); scanf("%d", &(p[i].priority) );
		printf("Proccess %d Registered.\n", i+1);
	}
	Proc small; int pos;
	for(int i = 0; i< n-1;i++){
		small = p[i];pos = i;
		for(int j = i+1; j < n;j++){
			if(small.arrival > p[j].arrival){
				small = p[j];pos = j;
			}
		}
		p[pos] = p[i];
		p[i] = small;
	}

	while(completed < n){
		for(int i = 0;i < n;i++){
			if(p[i].arrival <= current_time && p[i].remaining > 0){
				if(p[i].remaining > 3){
					p[i].remaining = p[i].remaining - 3;
					current_time += 3;
				}else{
					current_time += p[i].remaining;
					p[i].remaining = 0;
					completed++;
				}
			}
		}
	}


        return 0;
}
