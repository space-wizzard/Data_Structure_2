#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

typedef char element;

typedef struct {
	element stack[STACK_SIZE];
	int rear;
}StackType;

StackType* CreateStack();
int StackEmpty(StackType* S);
int StackFull(StackType* S);
void push(StackType* S, element item);
element pop(StackType* S);
void printStack(StackType* S);

