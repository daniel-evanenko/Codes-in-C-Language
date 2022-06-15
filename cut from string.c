#include <stdio.h>
#include <string.h>
char *cut_from_str(char *str1, char*str2, int start,int len);
int main()
{
    char str2[50],str1[] = "question number two";
    cut_from_str(str1,str2,9,6);
    printf("str2: %s\n",str2);
    printf("str1: %s\n",str1);
    return 0;
}


char *cut_from_str(char *str1, char*str2, int start,int len)
{
    /* check if the starting point and the amount of chars to copy is not out of range */
    if(start>strlen(str1) || start<0 || len<0)
        return str2;
    /* check if the amount of chars to copy is not out of range */    
    else if(len>strlen(str1))
        len = strlen(str1);
        
    /* check if the remaing chars to copy is not bigger/over the str length */    
    if(start+len>strlen(str1))
        len = strlen(str1)-start; // amount of chars to copy
    
    /*copy to str2 , str[strat] len chars.*/
    strncpy(str2,str1+start,len);
    
    /*delete from str[start] to str[start+len] amount of chars that left.*/
    strncpy(str1+start,str1+(start+len),strlen(str1)-start-len+1); 
}

