#include <stdlib.h>
#include <stdio.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;

typedef struct DataNode
{
    int data; 
    struct DataNode* next;
    struct DataNode* prev;
} newNode;

node* enter_numbers();
node* makeTwoWaysNode(node* head1);

int main()
{
    node* head1=NULL; 
    newNode* newHead=NULL;
    head1 = enter_numbers();
    newHead = makeTwoWaysNode(head1); // the newHead pointing to the last element so we need to print it backwards.
	
    if (head1 == NULL || newHead == NULL)
		 return 0;
	printf("old list:\n");
    while (head1!= NULL)
    {
        printf("%d ",head1->data);
        head1 = head1->next;
    }
    printf("\nnew list: \n");
	while (newHead!= NULL) // prints newHead backwards
    {
        printf("%d ",newHead->data);
        newHead = newHead->prev;
    }
    printf("\n");
	return 0;
}


node* enter_numbers()
{
    int number = 0;
    node *head = NULL, *temp = NULL;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0) 
	{
     	temp = (node*) malloc(sizeof(node));
		if (temp == NULL) 
        {
			printf("Error: out of memory, allocation failed!\n");
            return EXIT_FAILURE;
		}
		temp->data = number;
		temp->next = head;
		head = temp;
        scanf("%d", &number);
	}
	    return head;
}
node* makeTwoWaysNode(node* head1)
{
    newNode *head2 = NULL, *temp = NULL;
    while (head1 != NULL) // runs till head1 == NULL
	{
     	temp = (newNode*) malloc(sizeof(newNode));
		if (temp == NULL) 
        {
			printf("Error: out of memory, allocation failed!\n");
            return EXIT_FAILURE;
		}
		temp->data = head1->data; // puts the data from head1 in to newHead
		temp->next = head2;
		head2 = temp;
		head1 = head1->next;
		
		
	}
	head2->prev=NULL;
	temp=head2;
	while(temp->next!= NULL)
	{
	    temp->next->prev = temp; 
	    temp = temp->next;
	    
	}
	head2 = temp;
	head2->next = NULL; // puts NULL in the newHead tail. because we ran over the newHead list till the last element in (while loop) above us.
	
    return head2;
}

