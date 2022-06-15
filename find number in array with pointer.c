#include <stdio.h>
int findnum(int arr[],int N,int num);
int main()
{
    int arr[]={1,2,3,4,5};
    if(findnum(arr,5,3))
        printf("number found\n");
    else
        printf("cant find number\n");

    return 0;
}
int findnum(int arr[],int N,int num)
{
    
    int *p = arr;
    int *q = arr+N-1;
    
    while(*p < *q)
    {
        if(*(p++) == num)
            return 1;
    }
    return 0;
    
    
    
}

