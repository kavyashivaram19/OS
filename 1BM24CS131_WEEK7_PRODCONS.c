#include<stdio.h>
#define size 5
int buffer[size];
int in=0,out=-1,empty=size,full=0;
int mutex=1;
int wait(int s)
{
    while(s<=0);
    return --s;
}
int signal(int s)
{
    return ++s;
}
void producer()
{
    int item;
    printf("enter the item no:");
    scanf("%d",&item);
    empty=wait(empty);
    mutex=wait(mutex);
    buffer[in]=item;
    printf("Producer added item %d",item);
    in=(in+1)%size;
    mutex=signal(mutex);
    full=signal(full);
}
void consumer()
{
    int item;
    if(out==-1)
        printf("Buffer is empty");
    else{
        full=wait(full);
        mutex=wait(mutex);
        out++;
        item=buffer[out];
        if(item>0)
            printf("Consumer removed item %d",item);
        else
            printf("Buffer is empty");
        out=(out+1)%size;
        mutex=signal(mutex);
        empty=signal(empty);
    }

}
int main()
{
    int choice;
    printf("\n1.Producer\n2.Consumer\n3.exit\n");
    while(1)
    {
        printf("\nenter the choice:");
        scanf("%d",&choice);
        if(choice==1)
            producer();
        else if(choice==2){
                consumer();
        }
        else{
            break;
        }
    }
}
