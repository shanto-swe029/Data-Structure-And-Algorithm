/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 005            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Binary Search:											    |
        | 1. Search an element                                          |
        | 2. Print all steps of searching                               |
        | 3. Print the total number of setps                            |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
	int DATA[13] = { 11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99 };
	int item = 85, location, total_steps = 0;
	int begin = 0, end = 12, mid = ( int ) ( begin + end ) / 2;
	while( ( begin <= end ) && ( DATA[mid] != item ) ) {
		// printing each steps
		printf("Step-%d\n", ++total_steps);
		printf("Begin = %d\n", begin);
		printf("End = %d\n", end);
		printf("Mid = %d\n\n", mid);

		if( item < DATA[mid] ) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
		mid = ( int ) ( begin + end ) /2;
	}
	// printing last step when needed
	if( begin <= end ) {
		printf("Step-%d\n", ++total_steps);
		printf("Begin = %d\n", begin);
		printf("End = %d\n", end);
		printf("Mid = %d\n\n", mid);
	}

	// printing the number of steps
	printf("Total Steps : %d\n\n", total_steps);

	if ( DATA[mid] == item ) {
		location = mid;
		printf("%d is found at index %d\n", item, location);
	}
	else {
		location = -1;
		printf("%d not found.\n", item);
	}
	return 0;
}
