#include <stdio.h>
int search(int* nums, int numsSize, int target);
int main()
{
    int nums[] = {-1,0,3,5,9,12};
    printf("%d \n",search(nums,6,9));
    return 0;
}
int search(int* nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize-1;
    int m;
    while(l<=r)
    {
        m = ((l+r) / 2);
        if(nums[m] < target)
            l = m+1;
        else if(nums[m] > target)
            r = m-1;
        else
            return m;
    }
    return -1;
}