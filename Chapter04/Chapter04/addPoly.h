#pragma once
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

//typedef struct {
//	int degree;		// ���׽��� ������ ������ ����
//	float coef[MAX_DEGREE];	// ���׽��� �� ���� ����� ������ 1���� �迭
//}polynomial;

polynomial addPoly(polynomial a, polynomial b);

void printPoly(polynomial c);

typedef struct {
	int degree;			// ����
	int coefficient[MAX_DEGREE];	// ���
}polynomial;
