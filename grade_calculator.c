#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int fg, sg, avrg, i, n, sum=0;
	int g[10];
	
		printf("How many grade will you enter?");
		scanf("%d",&n);
	
	for(i=1; i<n+1; i++)
	{
		
		printf("please enter your %i. grade:");
		scanf("%d",&g[i-1]);
		
		
	}
	
			
	for(i=0; i<n; i++)
	{
		sum += g[i];
		
	}
	
		avrg = sum/n;
	
	/*printf("please enter your first grade:");
	scanf("%d",&fg);
	
	printf("please enter your second grade:");
	scanf("%d",&sg);
	
	avrg=(fg + sg)/2; */
	
	if (avrg>50)
		printf("your grade is %d so you pass", avrg);
		
	else
		printf("your grade is %d so you fail", avrg);
		
	
	return 0;
}
