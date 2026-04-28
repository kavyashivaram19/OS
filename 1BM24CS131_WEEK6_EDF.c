#include<stdio.h>
int main()
{
    int i,n,t,time;
    int period[10],exec[10],deadline[10],remaining[10];
    printf("enter the no.of process:");
    scanf("%d",&n);
    printf("enter exec time,period and deadline of the process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&exec[i],&period[i],&deadline[i]);
        remaining[i]=exec[i];
    }
    printf("enter the simulation time:");
    scanf("%d",&time);
    printf("\norder of excecution:");
    for(t=0;t<time;t++)
    {
        int mindeadline=9999;
        int currenttask=-1;
        for(i=0;i<n;i++)
        {
            if(remaining[i]>0&&deadline[i]<mindeadline)
            {
                mindeadline=deadline[i];
                currenttask=i;
            }
        }
        if(currenttask!=-1)
        {
            printf("\n%d\tP%d",t,currenttask+1);
            remaining[currenttask]--;
        }
        else{
            printf("\n%d\tIdle");
        }
        for(i=0;i<n;i++)
        {
            if((t+1)%period[i]==0)
            {
                deadline[i]+=period[i];
                remaining[i]=exec[i];
            }
        }

    }
}
