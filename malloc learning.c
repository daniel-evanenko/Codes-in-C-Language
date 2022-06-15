#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* grades;
    int n , i;
    float avg=0.0;
    printf("please enter num of students\n");
    scanf("%d",&n);
    grades = (int*)malloc(n * sizeof(int));
    if(grades == NULL)
    {
        printf("ERROR");
        return 1;
    }
    for(i=0;i<n; i++)
    {
        printf("please enter your grade\n");
        scanf("%d",&grades[i]);
        avg+=grades[i];
    }
    avg = avg/n;
    printf("the avg is :%.2f",avg);
    free(grades);
    return 0;
}

