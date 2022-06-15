#include <stdio.h>
#include <stdlib.h>

int main() {
	int n=5, i=0,num;
	int* numbers;
	numbers = (int*)calloc(n, sizeof(int));
	if (numbers == NULL)
	{
		printf("Error");
		return (-1);
	}

	for (i = 0; i < n; i++)
	{
	    printf("please enter a positive number\n");
	    scanf("%d", &num);
	    if(num<0)
	        break;
	        
	    numbers[i] = num;
	    
	    if(i==n-1)
	    {
	        n*=2;
	        numbers = realloc(numbers,(n*2)*sizeof(int));
	        if (numbers == NULL)
	            {
		            printf("Error");
		            return (-1);
	            }
	    }
	 }
	 i=0;
	 printf("the numbers in the arry are :");
	 while (numbers[i] !=0)
	        printf("%d ",numbers[i++]);
	free(numbers);
	return 0;
}
