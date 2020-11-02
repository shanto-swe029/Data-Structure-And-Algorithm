#include <stdio.h>

typedef struct {
private:
	int ara[100];

public:
	int push( int item ) {
		if( top == 100 ) return 0;
		ara[top] = item;
		top++;
		return 1;
	}
	int pop() {
		if( top == 0 ) return 0;
		top--;
		return 1;
	}
	int topValue() {
		return ara[top - 1];
	}
	int isEmpty() {
		return ( top == 0 );
	}
	int top = 0;
} stack;

int main()
{
	stack myStack;			printf("top = %d\n", myStack.top);
  
	myStack.push( 10 );		printf("top = %d\n", myStack.top);
	myStack.push( 20 );		printf("top = %d\n", myStack.top);
	myStack.push( 30 );		printf("top = %d\n", myStack.top);
	myStack.push( 40 );		printf("top = %d\n", myStack.top);
	myStack.push( 50 );		printf("top = %d\n", myStack.top);
	myStack.push( 60 );		printf("top = %d\n", myStack.top);
	myStack.push( 70 );		printf("top = %d\n", myStack.top);
	myStack.push( 80 );		printf("top = %d\n", myStack.top);
	myStack.push( 90 );		printf("top = %d\n", myStack.top);

	while( !myStack.isEmpty() ) {
		printf( "%d ", myStack.topValue() );
		myStack.pop();
	}
	printf("\n");

	printf("top = %d\n", myStack.top);
	
	return 0;
}
