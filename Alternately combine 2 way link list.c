#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;

typedef struct dataNode2
{
    int data; 
    struct dataNode2 *next;
	struct dataNode2 *prev;
} node2;

node* enter_numbers();
node2* flip2Ways(node* head1 , node* head2);

int main()
{
    node* head1, curr1;
	node* head2, *curr2;
	node2* Combined_head, *curr3;
   
	head1 = enter_numbers();
	head2 = enter_numbers();
	Combined_head = flip2Ways(head1,head2);
	
	//print reverse list
    curr3 = Combined_head;
	 if (curr3 == NULL)
		 return 0;
	while(curr3->next !=NULL)
		curr3 = curr3->next;
    while (curr3!= NULL)
    {
        printf("%d ",curr3->data);
        curr3 = curr3->prev;
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

node2* flip2Ways(node* head1 , node* head2)
{
	node2* head, *temp, *prev1;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if(head2!=NULL)
	{
	head = (node2*) malloc(sizeof(node2));
	head->data = head2->data;
	head->prev = NULL;
	head2 = head2->next;
	prev1 = head;
	}
	else
	{
	head = (node2*) malloc(sizeof(node2));
	head->data = head1->data;
	head->prev = NULL;
	head1 = head1->next;
	prev1 = head;	    
	}
	
	while (head1!=NULL && head2 != NULL)
	{
		temp = (node2*) malloc(sizeof(node2));
		temp->data = head1->data;
		temp->prev = prev1;
		prev1->next = temp;
		head1 = head1->next;
		prev1 = temp;
		temp = (node2*) malloc(sizeof(node2));
		temp->data = head2->data;
		temp->prev = prev1;
		prev1->next = temp;
		head2 = head2->next;
		prev1 = temp;

	}
	
	while(head2!=NULL)
	{
	    temp = (node2*) malloc(sizeof(node2));
        temp->data = head2->data;
        temp->prev = prev1;
        prev1->next = temp;
        head2 = head2->next;
        prev1 = temp;
	}
	        
	while(head1!=NULL)
	{
	    temp = (node2*) malloc(sizeof(node2));
        temp->data = head1->data;
        temp->prev = prev1;
        prev1->next = temp;
        head1 = head1->next;
        prev1 = temp;
	}
	prev1->next = NULL;
	
	return head;
    }

