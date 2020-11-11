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

	QInsert( 10 );
	QInsert( 20 );
	QInsert( 30 );
	QInsert( 40 );
	QInsert( 50 );
	QInsert( 60 );

	printf("%d\n", QDelete());
	printf("%d\n", QDelete());
	printf("%d\n", QDelete());
	printf("%d\n", QDelete());
	printf("%d\n", QDelete());
	printf("%d\n", QDelete());
}
