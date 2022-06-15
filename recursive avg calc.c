#include <stdio.h>
float recAvg(int *arr , int n,int n2);
int main()
{
    int arr[] = {9,10,11,12};
    int n = 4;
    printf("the avg is: %.2f \n",(recAvg(arr,n,n)));

    return 0;
}

float recAvg(int *arr , int n,int n2)
{
    if(n==0)
        return 0.0;
    return (recAvg(arr,n-1,n2)+(float)arr[n-1]/n2);
}


