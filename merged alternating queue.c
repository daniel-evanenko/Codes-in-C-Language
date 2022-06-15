#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;
node* merge(node* head1, node* head2);
void enterNumbers(node** head,node** END);
void printNode(node* head);
void push(node** head,node** END, int num);
int Remove(node** head);
bool isEmpty(node* head);
int peek(node* head);
int main()
{
    node *head1 = NULL, *END1 = NULL;
    node *head2 = NULL, *END2 = NULL;
    node* mergedHead = NULL;
    enterNumbers(&head1,&END1);
    enterNumbers(&head2,&END2);
    mergedHead = merge(head1,head2);
    printf("queue 1: ");
    printNode(head1);
    printf("queue 2: ");
    printNode(head2);
    printf("merged queue: ");
    printNode(mergedHead);
	return 0;
}
node* merge(node* head1, node* head2)
{
    node* mergedHead , *tail, *temp;
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    
    mergedHead = (node*) malloc(sizeof(node));
    mergedHead-> data = head1->data;
    mergedHead->next = (node*) malloc(sizeof(node));
    tail = mergedHead->next;
    tail->data = head2->data;
    head1 = head1->next;
    head2 = head2->next;
    while(head1!= NULL && head2 != NULL)
    {
        temp = (node*)malloc(sizeof(node));
        temp->data = head1->data;
        tail->next = temp;
        tail = tail->next;
        temp = (node*) malloc(sizeof(node));
        temp->data = head2->data;
        tail->next = temp;
        tail = tail->next;
        head1 = head1->next;
        head2 = head2->next;
        
    }
    while(head1 != NULL)
    {
        temp = (node*) malloc(sizeof(node));
        temp->data = head1->data;
        tail->next = temp;
        tail = tail->next;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        temp = (node*) malloc(sizeof(node));
        temp->data = head2->data;
        tail->next = temp;
        tail = tail->next;
        head2 = head2->next;
    }
    tail->next = NULL;
    return mergedHead;
    
}
void enterNumbers(node** head,node** END)
{
    int number = 0;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0) 
	{
		push(head,END,number);
        scanf("%d", &number);
	}    
}
void push(node** head,node** END, int num)
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
    	printf("Error: out of memory, allocation failed!\n");
        return;
    }
    temp->data  = num;
    temp->next = NULL;
    if(isEmpty(*head))
    {
        *head= temp;
        *END = temp;
        return;
    }
    (*END)->next = temp;
    *END = temp;
}
int peek(node* head)
{
    if(!isEmpty(head))
        return head->data;
    return -1;
}

int Remove(node** head)
{
    if(!isEmpty(*head))
    {
        int val = (*head)->data;
        node* temp = *head;
        (*head) = (*head)->next;
        free(temp);
        return val;
    }
    printf("the queue is empty\n");
    return -1;
}
bool isEmpty(node* head)
{
    if(head==NULL)
        return true;
    return false;
}

void printNode(node* head)
{
    node* curr = head;	
	while (curr!=NULL)
	{
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}








