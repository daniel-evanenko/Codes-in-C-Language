#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data;
    struct dataNode* next;
} node;

node* enter_numbers();
node* add_number(node* head ,int num);
node* circle(node* head1, node* head2);
int main()
{
    int number = 0;
    node *head1 = NULL, *temp = NULL, *pprint;
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
		temp->next = head1;
		head1 = temp;
        scanf("%d", &number);
	}
    number = 0;
    node *head2 = NULL;
    temp = NULL;
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
		temp->next = head2;
		head2 = temp;
        scanf("%d", &number);
	}
    node* head3;
    head3 = circle(head1,head2);
    node* curr = head3;
    for(int i=0;i<1;i++)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    return 0;
    
}

node* enter_numbers()
{
    int number = 0;
    node* head = NULL, * temp = NULL;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0)
    {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
        temp->data = number;
        temp->next = head;
        head = temp;
        scanf("%d", &number);
    }
    return head;
}
node* circle(node* head1, node* head2)
{
    node* itr1 = head1;
    node* itr2 = head2;
    int cntHead1=0;
    int cntHead2=0;
    
    if(head1 == NULL && head2!= NULL)
    {
        while(itr2->next!= NULL)
            itr2 = itr2->next;
            
        itr2->next = head2;
        return head2;
    }

    else if(head1!= NULL && head2==NULL)
    {
        while(itr1->next!= NULL)
            itr1 = itr1->next;
            
        itr1->next = head1;
        return head1;
    }

    else if(head1 == NULL && head2 == NULL)
        return NULL;
    
    while(itr1->next!=NULL)
    {
        cntHead1++;
        itr1 = itr1->next;
    }

    while(itr2->next!=NULL)
    {
        cntHead2++;
        itr2 = itr2->next;
    }

    if(cntHead1<cntHead2)
    {
        itr1->next = head2;
        itr2->next = head1;
        return head1;
    }
    else
    {
        itr2->next = head1;
        itr1->next = head2;
        return head2;
    }
    
}

