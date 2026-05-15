#include <stdio.h>

struct Process {
    int id;
    int burst;
    int period;
    int remaining;
    int deadline;
    int next_arrival;
};

int main() {
    int n, time, hyper = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // 🔹 Input
    for(int i = 0; i < n; i++) {
        printf("Process %d (Burst, Period): ", i + 1);
        scanf("%d %d", &p[i].burst, &p[i].period);

        p[i].id = i + 1;
        p[i].remaining = 0;
        p[i].next_arrival = 0;
        p[i].deadline = p[i].period;

        if(p[i].period > hyper)
            hyper = p[i].period;
    }

    // 🔹 Process Table
    printf("\nProcess Details:\n");
    printf("PID\tBurst\tPeriod\n");
    printf("------------------------\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\n", p[i].id, p[i].burst, p[i].period);
    }

    // 🔹 Scheduling Output
    printf("\nEDF Scheduling:\n");
    printf("Time\tRunning\n");
    printf("----------------\n");

    // 🔹 Simulation
    for(time = 0; time < hyper * 2; time++) {

        // ✅ Step 1: Release processes
        for(int i = 0; i < n; i++) {
            if(time == p[i].next_arrival) {
                p[i].remaining += p[i].burst;
                p[i].deadline = time + p[i].period;
                p[i].next_arrival += p[i].period;
            }
        }

        // ✅ Step 2: Select earliest deadline
        int earliest = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].remaining > 0) {
                if(earliest == -1 || p[i].deadline < p[earliest].deadline) {
                    earliest = i;
                }
            }
        }

        // ✅ Step 3: Execute
        printf("%d\t", time);

        if(earliest != -1) {
            printf("P%d\n", p[earliest].id);
            p[earliest].remaining--;
        } else {
            printf("Idle\n");
        }
    }

    return 0;
}
