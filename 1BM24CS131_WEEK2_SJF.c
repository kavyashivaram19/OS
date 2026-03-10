#include<stdio.h>
int main()
{
    int i,j,temp;
    int n;
    printf("enter the no.of process:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],p[n];
    for(i=0;i<n;i++)
    {
        printf("\nenter the at and bt of p%d:",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        p[i]=i+1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
    }
    float tat_avg=0,wait_avg=0;
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        tat_avg+=tat[i];
        wait_avg+=wt[i];
    }
    printf("process\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\naverage turn around time:%f",tat_avg/n);
    printf("\naverage wait time :%f",wait_avg/n);
}
