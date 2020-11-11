/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 010            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Recursion                                                     |
        | 1. Factorial Calculation                                      |
        -----------------------------------------------------------------
*/

#include <stdio.h>

long long FACTORIAL( long long n )
{
    if( n == 0 ) return 1;
    if( n < 0 ) return -1;      // impossible
    return ( n * FACTORIAL( n - 1) );
}

int main()
{
    long long n;        // n <= 20
    scanf( "%lld", &n );
    printf( "%lld\n", FACTORIAL( n ) );

	return 0;
}
