/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 006            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Stack:                                                        |
        | 1. push() function                                            |
        | 2. pop() function                                             |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int stack[100000];
int TOP = -1;
int maxStk = 0;

int push( int item )
{
	if( TOP == maxStk - 1 ) {
		printf("Overflow\n");
		return 0;
	}
	TOP++;
	stack[TOP] = item;
	return 1;
}

int pop()
{
	if( TOP == -1 ) {
		printf("Underflow\n");
		return 0;
	}
	TOP--;
	return 1;
}

int main()
{
	maxStk = 5;

	push( 5 ); push( 6 ); push( 7 ); push( 8 ); push( 9 );
	push( 10 );		// overflow

	pop(); pop(); pop(); pop(); pop(); 
	pop();			// underflow
}
