#include <stdio.h>

void train_print(int, int, int, int);

void train_print(int w, int c, int z, int m) {
	//�ܺ� 1
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
	//����
	printf("#");
	for (int i = 1; i <= w-2; i++) { //�ù�
		if (i == w - c) {
			printf("C");
		}
		else if (i == w - z) { // ����
			printf("Z");
		}
		else if (i == w - m) {
			printf("M");
		}
		else {
			printf(" ");
		}
	}
	printf("#");
	printf("\n");
	// �ܺ� 2
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
}


int main(void) {

}