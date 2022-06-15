#include <stdio.h>
int checkPali(char *string,int n);
int main()
{
    char string[9] = "abcdedcba";
    int n=9;
    printf("%d",checkPali(string,n));
    return 0;
}
int checkPali(char *string,int n)
{
    if(n<=1)
        return 1;
    if(*string != string[n-1])
        return 0;
    return checkPali(string+1,n-2);
    
}

