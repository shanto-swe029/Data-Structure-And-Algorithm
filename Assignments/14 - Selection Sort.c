/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 014            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Selection Sort of an array                                    |
        -----------------------------------------------------------------
	
	   Complexity :
        -----------------------------------------------------------------
        | Worst Case Complexity   : n * (n - 1) / 2 = O(n^2)            |
	| Average Case Complexity : n * (n - 1) / 2 = O(n^2)            |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int ara[10]     = {1, 6, 3, 8, 4, 6, 8, 3, 9, 1};
int araCopy[10] = {1, 6, 3, 8, 4, 6, 8, 3, 9, 1};

void printArray ( int n )
{
	for( int i = 0; i < n; i++ )
	{
		printf("%d ", ara[i] );
	}
	printf( "\n\n" );
}

int MIN( int k, int n, int min )
{
	int  loc = k;
	for( int j = k + 1; j < n; j++ )
	{
		if( min > ara[j] )
		{
			min = ara[j];
			loc = j;
		}
	}

	return loc;
}

void SelectionSort_NonDecreasing ( int n )
{
	int stepNumber = 0;

	for( int k = 0; k < n - 1; k++ )
	{
		int loc = MIN( k, n, ara[k] );

		//Interchanging
		int temp = ara[k];
		ara[k] = ara[loc];
		ara[loc] = temp;

		if( loc == k )
		{
			printf( "Step %d : ", ++stepNumber );
			printf( "Nothing Swapped ( %d is in the correct place )\n", ara[loc] );
			printArray( n );
		}
		else 
		{
			printf( "Step %d : ", ++stepNumber );
			printf( "%d and %d are swapped\n", ara[k], ara[loc] );
			printArray( n );
		}
	}

	return;
}

void printArray2 ( int n )
{
	for( int i = 0; i < n; i++ )
	{
		printf("%d ", araCopy[i] );
	}
	printf( "\n\n" );
}

int MAX( int k, int n, int max )
{
	int  loc = k;
	for( int j = k + 1; j < n; j++ )
	{
		if( max < araCopy[j] )
		{
			max = araCopy[j];
			loc = j;
		}
	}

	return loc;
}

void SelectionSort_NonIncreasing ( int n )
{
	int stepNumber = 0;

	for( int k = 0; k < n - 1; k++ )
	{
		int loc = MAX( k, n, araCopy[k] );

		//Interchanging
		int temp = araCopy[k];
		araCopy[k] = araCopy[loc];
		araCopy[loc] = temp;

		if( loc == k )
		{
			printf( "Step %d : ", ++stepNumber );
			printf( "Nothing Swapped ( %d is in the correct place )\n", araCopy[loc] );
			printArray2( n );
		}
		else 
		{
			printf( "Step %d : ", ++stepNumber );
			printf( "%d and %d are swapped\n", araCopy[k], araCopy[loc] );
			printArray2( n );
		}
	}

	return;
}

int main()
{
	int n = 10;

	SelectionSort_NonDecreasing( n );

	printf("Non-Decreasing Order: \n");
	for( int i = 0; i < n; i++ )
	{
		printf("%d ", ara[i]);
	}
	printf("\n");


	printf("\n-----------------------\n\n");


	SelectionSort_NonIncreasing( n );

	printf("Non-Increasing Order: \n");
	for( int i = 0; i < n; i++ )
	{
		printf("%d ", araCopy[i]);
	}
	printf("\n");
}
