#include<stdio.h>
#define n 5
int fork[n]={1,1,1,1,1};
void take_fork(int i)
{
    if(fork[i]==1&&fork[(i+1)%n]==1)
    {
        fork[i]=0;
        fork[(i+1)%n]=0;
        printf("philo %d is eating\n",i);
    }
    else{
        printf("philo %d is waiting\n",i);
    }
}
void drop_fork(int i)
{
    if(fork[i]==0&&fork[(i+1)%n]==0)
    {
        fork[i]=1;
        fork[(i+1)%n]=1;
        printf("philo %d is  finished eating",i);
    }
}
int main()
{
    int i,choice;
    printf("\namong 5 philosopher\n1.take fork\n2.drop fork\n3.exit");
    while(1)
    {
        printf("\nenter the choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("enter the philo no.:");
            scanf("%d",&i);
            take_fork(i);
        }
        else if(choice==2)
        {
            printf("\nenter the philo no.:");
            scanf("%d",&i);
            drop_fork(i);
        }
        else{
            break;
        }
    }
}
