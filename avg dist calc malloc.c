#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N ,i=0,*numbers;
    int max,min;
    float avg=0.0,dist;
    printf("please enter num of numbers\n");
    scanf("%d",&N);
    numbers = (int*)malloc(N*sizeof(int));
    if(numbers == NULL || N <2)
    {
        printf("ERROR");
        return 1;
    }
    printf("please enter a number\n");
    scanf("%d",&numbers[i]);
    min = numbers[i];
    max = numbers[i];
    avg+=numbers[i];
    for(i=1; i<N; i++)
    {
        printf("please enter a number\n");
        scanf("%d",&numbers[i]);
        avg+=numbers[i];
        if(numbers[i]<min)
            min = numbers[i];
        if(numbers[i] > max)
            max = numbers[i];
        
    }
    avg = avg/N;
    printf("avg = %.2f\n",avg);
    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
    
    
    for(i=0; i<N; i++)
    {
        dist = abs(avg - numbers[i]);
        printf("the distance of number %d from the avg is %.2f\n",numbers[i],dist);
    }
   

    return 0;
}

