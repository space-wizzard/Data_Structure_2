#include "stack.h"

StackType* CreateStack() {
	StackType* S;
	S = (StackType*)malloc(sizeof(StackType));
	S->rear = -1;
	return S;
}

int StackEmpty(StackType*S) {
	if (S->rear == -1) {
		printf("Stack is Empty\n");
		return 1;
	}
	else return 0;
}

int StackFull(StackType* S) {
	if (S->rear == STACK_SIZE - 1) {
		printf("Stack is Full\n");
		return 1;
	}
	else return 0;
}

void push(StackType* S,element item) {
	if (StackFull(S))
		return;
	else {
		S->rear++;
		S->stack[S->rear] = item;
	}
}

element pop(StackType* S) {
	if (StackEmpty(S))
		return;
	else {
		return S->stack[S->rear--];
	}
}

void printStack(StackType* S) {
	for (int i = 0; i <= S->rear; i++) {
		printf("%3c", S->stack[i]);
	}
	printf("\n");
}