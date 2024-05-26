#include <stdio.h>
#include <stdlib.h>

void train_print(int, int, int, int);

void citizen_move(int[2], int, int);

void madongseok_move(int[4]);

void zombie_move(int, int, int[2], int[4]);

void train_print(int w, int c, int z, int m) {
	//train 1
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
	//train 2
	printf("#");
	for (int i = 1; i <= w-2; i++) { //½Ã¹Î
		if (i == w - c) {
			printf("C");
		}
		else if (i == w - z) { // Á»ºñ
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
	// train 3
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
}

void  citizen_move(int c[2], int cr, int p) {
	cr = rand() % 100 + 1;
	if (cr <= 100 - p) {
		c[0] += 1;
		if (c[1] < 5) {
			c[1] += 1;
		}
	}
	else {
		if (c[1] > 1) {
			c[1] -= 1;
		}
	}
}

void madongseok_move(int m[4]) {
	printf("madongseok move(0:stay, 1:left>> ");
	scanf_s("%d", &m[2]);
	if (m[2] == 0) {
		if (m[1] > 1) {
			m[1] -= 1;
		}
	}
	else {
		m[0] += 1;
		if (m[2] < 5) {
			m[1] += 1;
		}
	}
}

void zombie_move(int z, int turn, int c[2], int m[4]) {
	if (turn % 2 == 0) {
		if (m[4] != 2) {
			if (c[1] > m[1]) {
				z += 1;
			}
			else {
				z -= 1;
			}
		}

	}
}


int main(void) {
	int w, ms, p, z = 3, cr = 1, turn = 1;
	int c[2] = { 6, 1 }; //where, agroo
	int m[4] = { 2, 1, 0, 0};//where, agroo, doing, pull

	printf("train length(15 ~ 50)>> ");
	scanf_s("%d", &w);
	printf("madongseok stamina(0~5)>> ");
	scanf_s("%d", &ms);
	printf("prercentile robability 'p' (10~90)>> ");
	scanf_s("%d", &p);

	//befor start
	train_print(w, c[0], z, m[0]);
	while (1) {
		printf("\n");
		train_print(w, c[0], z, m[0]);

	}

}