#include <stdio.h>
#include <stdbool.h>
#define N 11 // for 10 places
int START = 0;
int END = 0;
bool workDay = true;
bool isEmpty();
bool insert(int num);
int Remove();
int peek();
bool isFull();
int queue[N];
int main()
{
    int num,value,customers=0;
    printf("to get in line  press 1, to get service press 2, to end a work day press 3, to exit press -1\n");
    scanf("%d",&num);
    while(num!=-1)
    {
        switch (num)
        {
            case 1:
                if(!workDay)
                    printf("sorry, we are not accepting any more customers for today\n");
                else
                {
                    printf("please enter your id\n");
                    scanf("%d",&value);
                    if(!insert(value))
                        printf("the queue is full, try to come back later\n");
                    else
                        printf("customer %d is entered the queue, there are %d people in front of you in line\n",value,(customers++));
                }
                break;
            case 2:
                value = Remove();
                if(value!= -1)
                    printf("customer %d is receiving service, there are %d people in line\n",value,(--customers));
                else
                    printf("the queue is empty\n");
                break;
            case 3:
                workDay = false;
                printf("work day is ended\n");
                break;
            default:
                break;
        }
    printf("to get in line  press 1, to get service press 2, to end a work day press 3, to exit press -1\n");
    scanf("%d",&num);
    }
    while(!isEmpty())
        Remove();
    return 0;
}

bool isEmpty()
{
    if(START == END)
        return true;
    else
        return false;
}

bool insert(int num)
{
    if(!isFull())
    {
        queue[END] = num;
        END = (END+1)%N;
        return true;
    }
    return false;
}

int Remove()
{
    if(!isEmpty())
    {
        int val = queue[START];
        START = (START+1)%N;
        return val;
    }
    return -1;
}

int peek()
{
    if(!isEmpty())
        return queue[START];
}

bool isFull()
{
    if((END+1)%N == START) // full
        return true;
    return false;
}


