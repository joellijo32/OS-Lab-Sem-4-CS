#include <stdio.h>
#include "scheduler.h"

void run_fcfs(Process p[], int n, double *avg_wait, double *avg_tat) {

    Process temp[n];
    for(int i=0;i<n;i++) temp[i] = p[i];

    // sort by arrival
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(temp[j].arrival < temp[i].arrival){
                Process t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    int time = 0;
    int wait_sum=0, tat_sum=0;

    int gantt[1000];
    int gpos = 0;
    int prev = -1;

    printf("\n\n===== FCFS =====\n");
    printf("ID\tAT\tBT\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++){
        if(time < temp[i].arrival)
            time = temp[i].arrival;

        // Gantt tracking
        if(prev != temp[i].id){
            gantt[gpos++] = temp[i].id;
            prev = temp[i].id;
        }

        temp[i].completion = time + temp[i].burst;
        temp[i].turnaround = temp[i].completion - temp[i].arrival;
        temp[i].waiting = temp[i].turnaround - temp[i].burst;

        wait_sum += temp[i].waiting;
        tat_sum += temp[i].turnaround;

        time = temp[i].completion;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            temp[i].id,temp[i].arrival,temp[i].burst,
            temp[i].completion,temp[i].waiting,temp[i].turnaround);
    }

    *avg_wait = (double)wait_sum/n;
    *avg_tat = (double)tat_sum/n;

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    for(int i = 0; i < gpos; i++){
        printf("| %d ", gantt[i]);
    }
    printf("|\n");

    printf("\nAverage Waiting Time: %.2lf\n", *avg_wait);
    printf("Average Turn Around Time: %.2lf\n", *avg_tat);
}