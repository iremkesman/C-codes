#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int multipication(int a, int b)
{
	if(b==1)
	return a;
	else
	return a + multipication(a,b-1);
}


int main(int argc, char *argv[]) {
	
	int a,b;
	
	printf("enter the numbers will be multiply");
	scanf("%d %d",&a,&b);
	
	printf("%d",multipication(a,b));
	
	return 0;
}
