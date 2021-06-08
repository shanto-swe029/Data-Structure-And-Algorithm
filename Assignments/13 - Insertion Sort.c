/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 013            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Insertion Sort of an array                                    |
        -----------------------------------------------------------------
	
	   Complexity :
        -----------------------------------------------------------------
        | Worst Case Complexity   : n * (n - 1) / 2 = O(n^2)            |
	| Average Case Complexity : n * (n - 1) / 4 = O(n^2)            |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int ara[11]     = {-100000000, 1, 6, 3, 8, 4, 6, 8, 3, 9, 1};
int araCopy[11] = { 100000000, 1, 6, 3, 8, 4, 6, 8, 3, 9, 1};

void printStep ( int stepNumber )
{
	printf( "Step %2d: ", stepNumber );
	for( int i = 1; i <= stepNumber; i++ )
	{
		printf( "%d ", ara[i] );
	}
	printf( "\n" );
}

void printStep2 ( int stepNumber )
{
	printf( "Step %2d: ", stepNumber );
	for( int i = 1; i <= stepNumber; i++ )
	{
		printf( "%d ", araCopy[i] );
	}
	printf( "\n" );
}

void InsertionSort_NonDecreasing ( int n )
{
	ara[0] = -100000000;

	printStep( 1 );

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
		printStep( k );
	}

	return;
}

void InsertionSort_NonIncreasing ( int n )
{
	araCopy[0] = 100000000;

	printStep2( 1 );

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

		printStep2( k );
	}

	return;
}

int main()
{
	int n = 10;

	InsertionSort_NonDecreasing( n );

	printf("\nNon-Decreasing Order: \n");
	for( int i = 1; i <= n; i++ )
	{
		printf("%d ", ara[i]);
	}
	printf("\n");


	printf("\n-----------------------\n\n");


	InsertionSort_NonIncreasing( n );

	printf("\nNon-Increasing Order: \n");
	for( int i = 1; i <= n; i++ )
	{
		printf("%d ", araCopy[i]);
	}
	printf("\n");
}
