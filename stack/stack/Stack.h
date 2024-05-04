#pragma once
#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE];
int isStackEmpty(void);
int isStackFull(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);
element evalPostfix(char* exp);