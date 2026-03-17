#include<stdio.h>
int main()
{
    int n,i,done=0,time=0,min,pos,completed[10]={0};
    printf("enter the no.of process:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],pr[n],tat[n],wt[n],rbt[n];
    float avg_tat=0,avg_wt=0;
    for(i=0;i<n;i++)
    {
        printf("\nenter the at, bt and priority of P%d:",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        rbt[i]=bt[i];
    }
    while(done<n)
    {
        min=9999;
        pos=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&completed[i]==0)
            {
                if(pr[i]<min)
                {
                    min=pr[i];
                    pos=i;
                }
            }
        }
        if(pos==-1)
            time++;
        else{
            rbt[pos]--;
            time++;
            if(rbt[pos]==0)
            {
                ct[pos]=time;
                tat[pos]=ct[pos]-at[pos];
                wt[pos]=tat[pos]-bt[pos];
                avg_tat+=tat[pos];
                avg_wt+=wt[pos];
                completed[pos]=1;
                done++;
            }
        }
    }
    printf("\nPeocess\tAT\tBT\tPRIOR\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
    printf("\navg_tat:%f",avg_tat/n);
    printf("\navg_wt:%f",avg_wt/n);
}
