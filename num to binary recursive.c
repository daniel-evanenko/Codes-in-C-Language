#include <stdio.h>
void binaryNum(int num)
{
    if(num==0)
        return;
    binaryNum(num/2);
    printf("%d ",num%2);
}
int main()
{

    binaryNum(13);
    return 0;
}


