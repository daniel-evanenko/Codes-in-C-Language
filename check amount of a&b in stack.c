#include stdio.h
#include string.h
#include stdbool.h
#include stdlib.h
int stack;
int top = -1;
void push(char num);
char pop();
char peek();
bool empty();
int N;
bool checkString(char string);
int main()
{
    char string[] = aaabbb;
    if(checkString(string))
        printf(vaildn);
    else
        printf(not vaildn);

    return 0;
}

bool checkString(char string)
{
    N=strlen(string);
    if(N=2)
    {
        stack = malloc(sizeof(int)  N);
        int i=0;
       while(string[i]!='0')
        {
            if(string[i]=='a')
            {
                push(string[i]);
                i++;
            }
            else if(string[i]=='b')
            {
                if(!pop())
                    return false;
                i++;
            }
        }
        if(empty()&& i==N)
            return true;
        else
        {
            while(empty())
                pop();
            return false;    
        }
    }
    else
        return false;
    
}
void push(char value)
{
    if(top N-1)
        stack[++top] = value;
    else
        printf(ERROR - stack is full (push)n);
}

char pop()
{
    if(!empty())
        return stack[top--];
    return -1;
}

char peek()
{
    if(!empty())
        return stack[top];
    else
        printf(ERROR - stack is emptyn);
        
}
bool empty()
{
    if(top == -1)
        return true;
    else
        return false;
}





