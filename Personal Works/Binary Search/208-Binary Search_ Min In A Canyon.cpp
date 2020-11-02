/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	Problem Statement:
	---------------------------------------------------------------------------------
	Suppose, you have an array. The first part of the array is non-increasing and 
	the final part of the array is non-decreasing. You have to find the minimum
	value of this array.
	For example :
	Let's consider an array like { 5, 4, 3, 2, 1, 3, 5, 7, 9 }.
	The minimum number of this array = 1.
	
	For calrification : size of any of the two parts ( but not both ) can be zero.
	
	
	Solution Approach:
	---------------------------------------------------------------------------------
	Running Binary Search is the most efficient way here. But what will be the ITEM
	value here is the main query.
	Well, in this case, ITEM value is a variable. We have to compare DATA[MID] with
	DATA[MID - 1].
	This is the key to solving this problem. I am throwing the rest understanding of
	this approach on my code. I hope you will get it.
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_MinInACanyon( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int minimumNumber = max( DATA[LB], DATA[UB] );

	while( BEG <= END )
	{
		if( DATA[MID] <= DATA[MID - 1] )
		{
			BEG = MID + 1;
			if( DATA[MID] < minimumNumber )
			{
				minimumNumber = DATA[MID];
			}
		}
		else
		{
			END = MID - 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return minimumNumber;
}

int main()
{
	int ara[] = { 12, 9, 7, 6, 2, 1, 4, 8, 10 };
	int lowerBound = 0;
	int upperBound = 8;

	int minimumNumber = BinarySearch_MinInACanyon( ara, lowerBound, upperBound );
	std::cout << minimumNumber << endl;

    return 0;
}

//ALHAMDULILLAH
