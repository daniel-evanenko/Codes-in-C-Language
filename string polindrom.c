#include <stdio.h>
int polidrom(char letters[], int N);

int main()
{
    char letters[] = {'a','b','d','b','a'};
    int N=5;
if(polidrom(letters , N)) 
    printf("is a polidrom\n");
else
    printf("is not polidrom\n");
    return 0;
}
int polidrom(char letters[], int N)
{
    char *p = letters;
    char *q = letters + N-1;
    while(p<q)
    {
        if(*(p++) != *(q--))
            return 0;
    }
   
}    
    


