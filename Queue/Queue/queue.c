#include "Queue.h"

QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isQueueEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("Queue is Empty\n");
		return 1;
	}
	else
		return 0;
}

int isQueueFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("Queue is Full\n");
		return 1;
	}
	else
		return 0;
}

void enQueue(QueueType* Q, element item) {
	if (isQueueFull(Q))
		return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element Dequeue(QueueType* Q) {
	if (isQueueEmpty(Q))
		return;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

element peekQ(QueueType* Q) {
	if (isQueueEmpty(Q))
		return;
	else return Q->queue[Q->front];
}

void printQ(QueueType* Q) {
	for (int i = Q->front+1; i <= Q->rear; i++) {
		printf("%3c", Q->queue[i]);
	}
	printf("\n");
}