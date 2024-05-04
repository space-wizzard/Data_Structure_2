
#include "Stack.h"

int top = -1;

int isStackEmpty(void) {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isStackFull(void) {
	if (top == STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(element item) {
	if (isStackFull()) {
		printf("\n\n Stack is Full!\n");
		return;
	}
	else
		stack[++top] = item;

}

element pop(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty\n");
		return 0;
	}
	else
		return stack[top--];
}

element peek(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty\n");
		return 0;
	}
	else
		return stack[top];
}

void printStack(void) {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("]");
}

element evalPostfix(char* exp) {
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;



	for (i = 0; i < length; i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
			value = symbol - '0';
			
			push(value);
		}
		else {
			opr2 = pop();
			opr1 = pop();
			switch (symbol) {
			case '+':
				push(opr1 + opr2);
				break;
			case '-':
				push(opr1 - opr2);
				break;
			case '*':
				push(opr1 * opr2);
				break;
			case '/':
				push(opr1 / opr2);
				break;
			}
		}
		return pop();
	}
}