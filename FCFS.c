// FCFS Scheduling Algorithm Implementation in C

#include <stdio.h>

int main() {
    int n, i;
    int burst_time[20], waiting_time[20], turnaround_time[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    waiting_time[0] = 0; // First process has 0 waiting time

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
