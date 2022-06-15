#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;

void printNode(node* head);
void freeList(node* head);
void push(node** head, int num);
bool isEmpty(node* head);
int peek(node* head);
int pop(node** head);
int main()
{
    int number = 0;
    node *head = NULL;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0) 
	{
		push(&head,number);
        scanf("%d", &number);
	}
	while(head!=NULL)
	    printf("%d ",pop(&head));
	return 0;
}

bool isEmpty(node* head)
{
    if(head==NULL)
        return true;
    else
        return false;
}

int peek(node* head)
{
    if(!isEmpty(head))
        return head->data;
    else
        return -1;
}
int pop(node** head)
{
    if(!isEmpty(*head))
    {
        int value = (*head)->data;
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return (value);
    }
    printf("ERROR - the stack is empty\n");
    return -1;
    
}
void push(node** head, int num)
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
		printf("Error: out of memory, allocation failed!\n");
        return;
    }
    temp->data  = num;
    temp->next = *head;
    *head= temp;
}




