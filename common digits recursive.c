#include <stdio.h>
int commonDigit(int num1  , int num2)
{
    if(num1<=0 || num2<=0)
        return 0;
    if(num1%10 == num2%10)
        return 1 + commonDigit(num1/10,num2/10);
    return commonDigit(num1/10,num2/10);
}
int main()
{

    printf("%d ",commonDigit(4123,123));
    return 0;
}


