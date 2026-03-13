#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
};
int main()
{
    int n,i;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    struct Process p[n];
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter Arrival Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].completed=0;

    }
    int c_t=0;
    int comple=0;
    float totalwt=0,totaltat=0;
    while(comple<n)
    {
        int index=-1;
        int minbt=9999;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=c_t && p[i].completed==0)
            {
                if(p[i].bt<minbt)
                {
                    minbt=p[i].bt;
                    index=i;
                }
            }
        }
        if(index==-1)
        {
            c_t++;

        }
        else{
            p[index].ct = c_t + p[index].bt;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            c_t=p[index].ct;
            p[index].completed = 1;
            comple++;
            totalwt+=p[index].wt;
            totaltat+=p[index].tat;

        }

    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
     printf("\nAverage Waiting Time = %.2f", totalwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", totaltat/ n);

    return 0;


}
