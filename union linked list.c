#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;

node* enter_numbers();
node* unionTwoLists(node* head1, node* head2);

int main()
{
	node* curr;
    node* head1 = enter_numbers();
    node* head2 = enter_numbers();
	head1 = unionTwoLists(head1,head2);
    curr = head1;
    if (curr == NULL)
		 return 0;
    printf("%d ",curr->data); // print the list
    curr = curr->next;
    while (curr!= head1)
    {
        printf("%d ",curr->data);
        curr = curr->next;
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

node* unionTwoLists(node* head1, node* head2)
{
    node *tail1 = head1;
	node *tail2 = head2;
    int count1 = 1;
    int count2 = 1;
	
	if (head1== NULL && head2==NULL)
		return NULL;
	
	
	while (tail1!=NULL && tail1->next != NULL) // find tail and amount of elemnts from head1
    {
        tail1 = tail1->next;
        count1++;
    }
    
    while (tail2!=NULL && tail2->next != NULL) //find tail and amount of elemnts from head2
    {
        tail2 = tail2->next;
        count2++;
    } 
    if (head1==NULL)
	{
		tail2->next = head2;
		return head2;
	}
	if (head2==NULL)
	{
		tail1->next = head1;
		return head1;
	}
	
	tail1->next = head2;
    tail2->next = head1;
    if(count1<=count2) // if list 1 < list 2
        return head1;
    return head2;
}


