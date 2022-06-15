#include <stdio.h>
#define N 4
int maxnum(int arr[][N]);
int main()
{
    int arr[N][N]={{4,5,6,1},
                   {8,7,9,1},
                   {3,2,77,1},
                   {1,2,4,2}};
printf("the max number is: %d",maxnum(arr));
    return 0;
}
int maxnum(int arr[][N])
{
    int max = arr[0][0];
    for(int i=0; i<N; i++)
        for(int j=0;j<N;j++)
            if(max<arr[i][j])
                max = arr[i][j];
        
    
    return max;
}

