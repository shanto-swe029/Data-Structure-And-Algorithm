/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	What is Upper Bound?
	- The Upper Bound of X is the left most index in an array
	that has a value greater than X.
	
	For example:
	Consider ara[] = { 10, 20, 20, 20, 30, 30, 40, 50 };
	Here,
		Upper Bound of 20 = 4 ( Index of first 30 )
		Upper Bound of 30 = 6 ( Indec of 40 )
		Upper Bound of 50 = 8
		Upper Bound of 55 = 8 ( 55 does not exist in the array and is greater than the last element )
		Upper Bound of 25 = 4 ( Index of first 30 )
		Upper Bound of  5 = 1 ( Index of 10 )
	
	By using customized Binary Search Algorithm, we can find out the upper bound of an item. The code is given below.
	You can try nd unserdtand what's happening here. If I ever can make a good explanation, I'll provide it here.
*/

#include <bits/stdc++.h>
using namespace std;

/*
	Function Parameter Introduction
	----------------------------------------------------------------------
	int DATA[] =   the dataset given to us.
	int LB     =   the lower bound of the range we want to search for.
	int UB     =   the upper bound of the range we want to search for.
	int ITEM   =   the item which we are searching.
*/

long long BinarySearch_UpperBound(long long DATA[], int LB, int UB, long long ITEM)
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int LOC = UB + 1;

	while( BEG <= END ) {
		if( DATA[MID] > ITEM ) {
			END = MID - 1;
			if( MID < LOC ) {
				LOC = MID;
			}
		} 
		else {
			BEG = MID + 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	
	return LOC;
}

int main()
{
	int n, item;
	std::cin >> n;

	int ara[n];
	for( int i = 0; i < n; i++ ) {
		std::cin >> ara[i];
	}

	std::cin >> item;
	int UpperBound = BinarySearch_UpperBound( ara, 0, n-1, item );
	std::cout << "Upper bound of " << item << " = " <<UpperBound << endl;
}

// ALHAMDULILLAH
