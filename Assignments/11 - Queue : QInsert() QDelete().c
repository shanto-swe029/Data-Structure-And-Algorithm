/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 011            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Queue:                                                        |
        | 1. QInsert() function                                         |
        | 2. QDelete() function                                         |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int Queue[100000];
int Front = -1;
int Rear = -1;
int maxQueueSize = 0;

int QInsert( int  item )
{
	if( maxQueueSize == 0 ) {
		printf("Overflow\n");
		return 0;
	}
	if( Front == ( Rear + 1 ) % maxQueueSize ) {
		printf("Overflow\n");
		return 0;
	}
	if( Front == -1 && Rear == -1 ) {
		Front++;
		Rear++;
	}
	else {
		Rear++;
		Rear %= maxQueueSize;
	}
	Queue[Rear] = item;
	return 1;
}

int QDelete()
{
	if( Front == -1 && Rear == -1 ) {
		printf("Underflow\n");
		return 0;
	}
	int item = Queue[Front];
	if( Front == Rear ) {
		Front = -1;
		Rear = -1;
	}
	else {
		Front++;
		Front %= maxQueueSize;
	}
	return item;
}

int main()
{
	maxQueueSize = 5;

	QInsert( 'A' );
	QInsert( 'B' );
	QInsert( 'C' );	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);

	QInsert( 'D' );
	QInsert( 'E' );	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);

	QInsert( 'F' );	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);

	QInsert( 'G' );
	QInsert( 'H' );	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);

	QInsert( 'K' );	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);
	printf("%c\n", QDelete());	printf("FRONT: %d\tREAR: %d\n", Front + 1, Rear + 1);

}
