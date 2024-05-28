#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool flag_game = true;
int w =0, p = 0, turn = 1, game = 1;
int c = 6, ca = 1, cr = 0, cd = 0;
int z = 3, zat = 0, zd = 0;
int m = 2, ma = 1, ma1 = 0, md = 0, mac = 0,ms = 0, msp = 0, mr = 0;
//ms = chose, msa = present 
// game, 1 = true, 2 = z attack c, 3 == c win, 4 == z attack m
void train_print(int, int, int, int);

//move
void citizen_move(int, int, int, int, int, int, int);

void zombie_move(int, int, int, int, int, int, int);

void madongseok_move(int, int, int, int);

//doing
void citizen_doing(int, int, int, int);

void zombie_doing(int, int, int, int, int, int, int, int, int);

void madongseok_doing(int, int, int, int, int, int, int, int);

//print_move
void citizen_print_move(int, int, int, int);

void madongseok_print_move(int, int, int, int, int, int);

void zombie_print_move(int, int, int);

//print_doing
void citizen_print_doing(int);
void zombie_print_doing(int, int, int, int);
void madongseok_print_move(int, int, int, int, int, int);

//train
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

//move
void  citizen_move(int c, int cr, int ca, int cd, int p, int w, int game) {
	cr = rand() % 100 + 1;
	if (cr <= 100 - p) { //c move
		cd = 1;
		c += 1;
		if (ca < 5) {
			ca += 1;
		}
	}
	else { //c stay
		cd = 0;
		if (ca > 1) {
			ca -= 1;
		}
	}
}

void zombie_move(int c, int ca, int m, int ma, int mac, int zd, int turn) {
	if (turn % 2 == 1) { //z can move t = 1 3 5 ...
		if (mac != 2) { //m not pull
			if (ca >= ma) { //move to c
				if (c - z != 1) { //z not with c
					z += 1;
					zd = 1;
				}
				else { // z with c
					zd = 0;
				}
			}
			else { //move to m
				if (z - m != 1) { //z not with m
					z -= 1;
					zd = 2;
				}
				else { // z with m
					zd = 0;
				}
			}
		}
		else { //m pull
			zd = 0;
		}

	}
	else { //z cannot move
		zd = 0;
	}
}

void madongseok_move(int m, int ma, int md, int z) {
	if (z - m == 1) { //z with m
		md = 0;
		if (ma > 1) {
			ma -= 1;
		}
	}
	else { //z not with m
		printf("madongseok move (0:stay, 1:left)>> ");
		scanf_s("%d", &md);
		if (md != 0 && md != 1) { //re
			printf("madongseok move (0:stay, 1:left)>> ");
			scanf_s("%d", &md);
		}
		if (md == 0) { //stay
			if (ma > 1) {
				ma -= 1;
			}
		}
		else { //left
			m += 1;
			if (ma < 5) {
				ma += 1;
			}	
		}
	}
}

//doing
void citizen_doing(int c, int w, int game, int flag_game) {
	if (w - c == 2) {
		flag_game = false;
		game = 3;
	}
}

void zombie_doing(int c, int ca, int m, int ma, int msp, int z, int zat, int game, int flag_game) {
	if (c - z != 1 && z - m != 1) { //z not with c, m
		zat = 0;
	}
	else if (c - z == 1 && z - m != 1) { //z with c only
		zat = 1;
	}
	else if (c - z != 1 && z - m == 1) { //z with m only
		zat = 2;
	}
	else { // z with c, m
		if (ca >= ma) {
			zat = 1;
		}
		else {
			zat = 2;
		}
	}
	if (zat = 1) { // z doing to c
		flag_game = false;
		game = 2;
	}
	else if (zat = 2) { //z doing to m
		msp -= 1;
		if (msp == 0) {
			zat = 3;
			flag_game = false;
			game = 4;
		}
	}
}

void madongseok_doing(int m, int ma, int ma1, int ms, int msp, int mac, int mr, int z) {
	if (z - m == 1) { //z with m
		printf("madongseok action (0.rest, 1.provoke, 2.pull)>> ");
		scanf_s("%d", &mac);
	}
	else { //z not with m
		printf("madongseok action (0.rest, 1.provoke)>> ");
		scanf_s("%d", &mac);
	}
	if (mac == 0) { //m rest
		if (ma > 1) {
			ma -= 1;
		}
		if (msp < ms) {
			msp += 1;
		}
	}
	else if (mac == 1) { //m provo
		ma1 = ma;
		ma = 5;
	}
	else { //m pull
		mr = rand() % 100 + 1;
			if (ma < 5) { //m pull and not pull, both
				ma += 2;
				if (ma > 5) {
					ma = 5;
				}
				if (msp > 0) {
					msp -= 1;
				}
			}
			if (mr > 100 - p) { //m not pull
				mac = 3;
			}

	}
}

//print_move
void citizen_print_move(int c, int ca, int cd, int w) {
	if (cd == 0){
		printf("citizen: stay %d (aggro: %d -> %d)\n", w - c, ca + 1, ca);
	}
	else if (cd == 1) {
		printf("citizen: %d -> %d ((aggro: %d -> %d)\n", w - (c - 1), w - c, ca - 1, ca);
	}
}

void zombie_print_move(int z, int zd, int w) {
	if (zd = 0) { //stay
		printf("zombie: stay %d\n", w - z);
	}
	else if (zd == 1) { //move to c
		printf("zombie: %d -> %d\n", w - (z - 1), w - z);
	}
	else if (zd == 2) { //move to m
		printf("zombie: %d -> %d\n", w - (z + 1), w - z);
	}
}

void madongseok_print_move(int m, int ma, int msp, int md, int w) {
	if (md == 0) { //stay
		printf("madongseok: stay %d (aggro %d -> %d, stamina: %d)\n", w - m, ma + 1, ma, msp);
	}
	else if (md == 1) { //move
		printf("madongseok: %d -> %d (aggro %d -> %d, stamina: %d)\n",w - (m - 1) ,w - m, ma + 1, ma, msp);
	}
}

//print_doing
void citizen_print_doing(int game) {
	if (game == 1) {
		printf("citizen does nothing.\n");
	}
}
void zombie_print_doing(int ca, int ma, int msp, int zat) {
	if (zat == 0) {
		printf("zombie attacked nothing.\n");
	}
	else if (zat == 2) {
		printf("zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n", ca, ma, msp + 1, msp);
	}
}
void madongseok_print_doiing(int ca, int m, int ma, int ma1, int msp, int w) {
	if (mac == 0) { //rest
		printf("madongseok rests...\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina:%d -> %d)\n", w - m, ma + 1, ma, msp - 1, msp);
	}
	else if (mac == 1) { //provo
		printf("madongseok provoked zombie...\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", w - m, ma1, ma, msp);
	}
	else if (mac == 2) {
		printf("madongseok pulled zombie... Next turn, it can't move\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina:%d -> %d)\n", w - m, ma - 2, ma, msp + 1, msp);
	}

}

//print game over
void game_over(int game) {
	if (game == 2) {
		printf("GAME OVER! citizen dead...\n");
	}
	else if (game == 3) {
		printf("YOU WIN! citizen escape the train!\n");
	}
	else if (game == 4) {
		printf("GAME OVER! madongseok dead...\n");
	}
}
int main(void) {
	printf("train length(15 ~ 50)>> ");
	scanf_s("%d", &w);
	printf("madongseok stamina(0~5)>> ");
	scanf_s("%d", &ms);
	printf("prercentile robability 'p' (10~90)>> ");
	scanf_s("%d", &p);

	//befor start
	void train_print(w, c, z, m);
	while (flag_game) {
		printf("\n");
		void train_print(w, c, z, m);
		//move
		void  citizen_move(c, cr, ca, cd, p, w, game);
		void zombie_move(c, ca, m, ma, mac, zd, turn);
		void citizen_print_move(c, ca, cd, w);
		void zombie_print_move(z, zd, w);
		void madongseok_move(m, ma, md, z);
		void train_print(w, c, z, m);
		void madongseok_print_move(m, ma, msp, md, w);
		//doing
		void citizen_doing(c, w, game, flag_game);
		void citizen_print_doing(game);
		void zombie_doing(c, ca, m, ma, msp, z, zat, game, flag_game);
		void zombie_print_doing(ca, ma, msp, zat);
		void madongseok_doing(m, ma, ma1, ms, msp, mac, mr, z);
		void madongseok_print_doing(ca, m, ma, ma1, msp, w);
		//game
		void game_over(game);
		turn += 1;
	}
	return 0;
}