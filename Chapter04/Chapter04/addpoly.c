#include "addPoly.h"
#include <stdlib.h>
polynomial addPoly(polynomial a, polynomial b) {
	polynomial c = { 0, };
	int a_degree = a.degree;
	int b_degree = b.degree;
	int diff_index = abs(a_degree - b_degree);
	int idx = 0;
	c.degree= MAX(a_degree, b_degree);
	if (c.degree == a_degree) {
		idx = sizeof(b.coefficient) / sizeof(int);
		while (b.coefficient[idx] != NULL) {
			b.coefficient[idx+diff_index] = b.coefficient[idx];
			idx++;
		}
		for (int i = 0; i < diff_index; i++) {
			b.coefficient[i] = 0;
		}
	}
	else {
		idx = sizeof(a.coefficient) / sizeof(int);
		while (a.coefficient[idx] != NULL) {
			a.coefficient[idx+diff_index] = a.coefficient[idx];
			idx++;
		}
		for (int i = 0; i < diff_index; i++) {
			a.coefficient[i] = 0;
		}
	}

	for (int i = 0; i < sizeof(a.coefficient) / sizeof(int); i++) {
		c.coefficient[i] = a.coefficient[i] + b.coefficient[i];
	}
	return c;

}

void printPoly(polynomial c) {
	int degree = c.degree;
	for (int i = 0; i <= degree; i++) {
		if (i==0)
			printf("C(x)= %dx^%d +", c.coefficient[i], degree - i);
		else if (i!=degree)
			printf("%dx^%d +", c.coefficient[i], degree - i);
		else
			printf("%dx^%d", c.coefficient[i], degree - i);
	}
}