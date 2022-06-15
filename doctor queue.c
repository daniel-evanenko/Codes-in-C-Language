#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct dataNode
{
    char id[10];
    char name[10];
    struct dataNode *next;
} node;

void printNode();
void push();
bool Remove();
bool isEmpty();
void peek();
node* head;
node* END;
int main()
{
    int choise = 0;
    head = NULL, END = NULL;
    printf("to enter to the doc press 1, to enter the queue press 2, to exit press -1\n");
    scanf("%d",&choise);
    while(choise!=-1)
    {
        if(choise == 1)
        {
            if(Remove())
                printf("enter to the doc\n");
        }
        else if(choise == 2)
        {
            push();
            printf("enter to the queue\n");
        }
        printf("to enter to the doc press 1, to enter the queue press 2, to exit press -1\n");
        scanf("%d",&choise);
    }
    printf("good bye\n");
	return 0;
}

void push()
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
    	printf("Error: out of memory, allocation failed!\n");
        return;
    }
    printf("please enter your name\n");
    scanf("%s",temp->name);
    printf("please enter your id \n");
    scanf("%s",temp->id);
    temp->next = NULL;
    if(isEmpty())
    {
        head= temp;
        END = head;
        return;
    }
    END->next = temp;
    END = temp;
    return;
}
void peek()
{
    if(!isEmpty())
    {
        printf("name: %s , id: %s\n",head->name,head->id);
        return;
    }
    printf("the queue is empty\n");
}

bool Remove()
{
    if(!isEmpty())
    {
        printf("name: %s , id: %s\n",head->name,head->id);
        node* temp = head;
        head = head->next;
        free(temp);
        return true;
    }
    printf("the queue is empty\n");
    return false;
}
bool isEmpty()
{
    if(head==NULL)
        return true;
    return false;
}

void printNode( )
{
    node* curr = head;	
	while (curr!=NULL)
	{
		 printf("name: %s , id: %s\n",head->name,head->id);
		curr = curr->next;
	}
	printf("\n");
}





