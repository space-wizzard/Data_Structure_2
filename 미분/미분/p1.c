#include <stdio.h>
#include <stdlib.h>

void Print_Func(int n,double**cha,char**oper) {
	for (int i = n; i >= 0; i--) {
		//�����
		if (i == 0) {
			if (*cha[i] > 0) {
				printf("+%f", *cha[i]);
				oper[i] = "+";
			}
			else {
				printf("%f", *cha[i]);
				oper[i] = "-";
			}


		}
		// �� ��
		else {
			// ����� ��
			if (*cha[i] > 0) {
				printf("+%.1fx^%d", *cha[i], i);
				oper[i] = "+";
			}

			// ������ ��
			else {
				printf("%.1fx^%d", *cha[i], i);
				oper[i] = "-";
			}
		}
	}
}

int main() {
	int n;
	printf("�� �� ���׽��Դϱ�?");
	scanf("%d", &n);
	double* cha = calloc(n+1, sizeof(double));
	char* oper = calloc(n, sizeof(char));
	for (int i = n; i >= 0; i--) {
		printf("%d������ ���:", i);
		scanf("%lf", &cha[i]);
	}
	printf("\nf(x)=");
	Print_Func(n,&cha,&oper);
	

	for (int i = n; i > 0; i--) {
		if (i == 1)
			break;
		else
			cha[i] = cha[i] * i;
	}
		
	

	

	

}