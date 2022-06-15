#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;

void printNode(node* head);
void freeList(node* head);
void push(node** head, int num);
void reverse(node** head);
int main()
{
    int number = 0;
    node *head = NULL, *temp = NULL, *pprint;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0) 
	{
		push(&head,number);
        scanf("%d", &number);
	}
	printNode(head);
	reverse(&head);
	printNode(head);
	freeList(head);
	return 0;
}
void reverse(node** head)
{
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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

void freeList(node* head)
{
   node* temp;

   while (head != NULL)
    {
       temp = head;
       head = head->next;
       free(temp);
    }

}




