#pragma once
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

//typedef struct {
//	int degree;		// 다항식의 차수를 저장할 변수
//	float coef[MAX_DEGREE];	// 다항식의 각 향의 계수를 저장할 1차원 배열
//}polynomial;

polynomial addPoly(polynomial a, polynomial b);

void printPoly(polynomial c);

typedef struct {
	int degree;			// 차수
	int coefficient[MAX_DEGREE];	// 계수
}polynomial;
