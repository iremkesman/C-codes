#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fibonacci(int n)
{
	if(n==0)
	{
		return 0;
	}
	
	else if(n==1)
	{
		return 1;
	}
	
	else
	{
		return (fibonacci(n-1) + fibonacci(n-2));
	}
}

int main(int argc, char *argv[]) {
	
	int n,i;
	
	printf("how many times do you want to calculate ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("%d ",fibonacci(i));
	}
	return 0;
}
