#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;
void push(int num);
bool isEmpty();
int pop();
node *head;
bool newTasks = true;
int main()
{
    int num,value,task=1;
    printf("to add a new task press 1, to end a task press 2, To stop accepting tasks press 3\n");
    scanf("%d",&num);
    while(newTasks || !isEmpty())
    {
        switch (num)
        {
            case 1:
                if(!newTasks)
                    printf("sorry, we are not accepting any more tasks for today\n");
                else
                    printf("task %d were added to the stack\n",task);
                    push(task++);
                break;
            case 2:
                value = pop();
                if(value!= -1)
                    printf("Free CPU time - Task %d in action\n",value);
                else
                    printf("the stack is empty\n");
                break;
            case 3:
                newTasks = false;
                printf("New tasks will not be accepted from now on\n");
                break;
            default:
                break;
        }
    printf("to add a new task press 1, to end a task press 2, To stop accepting tasks press 3\n");
    scanf("%d",&num);
    }
    printf("---------all tasks were done---------\n");
	return 0;
}

bool isEmpty()
{
    if(head==NULL)
        return true;
    else
        return false;
}
int pop()
{
    if(!isEmpty(head))
    {
        int ans = head->data;
        node* temp = head;
        head = head->next;
        free(temp);
        return ans;
    }
    return -1;
    
}
void push(int value)
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
		printf("Error: out of memory, allocation failed!\n");
        return;
    }
    temp->data  = value;
    temp->next = head;
    head= temp;
}









