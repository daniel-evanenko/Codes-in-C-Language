#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data; 
    struct dataNode *next;
} node;
node* enterNumbers(node* head);
int commonNumbers(node* head1,node* head2);
void printNode(node* head);
void freeList(node* head);
void push(node** head, int num);
int main()
{
    node *head1 = NULL , *head2 = NULL;
    head1 = enterNumbers(head1);
    head2 = enterNumbers(head2);
	printNode(head1);
	printNode(head2);
	printf("%d ",commonNumbers(head1,head2));
	return 0;
}
node* enterNumbers(node* head)
{
    int number = 0;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0) 
	{
		push(&head,number);
        scanf("%d", &number);
	}
	return head;
}
int commonNumbers(node* head1,node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return 0;
    int ans = 0,val;
    node* tmpHead = head2;
    while(head1 !=NULL)
    {
        val = head1->data;
        tmpHead = head2;
        while(tmpHead!=NULL)
        {
            if(val == tmpHead->data)
            {
                ans++;
                break;
            }
            tmpHead = tmpHead->next;
        }
        head1 = head1->next;
    }
    return ans;
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





