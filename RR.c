// Round Robin Scheduling Algorithm Implementation in C

#include <stdio.h>

int main() {
    int n, i, time_quantum, total = 0, x, counter = 0;
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    x = n; // Copy of number of processes

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i]; // Store burst time in temp array
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\nProcess\t\tBurst Time\tTurnaround Time\tWaiting Time\n");

    int time = 0;
    for(i = 0; x != 0;) {
        if(temp[i] > 0 && temp[i] <= time_quantum) {
            time += temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0) {
            temp[i] -= time_quantum;
            time += time_quantum;
        }

        if(temp[i] == 0 && counter == 1) {
            x--; // Reduce the number of processes left
            printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], time - arrival_time[i], (time - arrival_time[i] - burst_time[i]));
            wait_time += time - arrival_time[i] - burst_time[i];
            turnaround_time += time - arrival_time[i];
            counter = 0;
        }

        if(i == n-1)
            i = 0;
        else if(arrival_time[i+1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %.2f", (float)wait_time / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)turnaround_time / n);

    return 0;
}
