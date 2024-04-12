#include <stdio.h>
#include <stdlib.h>
#include "addPoly.h"

int main() {
	polynomial A;
	TermType B;
	B.coef = 2;
	B.expo = 1;
	A.coef[3] = B;
}