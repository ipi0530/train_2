#include <stdio.h>

void train_print(int, int, int, int);

void train_print(int w, int c, int z, int m) {
	//외부 1
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
	//내부
	printf("#");
	for (int i = 1; i <= w-2; i++) { //시민
		if (i == w - c) {
			printf("C");
		}
		else if (i == w - z) { // 좀비
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
	// 외부 2
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
}


int main(void) {

}