#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num; 
    struct node *next;
} Nodes;
Nodes *recursiveMax(Nodes *head);
int main()
{
    int number = 0;
    Nodes *head = NULL, *temp = NULL, *pprint;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0) 
	{
     	temp = (Nodes*) malloc(sizeof(Nodes));
		if (temp == NULL) 
        {
			printf("Error: out of memory, allocation failed!\n");
            return 0;
		}
		temp->num = number;
		temp->next = head;
		head = temp;
        scanf("%d", &number);
	}
	printf("the largest number is:%d ",*recursiveMax(head));

    return 0;
}


Nodes *recursiveMax(Nodes *head)
{
    Nodes *next;

    if(head->next == NULL) 
        return head;
    next = recursiveMax(head->next);

    if(head->num > next->num)
        return head;
        
    return next;
}

