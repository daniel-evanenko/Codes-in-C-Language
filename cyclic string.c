#include <stdio.h>
#include <string.h>
int equal_cyclic(char *str1,char *str2);
int main()
{
    char str1[]= "helloworld";
    char str2[]= "worldhello";
    int res = equal_cyclic(str1,str2);
    if (res)
        printf ("match\n");
    else
        printf ("do not match\n");
        
    return 0;
}
int equal_cyclic(char *str1,char *str2)
{
    int i,j,k,flag=0;
    int N = strlen(str1);
    for (i=0;i<N&&!flag;i++)
    {
        j=0;
        if (str1[i] == str2[j])
        {
            k=i;
            flag = 1;
            for (;j<N&&flag;j++,k++)
                if (str1[k%N] != str2[j])
                    flag = 0;
        }
    }
    return (flag);
}
