/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	Problem Statement:
	-----------------------------------------------------------------------------------------
	Suppose you had a sorted array like this - { 2, 3, 6, 7, 9, 15, 19 }.
	The first two element were cut from the array and pasted in the last.
	So the new array becomes like this - { 6, 7, 9, 15, 19, 2, 3 }.
	This new resulting array is called a Rotated Array. If we had cut first 0
	element of all elements, the resulting array would stay the same as it was before.
	
	Now, you are given a rotated array. Find the smallest element of the array.
	
	
	Solution Approach:
	-----------------------------------------------------------------------------------------
	We can easily solve this problem using Linear Search Algorithm. But instead we can solve
	it efficiently by using customized Binary Search Algorithm. But for using binary search, 
	we need to have a ITEM value. What would be the ITEM value for this problem?
	Well, the ITEM value will be the last element of the array. Comparing with the last element 
	we can easily run binary search over the array to get our desired outcome.
	The code is given below. Once I make a good explanation of this algorithm, I'll provide it
	here.
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_RotatedArray_FindSmallestElement( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int ITEM = DATA[UB], smallestElement = ITEM;

	while( BEG <= END )
	{
		if( DATA[MID] > ITEM ) 
		{
			BEG = MID + 1;
		}
		else
		{
			END = MID - 1;
			if( DATA[MID] < smallestElement ) 
			{
				smallestElement = DATA[MID];
			}
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return smallestElement;
}


int main()
{
	int ara[] = { 6, 7, 9, 15, 19, 2, 3 };
	int lowerBound = 0;
	int upperBound = 7;

	int smallestElement = BinarySearch_RotatedArray_FindSmallestElement( ara, lowerBound, upperBound );
	std::cout << smallestElement << endl;

    return 0;
}

//ALHAMDULILLAH
