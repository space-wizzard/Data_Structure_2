//#include <stdio.h>

//void Count(int *num) {
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", num[i]);
//	}
//	//int size = sizeof(num) / sizeof(int);
//	// �� �Ű������� �迭�� �޸� �ּҸ� ���� �ִ� �����ͷ�, �迭�� ũ�⸦ ���޹��� ���Ѵ�.
//	// �迭�� �Ű������� ���޹��� �� �迭�� ũ�⸦ �������� ���ϰ�, ���� �����ؾ� �Ѵ�.
//}
//
//int main() {
//	int num[10] = { 0,1,2,3,4,5 };
//	Count(num);
//	
//}


//int main() {
//
//    int arr[3][2] = {
//            {11, 22},
//            {33, 44},
//            {55, 66},
//    };
//
//    int(*pointer)[2]; // ���� 2�� �ϴ� 2���� �迭 ������ �ϳ� ����
//
//    pointer = arr;
//
//    return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int row, col;
//    printf("��� ���� ������ �Է��ϼ���:");
//    scanf("%d %d", &row, &col);
//
//    // 2���� �迭�� �������� �Ҵ��ϰ� �ʱ�ȭ
//    int** double_matrix = (int**)malloc(row * sizeof(int*));
//    for (int i = 0; i < row; i++) {
//        double_matrix[i] = (int*)malloc(col * sizeof(int));
//        for (int j = 0; j < col; j++) {
//            // ���⿡�� ������ �ʱ�ȭ�� �����մϴ�.
//            double_matrix[i][j] = i * col + j; // ���÷� �� ��ҿ� �Ϸù�ȣ�� �Ҵ�
//        }
//    }
//
//    // �Ҵ�� �迭�� ����ϰų� ��� ���� �۾��� ������ �� �ֽ��ϴ�.
//    // ���÷� �迭 ���
//    printf("2���� �迭:\n");
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            printf("%d ", double_matrix[i][j]);
//        }
//        printf("\n");
//    }
//
//    // �������� �Ҵ�� �޸𸮸� �����մϴ�.
//    for (int i = 0; i < row; i++) {
//        free(double_matrix[i]);
//    }
//    free(double_matrix);
//
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef;
    struct node* next;
} polynomial;

typedef struct {
    polynomial* head;
} polynomial_h;


int* PrintNode(polynomial* a);


void CreateNode(int coefficient, int degree, polynomial_h* top) {

    int in_coef;
    polynomial* newnode = malloc(sizeof(polynomial));
    if (newnode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newnode->coef = coefficient;
    newnode->next = NULL;
    newnode->next = top->head;
    top->head = newnode;
    if (degree == 0)
        return;
    if (coefficient == 0)
        in_coef = 0;
    else
        scanf("%d", &in_coef);
    CreateNode(in_coef, degree - 1, top);

}

void InsertNodeLast(int loop, polynomial* node) {
    if (loop == 0)
        return;
    polynomial* curr = node;
    polynomial* newnode = malloc(sizeof(polynomial));
    newnode->coef = 0;
    newnode->next = NULL;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newnode;
    printf("dmdfknewiag\n");
    InsertNodeLast(loop - 1, curr->next);

}

void addPoly(polynomial_h* a, polynomial_h* b, int a_degree_count, int b_degree_count) {
    int diff_index = abs(a_degree_count - b_degree_count);
    int idx = 0;
    // a ���� ������ ū ���
    if (a_degree_count > b_degree_count) {
        InsertNodeLast(diff_index, b->head);
        idx = a_degree_count;
    }

    //b ���� ������ ū ���
    else {
        InsertNodeLast(diff_index, a->head);
        idx = b_degree_count;
    }

    polynomial* a_curr = a->head;
    polynomial* b_curr = b->head;
    int* a_arr = PrintNode(a_curr);
    int* b_arr = PrintNode(b_curr);
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", a_arr[i], b_arr[i]);
        printf("%dx^%d+", a_arr[i] + b_arr[i], idx - i);
        a_curr = a_curr->next;
        b_curr = b_curr->next;
    }
}

int* PrintNode(polynomial* a) {
    polynomial* curr = a;
    int count = 1;
    printf("b�ȳ����� �״´�");
    while (curr != NULL) {
        printf("node data");
        printf("%d\n", curr->coef);
        curr = curr->next;

        count++;
    }

    curr = a;
    int* arr = calloc(count, sizeof(int));
    for (int i = 1; i <= count; i++) {
        arr[count - i] = curr->coef;
        printf("%d\n", arr[count - i]);
        curr = curr->next;
    }
    printf("\n");
    return arr;
}

void FreeNode(polynomial* node) {
    polynomial* curr = node;
    polynomial* temp = NULL;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    int a_degree, b_degree;
    printf("Degree of A? ");
    scanf("%d", &a_degree);
    printf("Degree of B? ");
    scanf("%d", &b_degree);

    polynomial_h* A = malloc(sizeof(polynomial));
    A->head = NULL;
    polynomial_h* B = malloc(sizeof(polynomial));
    B->head = NULL;

    printf("Enter coefficients of A: ");
    int coef;
    scanf("%d", &coef);
    CreateNode(coef, a_degree, A);

    printf("Enter coefficients of B: ");
    scanf("%d", &coef);
    CreateNode(coef, b_degree, B);

    addPoly(A, B, a_degree, b_degree);
    //Free memory
    FreeNode(A->head);
    FreeNode(B->head);

    return 0;
}
