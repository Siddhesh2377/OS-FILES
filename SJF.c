// SJF Scheduling Algorithm Implementation in C (Non-Preemptive)

#include <stdio.h>

int main() {
    int n, i, j;
    int burst_time[20], process[20], waiting_time[20], turnaround_time[20], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        process[i] = i+1; // Process IDs
    }

    // Sort the processes based on burst time (Ascending order)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    waiting_time[0] = 0; // First process has 0 waiting time

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
