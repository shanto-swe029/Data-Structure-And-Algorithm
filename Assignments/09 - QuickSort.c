/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 009            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | QuickSort                                                     |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int PARTITION( int ara[], int low, int high )
{
	int pivot = ara[high];
	int i = low - 1, j;

	for( j = low; j < high; ++j ) {
		if( ara[j] <= pivot ) {
			i++;
			// SWAP( ara[i], ara[j] )
			if( ara[i] != ara[j] ) {
				ara[i] ^= ara[j];
				ara[j] ^= ara[i];
				ara[i] ^= ara[j];
			}
		}
	}
	// SWAP( ara[i+1], high )
	if( ara[i + 1] != ara[high] ) {
		ara[i + 1] ^= ara[high];
		ara[high]  ^= ara[i + 1];
		ara[i + 1] ^= ara[high];
	}
	return ( i + 1 );
}

void QUICKSORT( int ara[], int low, int high )
{
	if( low < high ) {
		int pi = PARTITION( ara, low, high );
		QUICKSORT( ara, low, pi - 1 );
		QUICKSORT( ara, pi + 1, high );
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int data[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
 	int n = sizeof(data) / sizeof(data[0]);
 	QUICKSORT(data, 0, n - 1);
 	printf("Sorted array in ascending order: \n");
 	for( int i = 0; i < n; i++ ) printf("%d ", data[i]);
}
