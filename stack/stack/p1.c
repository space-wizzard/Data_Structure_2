
#include "Stack.h"

int main() {
	/*element item;
	printStack();
	push(1);	printStack();
	push(2);	printStack();
	push(3);	printStack();

	item = peek();	printStack();
	printf("peek =>%d", item);

	item = pop();	printStack();
	printf("\t pop => %d", item);

	item = pop();	printStack();
	printf("\t pop => %d", item);
	item = pop();	printStack();
	printf("\t pop => %d\n", item);*/
	int result;
	char* express = "35*62/-";
	printf("후위 표기식:%s", express);

	result = evalPostfix(express);
	printf("\n\n연산 결과:%d\n", result);

}