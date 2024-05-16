#include "stack.h"

int main() {
	StackType* S1 = CreateStack();
	element data;
	push(S1, 'A');
	printStack(S1);
	push(S1, 'B');
	printStack(S1);
	push(S1, 'C');
	printStack(S1);
	push(S1, 'D');
	printStack(S1);
	data=pop(S1);
	printf("삭제 데이터:%c\n", data);
	data = pop(S1);
	printf("삭제 데이터:%c\n", data);
	data = pop(S1);
	printf("삭제 데이터:%c\n", data);

}