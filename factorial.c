#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fact(int n)
	{
		if(n>=1)
		{
			return n*fact(n-1);
		}
		else
			return 1;
	}
	
int main(int argc, char *argv[]) {
	
	int num;
	
	printf("Which numbers do you want to calculate the factorial?");
	scanf("%d",&num);
		
	printf("result: %d",fact(num));
	
	return 0;
}
