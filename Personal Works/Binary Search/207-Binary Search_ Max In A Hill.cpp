/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	Problem Statement:
	-----------------------------------------------------------------------------------
	Suppose, you have an array. First part ( not necessary to be half ) of the array is
	non-decreasing and the final part of the array is non-increasing. 
	For example :	{ 2, 3, 4, 6, 9, 12, 11, 8, 4, 1 }
	The first  part ( 2, 3, 4, 6, 9, 12 ) is non-decreasing and
	The second part ( 11, 8, 4, 1 ) is non-increasing.
	
	For clarification : size of any of the two parts ( but not both ) can be zero.
	
	You have to find the maximum element from this array.
	
	
	Solution Approach:
	-----------------------------------------------------------------------------------
	Running Binary Search is the most efficient way here. But what will be the ITEM
	value here is the main query.
	Well, in this case, ITEM value is a variable. We have to compare DATA[MID] with
	DATA[MID - 1].
	This is the key to solving this problem. I am throwing the rest understanding of
	this approach on my code. I hope you will get it.
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_MaxInAHill( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int maximumNumber = min( DATA[LB], DATA[UB] );

	while( BEG <= END )
	{
		if( DATA[MID] >= DATA[MID - 1] )
		{
			BEG = MID + 1;
			if( DATA[MID] > maximumNumber )
			{
				maximumNumber = DATA[MID];
			}
		}
		else
		{
			END = MID - 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return maximumNumber;
}

int main()
{
	int ara[] = { 2, 3, 4, 6, 9, 12, 11, 8, 4, 1 };
	int lowerBound = 0;
	int upperBound = 9;

	int maximumNumber = BinarySearch_MaxInAHill( ara, lowerBound, upperBound );
	std::cout << maximumNumber << endl;

    return 0;
}

//ALHAMDULILLAH
