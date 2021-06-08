/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 015            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Merge Sort of an array                                        |
        -----------------------------------------------------------------
	
	   Complexity :
        -----------------------------------------------------------------
        | Worst Case Complexity   : O( n * log(n) )                     |
		| Average Case Complexity : O( n * log(n) )                     |
        -----------------------------------------------------------------
*/

#include <stdio.h>

void printArray(int ara[], int l, int r)
{
    int i;
	for (i = l; i <= r; i++) printf("%d ",ara[i]);
	printf("\n");
}

void merge_NonDecreasing( int ara[], int l, int m, int r )
{
	printf("[%d, %d] = ", l+1, m+1);
    printArray(ara, l, m);
    printf("[%d, %d] = ", m+2, r+1);
    printArray(ara, m+1, r);

    int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// create temp-arrays
	int L[n1], R[n2];

	// copy data to temp-arrays
	for( i = 0; i < n1; i++ )
	{
		L[i] = ara[l + i];
	}
	for( j = 0; j < n2; j++ )
	{
		R[j] = ara[m + j + 1];
	}

	// merge the temp-arrays back into main array
	i = 0;  //  initial index of L[]
	j = 0;  //  initial index of R[]
	k = l;  //  initial index of ara[]
	while( i < n1 && j < n2 )
	{
		if( L[i] <= R[j] )
		{
			ara[k] = L[i];
			i++;
		}
		else 
		{
			ara[k] = R[j];
			j++;
		}
		k++;
	}

	// copy remaining part of L[]
	while( i < n1 )
	{
		ara[k] = L[i];
		i++;
		k++;
	}

	// copy remaining patr of R[]
	while( j < n2 )
	{
		ara[k] = R[j];
		j++;
		k++;
	}

	printf("After Merging [%d , %d] = ", l+1, r+1);
	printArray(ara, l, r);
	printf("\n");
}

void mergeSort_NonDecreasing ( int ara[], int l, int r )
{
	if( l < r )
	{
		int mid = ( l + r ) / 2;

		mergeSort_NonDecreasing( ara, l, mid );
		mergeSort_NonDecreasing( ara, mid + 1, r );

		merge_NonDecreasing( ara, l, mid, r );
	}
}

int main()
{
	int ara[] = {1, 6, 3, 8, 4, 6, 8, 3, 9, 1};
	int sz = sizeof( ara ) / sizeof( ara[0] );

	mergeSort_NonDecreasing( ara, 0, sz - 1 );

	printf("Non-Decreasing Order: \n");
	for( int i = 0; i < sz; i++ )
	{
		printf( "%d ", ara[i] );
	} printf("\n");

	printf("\n-----------------------------------\n");
}
