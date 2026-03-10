#include<stdio.h>

int main()
{
    int n,i,time=0,completed=0,small;
    int at[20],bt[20],ct[20],wt[20],tat[20];
    int visited[20]={0};
    float avg_wt=0,avg_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(completed<n)
    {
        small=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && visited[i]==0)
            {
                if(small==-1 || bt[i]<bt[small])
                {
                    small=i;
                }
            }
        }

        if(small!=-1)
        {
            time=time+bt[small];
            ct[small]=time;

            tat[small]=ct[small]-at[small];
            wt[small]=tat[small]-bt[small];

            avg_wt+=wt[small];
            avg_tat+=tat[small];

            visited[small]=1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f",avg_tat/n);

    return 0;
}

