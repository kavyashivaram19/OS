#include<stdio.h>

int main()
{
    int n,i,time=0,tq,done=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter time quantum: ");
    scanf("%d",&tq);

    int at[n],bt[n],ct[n],tat[n],wt[n],rbt[n];
    int queue[100],front=0,rear=0,visited[10]={0};

    float avg_tat=0,avg_wt=0;

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rbt[i]=bt[i];
    }

    // push first process
    queue[rear++] = 0;
    visited[0] = 1;

    while(front < rear)
    {
        int p = queue[front++];

        if(rbt[p] > tq)
        {
            time += tq;
            rbt[p] -= tq;
        }
        else
        {
            time += rbt[p];
            rbt[p] = 0;

            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            avg_tat += tat[p];
            avg_wt += wt[p];

            done++;
        }

        // add newly arrived processes
        for(i=0;i<n;i++)
        {
            if(at[i] <= time && visited[i]==0)
            {
                queue[rear++] = i;
                visited[i]=1;
            }
        }

        // if not finished, add back
        if(rbt[p] > 0)
            queue[rear++] = p;
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT = %.2f", avg_wt/n);

    return 0;
}
