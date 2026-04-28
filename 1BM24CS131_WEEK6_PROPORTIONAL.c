#include<stdio.h>
int main()
{
    int i,n,t,time;
    int w[10],exce[10];

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter the weight of each process:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        exce[i]=0;
    }

    printf("Enter the simulation time: ");
    scanf("%d",&time);

    printf("\nTime\tProcess\n");

    for(t = 0;t<time;t++)
    {
        int task = -1;
        float minratio = 9999.0;
        for(i = 0; i < n; i++)
        {
            float ratio=(float)exce[i] / w[i];
            if(ratio<minratio)
            {
                minratio=ratio;
                task=i;
            }
        }
        printf("%d\tP%d\n",t,task + 1);
        exce[task]++;
    }
}
