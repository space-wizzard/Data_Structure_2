#include "Queue.h"

int main() {
	QueueType* Q1 = createQueue();
	element data;
	enQueue(Q1, 'A');
	printQ(Q1);
	enQueue(Q1, 'B');
	printQ(Q1);
	enQueue(Q1, 'C');
	printQ(Q1);
	data=Dequeue(Q1);
	printf("삭제 데이터:%c\n", data);
	data = Dequeue(Q1);
	printf("삭제 데이터:%c\n", data);
	data = Dequeue(Q1);
	printf("삭제 데이터:%c\n", data);
	enQueue(Q1, 'E');
	printQ(Q1);
	enQueue(Q1, 'F');
	printQ(Q1);


}