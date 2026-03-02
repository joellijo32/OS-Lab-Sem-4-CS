#include <stdio.h>
#include "scheduler.h"

void run_rr(Process p[], int n, int tq, double *avg_wait, double *avg_tat){

    Process temp[n];
    for(int i=0;i<n;i++){
        temp[i]=p[i];
        temp[i].remaining=temp[i].burst;
    }

    int time=0, completed=0;
    int wait_sum=0,tat_sum=0;

    int gantt[1000];
    int gpos = 0;
    int prev = -1;

    printf("\n\n===== Round Robin (TQ=%d) =====\n",tq);
    printf("ID\tAT\tBT\tCT\tWT\tTAT\n");

    while(completed<n){
        int executed=0;

        for(int i=0;i<n;i++){
            if(temp[i].arrival<=time && temp[i].remaining>0){

                executed=1;

                // Gantt tracking
                if(prev != temp[i].id){
                    gantt[gpos++] = temp[i].id;
                    prev = temp[i].id;
                }

                if(temp[i].remaining>tq){
                    time+=tq;
                    temp[i].remaining-=tq;
                } else {
                    time+=temp[i].remaining;
                    temp[i].remaining=0;

                    temp[i].completion=time;
                    temp[i].turnaround=time-temp[i].arrival;
                    temp[i].waiting=temp[i].turnaround-temp[i].burst;

                    wait_sum+=temp[i].waiting;
                    tat_sum+=temp[i].turnaround;

                    completed++;

                    printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                        temp[i].id,temp[i].arrival,temp[i].burst,
                        temp[i].completion,temp[i].waiting,temp[i].turnaround);
                }
            }
        }

        if(!executed)
            time++;
    }

    *avg_wait=(double)wait_sum/n;
    *avg_tat=(double)tat_sum/n;

    
    printf("\nGantt Chart:\n");
    for(int i = 0; i < gpos; i++){
        printf("| %d ", gantt[i]);
    }
    printf("|\n");

    printf("\nAverage Waiting Time: %.2lf\n",*avg_wait);
    printf("Average Turn Around Time: %.2lf\n",*avg_tat);
}