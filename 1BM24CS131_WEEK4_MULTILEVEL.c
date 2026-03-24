#include<stdio.h>
int main()
{
    int n,i,j,time=0;
    printf("enter the no.of process:");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],type[n];
    int sys[n],sc=0,user[n],us=0;
    printf("TYPE: system=0 user=1");
    for(i=0;i<n;i++)
    {
        printf("\nenter pid,at,bt,type of P%d:",i+1);
        scanf("%d %d %d %d",&pid[i],&at[i],&bt[i],&type[i]);
    }
    for(i=0;i<n;i++)
    {
        if(type[i]==0)
        {
            sys[sc]=i;
            sc++;
        }
        else{
            user[us]=i;
            us++;
        }
    }
    for(i=0;i<sc-1;i++)
    {
        for(j=0;j<sc-i-1;j++)
        {
            if(at[sys[j]]>at[sys[j+1]])
            {
                int temp=sys[j];
                sys[j]=sys[j+1];
                sys[j+1]=temp;
            }
        }
    }
    for(i=0;i<us-1;i++)
    {
        for(j=0;j<us-i-1;j++)
        {
            if(at[user[j]]>at[user[j+1]])
            {
                int temp=user[j];
                user[j]=user[j+1];
                user[j+1]=temp;
            }
        }
    }
    for(i=0;i<sc;i++)
    {
        int p=sys[i];
        if(time<at[p])
            time=at[p];
        time+=bt[p];
        ct[p]=time;
        tat[p]=ct[p]-at[p];
        wt[p]=tat[p]-bt[p];
    }
    for(i=0;i<us;i++)
    {
        int p=user[i];
        if(time<at[p])
            time=at[p];
        time+=bt[p];
        ct[p]=time;
        tat[p]=ct[p]-at[p];
        wt[p]=tat[p]-bt[p];
    }
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],type[i],ct[i],tat[i],wt[i]);
    }
}
