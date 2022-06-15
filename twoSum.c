#include <stdio.h>
int twoSum(int nums[], int numsSize, int target);
int main()
{
    int nums[4] = {2,7,11,15};
    int numsSize = 4;
    int target = 3;
    
    int res = twoSum(nums,numsSize,target);
    if(res)
        printf("%d ",res);
    else
        printf("there is no numbers that match\n");

    return 0;
}

int twoSum(int nums[], int numsSize, int target)
{
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<target)
        {
            for(int j=i+1;j<numsSize;j++)
            {
                if(nums[j]+nums[i] == target)
                    return (nums[j]+nums[i]);
            }
        }
    }
    return 0;
}