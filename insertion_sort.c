#include <stdio.h>
#include <stdlib.h>

int dizi[10];
int key;

int insertion_sort(int dizi[], int elements_num)
{
	int i, j, counter;
	
	for(i=1; i<elements_num; i++)
	{
		key=dizi[i];
		j=i-1;
		while(key < dizi[j] && j>=0)
		{
			dizi[j+1] = dizi[j];
			j--;
		}
		
		dizi[j+1] = key;
		counter++;
	} return counter;
}



int main(int argc, char *argv[]) 
{
	int i, piece;/*adet*/
	
	printf("how many numbers will you entered");
	scanf("%d", &piece);
	
	for(i=0; i<piece; i++)
	{
		printf("%d. number= ", i+1);
		scanf("%d", &dizi[i]);
	}
	
	printf("number of steps: %d\n",insertion_sort(dizi, piece));
	
	for(i=0; i<piece; i++)
	{
		printf("%d-", dizi[i]);
	}
	
	
	return 0;
}
