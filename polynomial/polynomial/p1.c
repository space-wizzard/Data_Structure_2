#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a>b)?a:b)
//#define MAX_DEGREE 10
typedef struct node {
	int coef;			// 계수(data)
	struct node* next;
}polynomial;

typedef struct {
	polynomial* head;
}polynomial_h;

void addPoly(polynomial* a, polynomial* b,int a_degree_count,int b_degree_count) {
	//polynomial* c = malloc(sizeof(polynomial));

	int diff_index = abs(a_degree_count - b_degree_count);
	int idx = 0;

	// a 식의 차수가 큰 경우
	if (a_degree_count >b_degree_count) {

		while (diff_index!=0) {
			// 두 식의 차수 차이 때문에 다항식 덧셈이 안된다.
			// 차수 차이만큼 뒤로 미뤄줘야 하는데 차수 차이가 크면 데이터가 겹친다. -> LinkedList 사용하기 
			InsertLastNode(b);
			diff_index--;
		}

	}
	// b 식의 차수가 큰 경우
	else {
		while (diff_index != 0) {
			InsertLastNode(a);
			diff_index--;
		}
		
	}
	AddNode(a, b);

}

void AddNode(polynomial* a, polynomial* b) {
	polynomial* a_curr = a;
	polynomial* b_curr = b;
	int ans[10] = { 0, };
	int idx = 0;
	while (a_curr->next != NULL) {
		a_curr = a_curr->next;
		b_curr = b_curr->next;
		ans[idx] = a_curr->coef + b_curr->coef;
		idx++;
	}
	printPoly(ans);
}

void printPoly(int ans[]) {
	int degree = sizeof(ans);
	int idx_count[sizeof(ans)] = {0,};
	for (int i = sizeof(ans); i >= 0; i--) {
		if (i == 0)
			printf("C(x)= %dx^%d +", idx_count[i], degree);
		else if (i != degree)
			printf("%dx^%d +", idx_count[i], degree);
		else
			printf("%dx^%d", idx_count[i], degree);
	}
}

void InsertLastNode(polynomial* node) {
	polynomial* temp = node;
	polynomial* newnode = malloc(sizeof(polynomial));
	newnode->next = NULL;
	scanf("%d", &newnode->coef);
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
}
polynomial_h* CreateLinkedList() {
	polynomial_h* newnode = malloc(sizeof(polynomial));
	if (newnode == NULL)
		return NULL;
	else {
		newnode->head = NULL;
		return newnode;
	}
}

polynomial* CreateNode(int n, polynomial_h* top) {
	const int initial = n;
	polynomial* newnode = malloc(sizeof(polynomial));
	scanf("%d", &newnode->coef);
	if (n == 1) {
		newnode->next = NULL;
		return top;
	}
	newnode->next = top->head;
	top->head = newnode;
	polynomial* node = CreateNode(n - 1, top);
	return node;
		

	
	
}


int main() {
	int a_degree, b_degree;
	printf("Coefficient of A?");
	scanf("%d", &a_degree);
	printf("Coefficient of B?");
	scanf("%d", &b_degree);
	polynomial_h* head = CreateLinkedList();
	polynomial* a = CreateNode(a_degree,head);
	polynomial* b = CreateNode(b_degree,head);
	
	//polynomial* c=CreateNode(a_degree,head);
	addPoly(a, b,a_degree,b_degree);
}



/*idx = sizeof((*a)->coefficient);
		printf("%d\n", sizeof((*b)->coefficient));
		while (idx!=0) {
			(*a)->coefficient[idx + diff_index] = (*a)->coefficient[idx];
			idx--;
		}
		for (int i = 0; i < diff_index; i++) {
			(*a)->coefficient[i] = 0;
		}*/