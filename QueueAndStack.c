#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct dataNode
{
	int data;
	struct dataNode *next;
} node;

node* head1;
node* head2;


bool isEmpty(node* head)
{
	if (head==NULL)
        return true;
    return false;
}
bool areEmpty(node* head1,node* head2)
{
	if (head1==NULL&& head2==NULL)
        return true;
    return false;
}


int pop(node** head) // **head pointing to *head that pointing to the node.
{
    if(isEmpty(*head)) // if the value of the **head that pointing to *head that pointing to node is != NULL
        return -1;
    node* temp = *head;    
    int num = temp->data;
    *head = (*head)->next;
    free(temp);
    return num;
    
    
}

void printStack(node** head)
{
    node* temp = *head; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(int n,node** head)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->next = *head;
    *head = temp;
}

int Remove(node** head1,node** head2)
{
    if(areEmpty(*head1,*head2)) // if the 2 stacks are empty then there is now values to remove.
    {
        printf("\nthe Queue is empty\n");
        return -1;
    }
    int num;
    int returnVal;
    while (!(isEmpty(*head1))) // if all the values are in stack 1 so move then to stack 2 so its ordered like queue and then pop them.
    {
        num = pop(head1);
        insert(num,head2);
    }
    returnVal = pop(head2);
    while (!(isEmpty(*head2))) // if all the values are in stack 1 so move then to stack 2 so its ordered like queue and then pop them.
    {
        num = pop(head2);
        insert(num,head1);
    }
    return returnVal;
    
}
int peek(node* head1,node* head2) // top
{
    if(areEmpty(head1,head2))
        return -1;
    int num;
    int returnVal;
    while (!(isEmpty(head1))) // if all the values are in stack 1 so move then to stack 2 so its ordered like queue and then pop them.
    {
        num = pop(&head1);
        insert(num,&head2);
    }
    returnVal = head2->data;
    while (!(isEmpty(head2))) // if all the values are in stack 1 so move then to stack 2 so its ordered like queue and then pop them.
    {
        num = pop(&head2);
        insert(num,&head1);
    }
    return returnVal;
}

void main()
{
	head1 = NULL;
	head2 = NULL;
    
    for (int i=1; i<=5; i++)
	{
        insert(i,&head1);
    }
    printStack(&head1);

    for (int i=0; i<6; i++)
        printf ("%d ",Remove(&head1,&head2));

}