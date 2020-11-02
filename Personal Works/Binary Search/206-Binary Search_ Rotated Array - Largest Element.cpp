/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	Solution Approach:
	----------------------------------------------------------------------------------
	Finding smallest element and largest element form a rotated array is almost same.
	For smallest element,
		out ITEM value was the last element of the array.
	But here we have to work with the first element of the array considering it our 
	ITEM value.
	
	You may understand the difference between these two functions by comparing them.
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_RotatedArray_FindLargestElement( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int ITEM = DATA[LB], largestElement = ITEM;

	while( BEG <= END )
	{
		if( DATA[MID] >= ITEM ) 
		{
			BEG = MID + 1;
			if( DATA[MID] > largestElement ) 
			{
				largestElement = DATA[MID];
			}
		}
		else
		{
			END = MID - 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return largestElement;
}

int main()
{
	int ara[] = { 2, 3, 6, 7, 9, 15, 19 };
	int lowerBound = 0;
	int upperBound = 6;

	int largestElement = BinarySearch_RotatedArray_FindLargestElement( ara, lowerBound, upperBound );
	std::cout << largestElement << endl;

	return 0;
}

//ALHAMDULILLAH
