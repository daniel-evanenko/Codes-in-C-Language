#include <stdio.h>
void MergeArrayRecursively(int array1[], int n, int array2[], int m, int array3[], int i, int j,int k ){
	
	// checking if there are elements to compare
	if(i<n&&j<m){
		
		// compares array1[i] and array2[j]
		// push the smaller elements to array3 and move to next index
		if(array1[i]<array2[j]){
			array3[k] = array1[i];
			++i;
		}
		else{
			array3[k] = array2[j];
			++j;
		}
		
		++k;
		MergeArrayRecursively(array1,n,array2,m,array3,i,j,k);
		
	}
	else{
		
		// this code segment will run if there's no element left to compare
		// in array 1 or array 2
		// we push the remaining elements of other array to array 3
		while(i<n){
			array3[k] = array1[i];
			++i;
			++k;
		}
		
		while(j<m){
			array3[k] = array2[j];
			++j;
			++k;
		}
		
	}
	
}

void PrintArray(int array[], int n){
	for(int i=0;i<n;++i)
		printf("%d ",array[i]);
	printf("\n");
}
int main()
{
	int n,m;
	int array3[100];
	int array1[] = {56,103,1001,90021};
	int array2[] = {30,50,200,3427,65090};
	n = sizeof(array1)/sizeof(int);	// length of array 1
	m = sizeof(array2)/sizeof(int); // Length of array 2
	
	PrintArray(array1, n);
	PrintArray(array2, m);
	
	MergeArrayRecursively(array1,n,array2,m,array3,0,0,0);
	
	PrintArray(array3,n+m);

    return 0;
}

