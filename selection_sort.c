#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	
	int selection_sort(int arr[], int size)
	{
		int i, j,min, temp, counter=0;
		for(i=0; i<size-1; i++)
		{
			min=i;
			for(j=i+1; j<size; j++)
			{
				if(arr[j]<arr[min])
					min = j;	
			}
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
			counter++;
		}
		return counter;
	}
	
	int main(int argc, char *argv[]) {

		int array[5]={1,3,5,2,4};

		int i, size=5;
			
			printf("number of steps: %d\n",selection_sort(array,5));
			
			for(i=0; i<size; i++)
			{
				printf("%d - ",array[i]);	
			}		
								
			
								
	return 0;
}
