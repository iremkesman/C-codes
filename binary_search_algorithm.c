#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define max 10
int arr[max]={1,2,3,4,5,6,7,8,9,10};

int find(int data)
{
	int upper_bound = max-1;
	int lower_bound = 0;
	int midpoint = 0;
	int index = 0;
	
	while(lower_bound <= upper_bound)
	{
		midpoint= lower_bound + (upper_bound-lower_bound)/2;
		
		if(arr[midpoint] == data)
		{
			index = midpoint;
			break;
		}
		else
		{
			if(arr[midpoint] < data)
			{
				lower_bound = midpoint+1;
			}
			else
			{
				upper_bound = midpoint-1;
			}
		}
		
	}
	return index;	
}

int main(int argc, char *argv[]) {
	
	int location = 0;
	int num, i;
	
	for(i=0; i<max; i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\nwhich num do you looking for:");
	scanf("%d",&num);
	
	location = find(num);
	
	if(location != 0)
	{
		printf("%d num is founded in %d. index",num,location);
	}
	else
	{
		printf("%d num is not founded",num);
	}
	
	
	return 0;
}
