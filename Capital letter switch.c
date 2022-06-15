#include <stdio.h>
#include <string.h>
int func(char *str1, char *str2);
int main()
{
    char str1[16] = "have a nice day";
    char str2[16];
    func(str1,str2);
    printf("str2: %s\n",str2);

    return 0;
}

int func(char *str1, char *str2)
{
    int i,flag=1,len = strlen(str1);
    int dist;
    for(i=0;i<len;i++)
    {
        if((str1[i]<'a' || str1[i]>'z') && str1[i]!= ' ')
        {
            printf("Wrong string\n");
            return -1;
        }
    }
    for(i=0;i<len;i++)
    {
        if(flag)
        {
            dist = str1[i]-'a';
            str2[i]= 'A'+dist;
            flag=0;
        }
        else
            str2[i] = str1[i];
        if(str1[i]==' ')
            flag=1;
    }
    
    
    
}

