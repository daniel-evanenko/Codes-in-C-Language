#include <stdio.h>
#include<stdlib.h>
#define N 5
int checkMat(int** mat);
int main(void)
{
    int **arr = malloc(N*sizeof(int*));

    for(int i=0;i<N;i++)
    {
        arr[i] = malloc(N*sizeof(int));
    }

    int  matrix[N][N]={{4,2,1,3,7},
                     {29,7,1,17,13},
                     {26,28,13,4,16},
                     {9,14,22,11,11},
                     {20,6,47,31,17}};

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr[i][j] = matrix[i][j];
        }
    }
    
    printf("%d ",checkMat(arr));   

    return 0;         
}

int checkMat(int** mat)
{
    int perimeter;
    int i,j,sum=0;
    for(perimeter = 0;perimeter<=N/2;perimeter++)
    {
        sum=0;
        for(i= perimeter;i<N-perimeter;i++)
        {
            sum+= mat[i][perimeter]+mat[i][N-1-perimeter]; // sums the sides of the matrix
        }
        for(j=1+perimeter; j<N-1-perimeter;j++)
        {
            sum+= mat[perimeter][j]+mat[N-1-perimeter][j]; // sums the the upper and lower depth staring from index 1. (not to sum the number twice)
        }
        if(N/2 == perimeter) // if its the middle of the matrix and N is un even the depth has only one number so its sums the number twice, the result should be sum/2.
            printf("%d \n",sum/2);
        else
            printf("%d \n",sum);
    }
    int r,c,count; // r=row , c=column
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            count=0;
            for(r=0;r<N;r++) // r=row
                for(c=0;c<N;c++) // c=column
                        if(mat[i][j]==mat[r][c]) // if there is a number that matched increment count by one;
                            count++;
            if(count==5) // if its found 5 or more numbers that are the same it returns;
                return -1;
        }
    return 0;
           
}

