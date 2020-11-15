/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 005            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Binary Search:                                                |
        | 1. Search an element                                          |
        | 2. Print all steps of searching                               |
        | 3. Print the total number of setps                            |
        -----------------------------------------------------------------
*/
#include <stdio.h>

int BinarySearch ( int DATA[], int LB, int UB, int ITEM )
{
	int BEG = LB, END = UB, MID, total_steps = 0;
	
	while( BEG <= END ) {
		MID = ( int ) ( BEG + END ) / 2;
		
		// printing each steps
		printf("Step-%d\n", ++total_steps);
		printf("Begin = %d\n", BEG);
		printf("End = %d\n", END);
		printf("Mid = %d\n\n", MID);

		if ( ITEM < DATA[MID] ) {
			END  = MID - 1;
		}
		else if ( ITEM > DATA[MID] ) {
			BEG = MID + 1;
		}
		else {
			// printing last step when needed
			if( BEG <= END ) {
				printf("Step-%d\n", ++total_steps);
				printf("Begin = %d\n", BEG);
				printf("End = %d\n", END);
				printf("Mid = %d\n\n", MID);
			}

			// printing the number of steps
			printf("Total Steps : %d\n\n", total_steps);
			return MID;
		}
	}
	// printing last step when needed
	if( BEG <= END ) {
		printf("Step-%d\n", ++total_steps);
		printf("Begin = %d\n", BEG);
		printf("End = %d\n", END);
		printf("Mid = %d\n\n", MID);
	}

	// printing the number of steps
	printf("Total Steps : %d\n\n", total_steps);
	return -1;
}

int main()
{
    int ara[] = { 11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99 };
    int item = 88;
    int lowerBound = 0;
    int upperBound = 12;
    int index = BinarySearch( ara, lowerBound, upperBound, item );

    if( index == -1 ) {
        printf("Item Not Found\n");
    } else {
        printf("%d is found at index %d\n", item, index);
    }

     return 0;
}

//ALHAMDULILLAH
