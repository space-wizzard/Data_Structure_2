#pragma once
typedef struct {
	int row;
	int col;
	int value;
}term;

void PrintMatrix(term target[]);
void smTranspose(term a[], term b[]);