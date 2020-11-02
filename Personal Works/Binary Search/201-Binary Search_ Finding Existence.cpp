/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	                                                               BINARY SEARCH
	----------------------------------------------------------------------------------------------------------------------------------------------------------
	What is Binary Search ?
	- In computer science, binary search, also known as half-interval search, logarithmic search, or binary chop, is a search algorithm that finds the 
	position of a target value within a sorted array.

	How does Binary Search Work?
	- Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated
	and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value
	is found. If the search ends with the remaining half being empty, the target is not in the array.

	Binary search runs in logarithmic time in the worst case, making O(log n) comparisons, where {\displaystyle n}n is the number of elements in the array.
	Binary search is faster than linear search except for small arrays. However, the array must be sorted first to be able to apply binary search. There are 
	specialized data structures designed for fast searching, such as hash tables, that can be searched more efficiently than binary search. However, binary 
	search can be used to solve a wider range of problems, such as finding the next-smallest or next-largest element in the array relative to the target even
	if it is absent from the array.

	There are numerous variations of binary search. In particular, fractional cascading speeds up binary searches for the same value in multiple arrays. 
	Fractional cascading efficiently solves a number of search problems in computational geometry and in numerous other fields. Exponential search extends
	binary search to unbounded lists. The binary search tree and B-tree data structures are based on binary search.
	----------------------------------------------------------------------------------------------------------------------------------------------------------
	                                                              Algorithm
	----------------------------------------------------------------------------------------------------------------------------------------------------------
	Binary search works on sorted arrays. Binary search begins by comparing an element in the middle of the array with the target value. If the target value
	matches the element, its position in the array is returned. If the target value is less than the element, the search continues in the lower half of the
	array. If the target value is greater than the element, the search continues in the upper half of the array. By doing this, the algorithm eliminates the
	half in which the target value cannot lie in each iteration.

	Let A be an array, which has n elements and we want to search for a number T.

	PSEUDOCODE
	----------------------------------------------
	function binary_search(A, n, T) is
		L := 0
		R := n − 1
		while L ≤ R do
			m := floor((L + R) / 2)
			if A[m] < T then
				L := m + 1
			else if A[m] > T then
				R := m − 1
			else:
				return m
			return unsuccessful
	--------------------------------------------
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

int BinarySearch ( int DATA[], int LB, int UB, int ITEM )
{
	int BEG = LB, END = UB, MID;
	
	while( BEG <= END ) {
		MID = ( int ) ( BEG + END ) / 2;
		if ( ITEM < DATA[MID] ) {
			END  = MID - 1;
		}
		else if ( ITEM > DATA[MID] ) {
			BIG = MID + 1;
		}
		else {
			return MID;
		}
	}
	return -1;
}

int main()
{
    int ara[] = { 1, 3, 4, 5, 5, 7, 8, 12, 18 };
    int item = 3;
    int lowerBound = 0;
    int upperBound = 8;
    int index = BinarySearch( ara, lowerBound, upperBound, item );

    if( index == -1 ) {
        printf("Item Not Found\n");
    } else {
        printf("%d is found at index %d\n", item, index);
    }

     return 0;
}

//ALHAMDULILLAH

