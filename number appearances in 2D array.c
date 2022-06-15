#include <stdio.h>
#define N 4
int numfind(int arr[][N] , int num);
int main()
{
    int num;
    printf("please enter a number you want to find\n");
    scanf("%d",&num);
    int arr[N][N]={{4,5,6,1},
                   {8,7,9,1},
                   {3,2,77,1},
                   {1,2,4,2}};
    
    num = numfind(arr,num);       
    if(num)
        printf("the number appear %d times.\n",num);
    else
        printf("the number doesn't appear in the array.");
}

int numfind(int arr[][N] , int num)
{
    int count = 0;
    for(int i=0; i<N; i++)
        for(int j=0;j<N;j++)
            if(num==arr[i][j])
                count++;
    return count;
}
    



