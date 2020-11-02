/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 006            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Stack Implementation:                                         |
        | 1. push()                                                     |
        | 2. pop()                                                      |
        | 3. top                                                        |
        -----------------------------------------------------------------
*/

#include <stdio.h>

typedef struct {
private:
	int ara[100];

public:
	int push( int item ) {
		if( top == 100 ) return 0;
		top++;
		ara[top] = item;
		return 1;
	}
	int pop() {
		if( top == 0 ) return 0;
		top--;
		return 1;
	}
	int top = 0;
} stack;

int main()
{
	stack myStack;
	myStack.push(10);
	myStack.push(20);
	myStack.push(30);
	printf("%d\n", myStack.top);
	myStack.pop();
	printf("%d\n", myStack.top);
}
