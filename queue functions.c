#include <stdio.h>
#include <stdbool.h>
#define N 6 // for 5 places
int START = 0;
int END = 0;
bool isEmpty();
bool insert(int num);
int Remove();
int peek();
bool isFull();
int tor[N];
int main()
{
    int num,value;
    printf("to insert value press 1, to Remove value press 2. to exit press -1\n");
    scanf("%d",&num);
    while(num!=-1)
    {
        switch (num)
        {
            case 1:
                printf("please enter a number\n");
                scanf("%d",&value);
                if(!insert(value))
                    printf("the queue is full\n");
                break;
            case 2:
                value = Remove();
                if(value!= -1)
                    printf("the removed number: %d\n",value);
                else
                    printf("the queue is empty\n");
                break;
            default:
                break;
        }
    printf("to insert value press 1, to Remove value press 2, to exit press -1\n");
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
        tor[END] = num;
        END = (END+1)%N;
        return true;
    }
    return false;
}

int Remove()
{
    if(!isEmpty())
    {
        int val = tor[START];
        START = (START+1)%N;
        return val;
    }
    return -1;
}

int peek()
{
    if(!isEmpty())
        return tor[START];
}

bool isFull()
{
    if((END+1)%N == START) // full
        return true;
    return false;
}


