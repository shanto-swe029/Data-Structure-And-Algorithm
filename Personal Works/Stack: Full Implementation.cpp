/*
	                                 STACK : FULL IMPLEMENTATION
	---------------------------------------------------------------------------------------------
	Here is the full implementation of STACK using STRUCTURE in C Programming Language. This is a
	full functional stack structure. You can use it like 'std::stack < int > ' of C++ Programming 
	Language. For using this stack in more data types, you can see my advanced implementation.
	---------------------------------------------------------------------------------------------
*/

#include <stdio.h>

typedef struct {
private:
	int ara[1000000];

public:
	int push( int item ) {
		if( size == 1000000 ) return 0;
		ara[size] = item;
		size++;
		return 1;
	}
	int pop() {
		if( size == 0 ) return 0;
		size--;
		return 1;
	}
	int top() {
		return ara[size - 1];
	}
	int isEmpty() {
		return ( size == 0 );
	}
	int size = 0;
} stack;

int main()
{
	stack myStack;			printf( "size = %d\n", myStack.size );
	myStack.push( 10 );		printf( "size = %d\n", myStack.size );
	myStack.push( 20 );		printf( "size = %d\n", myStack.size );
	myStack.push( 30 );		printf( "size = %d\n", myStack.size );
	myStack.push( 40 );		printf( "size = %d\n", myStack.size );
	myStack.push( 50 );		printf( "size = %d\n", myStack.size );
	myStack.push( 60 );		printf( "size = %d\n", myStack.size );
	myStack.push( 70 );		printf( "size = %d\n", myStack.size );
	myStack.push( 80 );		printf( "size = %d\n", myStack.size );
	myStack.push( 90 );		printf( "size = %d\n", myStack.size );

	while( !myStack.isEmpty() ) {
		printf( "%d ", myStack.top() );
		myStack.pop();
	}
	printf( "\n" );

	printf( "size = %d\n", myStack.size );
}
