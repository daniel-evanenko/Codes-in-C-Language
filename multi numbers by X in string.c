#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int func(char *str);
int main()
{
    char string[100];
    printf("please enter string\n"); 
    gets(string);
    printf("\nnumbers that created: %d\n", func(string));

    return 0;
}

int func(char *str)
{
    int count=1;
    for(int i=0;i<strlen(str);i++)
        if((str[i]<'0' || str[i]>'9') && str[i]!='x' && str[i]!=' ')
                return -1;
    
    for(int i=1;i<strlen(str)-1;i++)
        if(str[i]=='x')
            if((str[i-1]==' ' || str[i-1]=='x' &&str[i+1]==' ' || str[i+1]=='x'))
                return -1;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='x')
        {
            for(int j=0;j<(str[i+1]-'0'-1);j++)
                printf("%c",str[i-1]);
            i++;
        }
        else if(str[i]!=' ')
            printf("%c",str[i]);
        else
        {
            printf("\n");
            count++;
        }
    }
    return count;
}
/*
please enter string
245 56x2 76x5
245
566
766666
numbers that created: 3
*/


