#include<stdio.h>
int main()
{
    int n,i,done=0,time=0,min,pos,completed[10]={0},tq;
    printf("enter the no.of process:");
    scanf("%d",&n);
    printf("enter tq:");
    scanf("%d",&tq);
    int at[n],bt[n],ct[n],pr[n],tat[n],wt[n],rbt[n];
    float avg_tat=0,avg_wt=0;
    for(i=0;i<n;i++)
    {
        printf("\nenter the at, bt of P%d:",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rbt[i]=bt[i];
    }
    while(done<n)
    {
        int e=0;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&completed[i]==0)
            {
                e=1;
                if(rbt[i]>tq)
                {
                    rbt[i]-=tq;
                    time+=tq;
                }
                else{
                    time+=rbt[i];
                    rbt[i]=0;
                    ct[i]=time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    avg_tat+=tat[i];
                    avg_wt+=wt[i];
                    done++;
                }
            }
            if(e==0)
                time++;
        }
    }
    printf("\nPeocess\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\navg_tat:%f",avg_tat/n);
    printf("\navg_wt:%f",avg_wt/n);
}
