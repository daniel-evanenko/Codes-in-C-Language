
#include <stdio.h>
#define N 5
int find_vec_in_mat(int mat[][N] , int vec[] , int size);
int main()
{
    int mat[N][N] = {{1,2,4,6,8},
                     {2,3,4,5,6},
                     {3,4,5,6,7},
                     {4,7,8,9,0},
                     {5,0,0,0,0}};
int vec[3] = {2,4,6};                   
find_vec_in_mat(mat , vec , 3 );
    return 0;
}
int find_vec_in_mat(int mat[][N] , int vec[] , int size)
{
    int flag =1;
    int t;
    for(int i=0;i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(vec[0] == mat[i][j])
            {
                if(j>=size-1)
                {
                    t=j;
                    for(int k=0;k<size;k++)
                        if(vec[k]!=mat[i][t--])
                        {
                            flag=0;
                            break;
                        }
                if(flag)
                {
                    printf("found in row in left direction starting [%d],[%d]\n",i,j);
                    return 1;
                }
                }
                
                if(N-j>=size)
                {
                  t=j;
                  flag=1;
                    for(int k=0;k<size;k++)
                        if(vec[k]!=mat[i][t++])
                        {
                            flag=0;
                            break;
                        }
                    if(flag)
                    {
                    printf("found in row in right direction starting [%d],[%d]\n",i,j);
                    return 1;
                    }
                }
                
                if(i>=size-1)
                {
                    t=i;
                    flag=1;
                    for(int k=0;k<size;k++)
                        if(vec[k]!=mat[t--][j])
                        {
                            flag=0;
                            break;
                        }
                if(flag)
                {
                    printf("found in column up direction starting [%d],[%d]\n",i,j);
                    return 1;
                }
                }
                
                if(N-i>=size)
                {
                    t=i;
                    flag=1;
                    for(int k=0;k<size;k++)
                        if(vec[k]!=mat[i][j])
                        {
                            flag=0;
                            break;
                        }
                if(flag)
                {
                    printf("found in column down direction starting [%d],[%d]\n",i,j);
                    return 1;
                }
                }
            }
            
        }
    if(!flag)
    {
        printf("not found");
        return 0;
    }
}
