#include <stdio.h>

int main()
{
    int n,i,time=0,pos,min;
    int at[10],bt[10],rt[10];
    int ct[10],tat[10],wt[10];
    int completed[10]={0},done=0;
    float avgtat=0,avgwt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(done < n)
    {
        pos = -1;
        min = 9999;

        for(i=0;i<n;i++)
        {
            if(at[i] <= time && completed[i]==0)
            {
                if(rt[i] < min)
                {
                    min = rt[i];
                    pos = i;
                }
            }
        }

        if(pos == -1)
        {
            time++;
        }
        else
        {
            rt[pos]--;
            time++;

            if(rt[pos] == 0)
            {
                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];
                avgtat+=tat[pos];
                avgwt+=wt[pos];

                completed[pos] = 1;
                done++;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("avgtat:%f,avgwt:%f",avgtat/n,avgwt/n);

    return 0;
}
