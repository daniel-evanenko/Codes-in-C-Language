#include <stdio.h>
#define N 5
int funcA(int mat[][N] , int *perimeter);
int funcB(int mat[][N]);
int main()
{
    int row =1;
    int mat[N][N] = {{1,2,3,4,5},
                    {1,5,5,5,2},
                    {1,4,1,4,4},
                    {1,2,2,2,2},
                    {1,1,1,1,2}};
int res =funcA(mat,&row);
if(res)
    printf("sum of the numbers in the requested perimeter = %d\n",res);

printf("the biggest sum is in depth: %d\n",funcB(mat));
    return 0;
}
int funcA(int mat[][N] , int *perimeter) // The function will calculate the sum of the numbers in the requested perimeter and return the amount.
{
    if(*perimeter > N-1/2)
    {
        *perimeter =-1;
         return 0;
    }
    int i,j,sum=0;
    for(i= *perimeter;i<N-*perimeter;i++)
    {
        sum+= mat[i][*perimeter]+mat[i][N-1-*perimeter];
    }
    for(j=1+*perimeter; j<N-1-*perimeter;j++)
    {
        sum+= mat[*perimeter][j]+mat[N-1-*perimeter][j]  ; 
    }
    if(N%2==0)
        return sum;
    else if(N/2 == *perimeter)
        return sum/2;
    else
    return sum;
}
int funcB(int mat[][N])
{
    int i=0,sum,maxSum = funcA(mat, &i),depth=0; // The function will calculate the biggest sum of the numbers in the perimeters of the matrix and return the amount
    for(int i=1; i<=(N-1)/2;i++)
    {
            sum = funcA(mat, &i); // i will be in legal depth , so it will not be changed
            if(sum>maxSum)
            {
                maxSum = sum;
                depth = i;
            }
    }
    return depth;
}



