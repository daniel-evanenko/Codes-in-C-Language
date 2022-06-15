#include <stdio.h>
int twoArrs(int arr1[15],int arr2[15],int arr3[15]);
int main()
{
    int arr1[15]={10,94,9,82,37,9,2,21,2,5,78,7,91,36,49};
    int arr2[15]={1,56,33,82,45,98,2,21,2,87,17,7,10,63,9};
    int arr3[15]={60,23,19,34,11,50,2,36,2,27,78,7,9,65,14};
    printf("%d ",twoArrs(arr1 , arr2,arr3));
    return 0;
}
int twoArrs(int arr1[15],int arr2[15],int arr3[15])
{
    int i,j,k;
    int flag=1;
    int sum_arr[45];
    int temp_arr[15]={0};
    int all_numbers_arr[45]={0};
    for(int i=0;i<15;i++)
    {
        if(arr1[i]<0 || arr2[i]<0 || arr3[i]<0)
            return -1;       
    }
    for(int i=0,j=0;i<15;i++) // copys all the elements from arr1/arr2/arr3 to one arr.
    {
        sum_arr[j++]=arr1[i];
        sum_arr[j++]=arr2[i];
        sum_arr[j++]=arr3[i];
    }
    printf("the uniqe numbers in the arrays are: \n");
    for(i=0;i<45;i++)
    {   
        int count =1;
        for(j=0;j<45;j++)
        {   
            if(i!=j)
                if(sum_arr[i]==sum_arr[j]) // checks if the number appears more then once.
                    count++;
        }
        
        if(count==1)
            printf("%d ",sum_arr[i]);
        for(k=0;k<45;k++)
        {
            flag=1;
            if(sum_arr[i]==all_numbers_arr[k])
            {
                flag=0;
                break;
            }
            
        }
        if(flag)
            all_numbers_arr[i]=sum_arr[i];
            
    }
    printf("\nthe numbers that appear in all 3 arrays are: \n");
    for(int i=0;i<15;i++)
    {
        int apper_flag = 0;
        for(int check = 0; check<15;check++)
        {
            if(arr1[i]==temp_arr[check]) // checks if the number arr[i] appers in the temp_arr (arr with the numbers that appear in all 3 arrays)
            {
                apper_flag =1;
                break;
            }
        }
        if(!apper_flag)
        {
        for(int j=0;j<15;j++)
            {
                if(arr1[i]==arr2[j]) // checks if the number apper in the arr2. if TRUE checks if the number apper in arr3 if it does it appends the number to temp_arr
                {
                    for(int k=0;k<15;k++)
                        if(arr1[i]==arr3[k])
                        {
                            temp_arr[i]=arr1[i];
                            printf("%d ",arr1[i]);
                            break;
                        }  
                    break; 
                }
            }
        }
    }
    printf("\nall the numbers in the arrays are: \n");
    for(i=0;i<45;i++)
        if(all_numbers_arr[i]!= 0)
            printf("%d ",all_numbers_arr[i]);
    
}
