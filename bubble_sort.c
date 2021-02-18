#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int bubble_sort(int arr[],int size)
{
	int i, j, temp, counter;
	
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
			counter++;	
		}
	} return counter;
}


int main(int argc, char *argv) {
	
	int array[5]={1,3,5,2,4};
	int i, size=5;
	
	printf("number of steps: %d\n",bubble_sort(array,5));
	
	for(i=0; i<size; i++)
	{
		printf("%d - ",array[i]);
	}
	
	return 0;
}
