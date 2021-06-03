#include <stdio.h>

int ara[11] = {-100000000, 1, 6, 3, 8, 4, 6, 8, 3, 9, 1};
int araCopy[11] = {100000000, 1, 6, 3, 8, 4, 6, 8, 3, 9, 1};

void InsertionSort_NonDecreasing ( int n )
{
	ara[0] = -100000000;

	for ( int k = 2; k <= n; k++ )
	{
		int temp = ara[k];
		int ptr = k - 1;
		while( temp < ara[ptr] )
		{
			ara[ptr + 1] = ara[ptr];
			ptr--;
		}
		ara[ptr + 1] = temp;
	}

	return;
}

void InsertionSort_NonIncreasing ( int n )
{
	araCopy[0] = 100000000;

	for( int k = 2; k <= n; k++ )
	{
		int temp = araCopy[k];
		int ptr = k - 1;
		while( temp > araCopy[ptr] )
		{
			araCopy[ptr + 1] = araCopy[ptr];
			ptr--;
		}
		araCopy[ptr + 1] = temp;
	}

	return;
}

int main()
{
	int n = 10;

	InsertionSort_NonDecreasing( n );

	printf("Non-Decreasing Order: \n");
	for( int i = 1; i <= n; i++ )
	{
		printf("%d ", ara[i]);
	}
	printf("\n");


	printf("\n-----------------------\n\n");


	InsertionSort_NonIncreasing( n );

	printf("Non-Increasing Order: \n");
	for( int i = 1; i <= n; i++ )
	{
		printf("%d ", araCopy[i]);
	}
	printf("\n");
}
