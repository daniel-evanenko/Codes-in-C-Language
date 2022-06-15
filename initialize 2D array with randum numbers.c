#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
void printarry(int arr[][N]);
int main()
{
int arr[N][N];
srand(time(NULL));

for(int i =0; i<N; i++){

    for(int j=0; j<N; j++)
    {
        int random = rand();
        arr[i][j]= random %20;
    }
}
    printarry(arr);
return 0;
}
void printarry(int arr[][N])
{
    for(int i=0;i<N; i++)
    {
        printf("[");
            for(int j=0; j<N; j++)
            {
                printf("%d ",arr[i][j]);
            }
        printf("]\n");
    }

}
