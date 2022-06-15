#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;
void createQueue(int *queue);
void printNode();
void push(int num);
int Remove();
bool isEmpty();
int peek();
node* head;
node* END;
int top = 0;
int main()
{
    head = NULL, END = NULL;
    int queue[10];
    for(int i=0;i<10;i++)
        queue[i] = i+1;
    for(int i=0;i<10;i++)
        createQueue(queue);
    printNode();

	return 0;
}
void createQueue(int *queue)
{
    if(top<N)
    {
        push(queue[top++]);
        return;
    }
    printf("the queue is empty\n");
}
void push(int num)
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
    	printf("Error: out of memory, allocation failed!\n");
        return;
    }
    if(isEmpty())
    {
        temp->data  = num;
        temp->next = head;
        head= temp;
        END = head;
        return;
    }
    temp->data = num;
    temp->next = NULL;
    END->next = temp;
    END = temp;
    return;
}
int peek()
{
    if(!isEmpty())
        return head->data;
    return -1;
}

int Remove()
{
    if(!isEmpty())
    {
        node* temp = (node*) malloc(sizeof(node));
        if (temp == NULL) 
        {
    	printf("Error: out of memory, allocation failed!\n");
        return -1;
        }
        int val = head->data;
        temp = head;
        head = head->next;
        free(temp);
        return val;
    }
    printf("the queue is empty\n");
    return -1;
}
bool isEmpty()
{
    if(head==NULL)
        return true;
    return false;
}

void printNode( )
{
    node* curr = head;	
	while (curr!=NULL)
	{
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}






