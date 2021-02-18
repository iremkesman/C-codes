#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
int board[SIZE][SIZE]= {
		{0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 1, 0, 0}, 
		{0, 0, 1, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 1, 0, 1, 0, 0}, 
		{0, 0, 1, 0, 0, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 1, 1, 0}, 
	};
	
	int count_coins()
	{
		int i,j;
		int counter=0;
		
		for(i=0; i<SIZE; i++)
		{
			for(j=0; j<SIZE; j++)
			{
				if(board[i][j]==1)
				counter++;
			}
		}
		return counter;
	}
	
	int distance(int fromx, int fromy, int tox, int toy)
	{
		return (tox-fromx)+(toy-fromy);
	}
	
	int find_closest(int *x, int *y)
	{
		int i,j;
		int closest_distance= SIZE*2;
		int closest_x=SIZE-1, closest_y=SIZE-1;
		int temp;
		
		for(i=*x; i<SIZE; i++)
		{
			for(j=*y; j<SIZE; j++)
			{
				if(board[i][j]==1)
				{
					temp=distance(*x,*y,i,j);
					if(temp<closest_distance)
					{
						closest_x=i;
						closest_y=j;
						closest_distance=temp;
					}
				}
			}
		}
		*x=closest_x;
		*y=closest_y;
		return closest_distance;
	}

int main(int argc, char *argv[]) {
	
	int robot;
	int robot_x, robot_y;
	int coin_count=count_coins();
	
	while(coin_count>0)
	{
		robot++;
		robot_x=0;
		robot_y=0;
		
		printf("\nrobot %d starts[%d][%d]",robot,robot_x,robot_y);
		
		while(robot_x<(SIZE-1)||robot_y<(SIZE-1))
		{
			find_closest(&robot_x, &robot_y);
			printf("\nrobot %d in [%d][%d]",robot,robot_x,robot_y);
			
			if(board[robot_x][robot_y]==1)
			{
				printf("\nrobot %d collected the coin in [%d][%d]",robot,robot_x,robot_y);
				board[robot_x][robot_y]=0;
				coin_count--;
			}	
		}
		printf("\nrobot %d finish [%d][%d]",robot,robot_x,robot_y);

		
	}
	printf("\nusing %d robots",robot);
	
	
	
	
	return 0;
}
