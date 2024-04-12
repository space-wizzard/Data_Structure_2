#include <stdio.h>
#include <stdlib.h>
#include "addPoly.h"


int main() {
	polynomial a = { 3,{4,3,5,0} };
	polynomial b = { 4,{3,1,0,2,1} };
	polynomial c = { 0,{0,} };
	c = addPoly(a, b);
	PrintPoly(c);
}