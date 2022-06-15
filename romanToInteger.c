
#include <stdio.h>
int romanToInt(char * s);
int main()
{
    char *s = "IX";
    printf("%d ",romanToInt(s));
}



int romanToInt(char * s)
{
    int result = 0;
    while(*s != '\0')
    {
        switch (*s)
        {
            case 'I':
                if(*(s+1) == 'V')
                {
                    result += 4;
                    s++;
                }
                else if(*(s+1) == 'X')
                {
                    result += 9;
                    s++;
                }
                else
                    result+=1;
                break;
                
            case 'V':
                result+=5;
                break;
            case 'X':
                if(*(s+1) == 'L')
                {
                    result+= 40;
                    s++;
                }
                else if(*(s+1) == 'C')
                {
                    result += 90;
                    s++;
                }
                else
                    result+= 10;
                break;
            case 'L':
                result+= 50;
                break;
            case 'C':
                if(*(s+1) == 'D')
                {
                    result+= 400;
                    s++;
                }
                else if(*(s+1) == 'M')
                {
                    result+= 900;
                    s++;
                }
                else
                    result += 100;
                break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result +=1000;
                    break;
            default:
                break;
        }
        s++;
    }
    return result;
}