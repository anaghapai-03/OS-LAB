#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt;  // remaining time
    }

    int completed = 0, current_time = 0;
    float totalwt = 0, totaltat = 0;

    while(completed < n) {
        int index = -1;
        int minrt = 9999;

        for(i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].rt > 0) {
                if(p[i].rt < minrt) {
                    minrt = p[i].rt;
                    index = i;
                }
            }
        }

        if(index == -1) {
            current_time++;
        }
        else {
            p[index].rt--;   // execute for 1 unit
            current_time++;

            if(p[index].rt == 0) {
                p[index].ct = current_time;

                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;

                totalwt += p[index].wt;
                totaltat += p[index].tat;

                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", totalwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", totaltat / n);

    return 0;
}
