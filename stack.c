#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct dataNode
{
	char* data;
	struct dataNode *next;
} node;

node* head;

int isEmpty() // if emtpy = 1
{
    if(head==NULL)
        return true;
    return false;
}
void push(char* n)
{
     	node* temp = (node*) malloc(sizeof(node));
     	int len = strlen(n)+1;
     	char* str = (char*) malloc(sizeof(char)*len);
		if (temp == NULL || str == NULL) 
        {
			printf("Error: out of memory, allocation failed!\n");
            return;
		}
		strcpy(str,n);
		temp->data = str;
		temp->next = head;
		head = temp;
}

char* pop()
{
    if(isEmpty())
        return NULL;
    node* temp = head;    
    char* str = head->data;
    head = head->next;
    free(temp);
    return str;
}

char* peek() // top
{
    if(isEmpty())
        return NULL;
    return head->data;
    
}
void printStack()
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool checkPali(char *string,int n)
{
    if(n<=1)
        return true;
    if(*string != string[n-1])
        return false;
    return checkPali(string+1,n-2);
    
}
void main()
{
    head = NULL;
    char* temp;
    char str[240];
    printf("please enter a string\n");
    scanf("%s",str);
    push(str);
    printf("stack:");
    printStack();
    pop(temp);
    int n = strlen(temp);
    printf("%s \n",temp);
    printf("%d",n);
    // printf("is palidrom=: %d\n",checkPali(temp,n));

    // printf("the stack is emtpy=: %d\n",isEmpty());
 
}

