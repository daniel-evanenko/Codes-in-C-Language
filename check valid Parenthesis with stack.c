#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dataNode
{
    char data; 
    struct dataNode *next;
} node;
bool checkString(char *string);
void push(char num);
bool isEmpty();
char peek();
char pop();
void freeList();
node *head;
int main()
{
    head = NULL;
    char string[] = "{()[]}";
    if(checkString(string))
        printf("vaild\n");
    else
        printf("not vaild\n");
	return 0;
}

bool checkString(char *string)
{
    int i=0;
    int len = strlen(string);
    while(string[i]!='\0')
    {
        if(string[i]=='(' || string[i]=='[' || string[i]=='{')
            push(string[i]);
            
        else if(string[i]==')')
        {
            if(isEmpty() || !isEmpty() && pop() != '(')
                return false;
        }
            
        else if(string[i]=='}')
        {
            if(isEmpty() || !isEmpty() && pop() != '{')
                return false;
        }
            
        else if(string[i]==']')
        {
            if(isEmpty() || !isEmpty() && pop() != '[')
                return false;
        }
        i++;
    }
    
    if(isEmpty()&& i==len)
        return true;
    else
    {
        while(!isEmpty())
            pop();
        return false;    
    }
}
bool isEmpty()
{
    if(head==NULL)
        return true;
    else
        return false;
}

char peek()
{
    if(!isEmpty(head))
        return head->data;
    else
        return -1;
}
char pop()
{
    if(!isEmpty(head))
    {
        char value = head->data;
        node* temp = head;
        head = head->next;
        free(temp);
        return (value);
    }
    return -1;
    
}
void push(char value)
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
		printf("Error: out of memory, allocation failed!\n");
        return;
    }
    temp->data  = value;
    temp->next = head;
    head= temp;
}


void freeList()
{
    if(!isEmpty(head))
    {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}







