#include<stdio.h>
int main()
{
    int n,i;
    int bt[10],s[10];
    float ct[10],tb=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Process P%d\n",i+1);
        printf("enter burts time:");
        scanf("%d",&bt[i]);
        printf("enter cpu share in %% :");
        scanf("%d",&s[i]);
        tb+=bt[i];

    }
    printf("proportional Sharing");
    printf("process \t burst time \t cpu share \t allocated cpu time \n");
    for(i=0;i<n;i++)
    {
        ct[i]=(s[i]/100.0)*tb;
        printf("P%d\t%d\t%d\t%d",i+1,bt[i],s[i],ct[i]);

    }
    return 0;
}
