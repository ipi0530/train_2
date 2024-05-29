#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//train
void train_print(int, int, int, int);
void train_print(int w, int c, int z, int m) {
	//train 1
	for (int i = 1; i <= w; i++) {
		printf("#");
	}
	printf("\n");
	//train 2
	printf("#");
	for (int i = 1; i <= w - 2; i++) { //½Ã¹Î
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

//citizen
int c_move(int, int, int, int);
int c_move_r(int, int);
int c_move_a(int, int);
void c_move_print(int, int, int, int);
int c_doing(int, int, int);
void c_doing_print(int);

int c_move(int c, int cm, int cp, int p) {
	cp = rand() % 100 + 1;
	if (cp <= 100 - p) {
		cm = 1;
	}
	else {
		cm = 0;
	}
	return cm;
}
int c_move_r(int cm, int c) {
	if (cm == 1) {
		c += 1;
	}
	return c;
}
int c_move_a(int cm, int ca) {
	if (cm == 1) {
		if (ca < 5) {
			ca += 1;
		}
	}
	else if (cm == 0) {
		if (ca > 1) {
			ca -= 1;
		}
	}
	return ca;
}
void c_move_print(int c, int ca, int cm, int w) {
	if (cm == 0) {
		printf("citizen: stay %d (aggro: %d -> %d)\n", w - c, ca + 1, ca);
	}
	if (cm == 1) {
		printf("citizen: %d -> %d (aggro: %d -> %d)\n", w - (c - 1), w - c, ca - 1, ca);
	}
}
int c_doing(int c, int w, int game) {
	if (w - c == 2) {
		game = 1;
	}
	else {
		game = 0;
	}
	return game;
}
void c_doing_print(int game) {
	if (game == 0) {
		printf("citizen dose nothing.\n");
	}
}

//zombie
int z_move(int, int, int, int, int, int, int);
int z_move_r(int, int);
void z_move_print(int, int, int);
int z_doing(int, int, int, int, int, int);
int z_doing_c(int, int);
int z_doing_m1(int, int);
int z_doing_m2(int, int, int);
void z_doing_print(int, int, int, int);

int z_move(int c, int ca, int m, int ma, int md, int z, int zm) {
	if (md != 2) {
		if (ca >= ma) {
			if (c - z == 1) {
				zm = 0;
			}
			else {
				zm = 1;
			}
		}
		else {
			if (z - m == 1) {
				zm = 0;
			}
			else {
				zm = 2;
			}
		}
	}
	else if (md == 2) {
		zm = 0;
	}
	return zm;
}
int z_move_r(int z, int zm) {
	if (zm == 1) {
		z += 1;
	}
	else if (zm == 2) {
		z -= 1;
	}
	return z;
}
void z_move_print(int z, int zm, int w) {
	if (zm == 0) {
		printf("zombie: stay %d\n", w - z);
	}
	else if (zm == 1) {
		printf("zombie: %d -> %d\n", w - (z - 1), w - z);
	}
	else if (zm == 2) {
		printf("zombie: %d -> %d\n", w - (z + 1), w - z);
	}
}
int z_doing(int c, int ca, int m, int ma, int z, int zd) {
	if (c - z == 1 && z - m == 1) {
		if (ca >= ma) {
			zd = 1;

		}
		else {
			zd = 2;
		}
	}
	else if (c - z == 1 && z - m != 1) {
		zd = 1;
	}
	else if (c - z != 1 && z - m == 1) {
		zd = 2;
	}
	else {
		zd = 0;
	}
	return zd;
}
int z_doing_c(int zd, int game) {
	if (zd == 1) {
		game = 2;
	}
	return game;
}
int z_doing_m1(int ms, int zd) {
	if (zd == 2) {
		if (ms > 0) {
			ms -= 1;
		}
	}
	return ms;
}
int z_doing_m2(int ms, int zd, int game) {
	if (zd == 2 && ms == 0) {
		game = 3;
	}
	return game;
}
void z_doing_print(int ca, int ma, int ms, int zd) {
	if (zd == 0) {
		printf("zombie attacked nobody.\n");
	}
	else if (zd == 1) {
		printf("GAME OVER! citizen dead...\n");
	}
	else if (zd == 2 && ms != 0) {
		printf("zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n", ca, ma, ms + 1, ms);
	}

}

//madongseok
int m_move(int, int, int);
int m_move_r(int, int);
int m_move_a(int, int);
void m_move_print(int, int, int, int, int);
int m_doing(int, int, int, int, int);
int m_doing_a(int, int);
int m_doing_s(int, int);
void m_doing_print(int, int, int, int, int);

int m_move(int m, int mm, int z) {
	if (z - m == 1) {
		mm = 0;
	}
	else {
		while (mm != 0 && mm != 1) {
			printf("madongseok move (0:stay, 1:left)>> ");
			scanf_s("%d", &mm);
		}
	}
	return mm;
}
int m_move_r(int m, int mm) {
	if (mm == 1) {
		m += 1;
	}
	return m;
}
int m_move_a(int ma, int mm) {
	if (mm == 0) {
		if (ma > 1) {
			ma -= 1;
		}
		if (ma < 0) {
			ma = 0;
		}
	}
	else if (mm == 1) {
		if (ma < 5) {
			ma += 1;
		}
	}
	return ma;
}
void m_move_print(int m, int ma, int ms, int mm, int w) {
	if (mm == 0) {
		printf("madongseok: stay %d (aggro: %d -> %d, siamina: %d)\n", w - m, ma + 1, ma, ms);
	}
	else if (mm == 1) {
		printf("madongseok: %d -> %d (aggro: %d -> %d, siamina: %d)\n", w - (m - 1), w - m, ma - 1, ma, ms);
	}
}
int m_doing(int m, int z, int md, int mr, int p) {
	if (z - m != 1) {
		while (md != 0 && md != 1) {
			printf("madongseok action(0.rest, 1.provke)>> ");
			scanf_s("%d", &md);
		}
	}
	else if (z - m == 1) {
		while (md != 0 && md != 1 && md != 2) {
			printf("madongseok action(0.rest, 1.provke, 2.pull)>> ");
			scanf_s("%d", &md);
		}
		if (md == 2) {
			mr = rand() % 100 + 1;
			if (mr <= 100 - p) {
				md = 2;
			}
			else {
				md = 3;
			}
		}
	}
	return md;
}
int m_doing_a(int md, int ma) {
	if (md == 0) {
		if (ma > 1) {
			ma -= 1;
		}
		else if (ma <= 0) {
			ma = 1;
		}
	}
	else if (md == 1) {
		ma = 5;
	}
	else if (md == 2 || md == 3) {
		ma += 2;
	}
	return ma;
}
int m_doing_s(int md, int ms) {
	if (md == 0) {
		ms += 1;
	}
	else if (md == 2 || md == 3) {
		ms -= 1;
	}
	return ms;
}
void m_doing_print(int m, int md, int ma, int ms, int bin) {
	if (md == 0) {
		printf("madongseok rests...\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", m, ma + 1, ma, ms - 1, ms);
	}
	else if (md == 1) {
		printf("madongseok provoked zombie...\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", m, bin, ma, ms);
	}
	else if (md == 2) {
		printf("madongseok pulled zombie... Next turn, it can't move\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", m, ma - 2, ma, ms + 1, ms);
	}
	else if (md == 3) {
		printf("madongseok failed to pulled zombie\n");
		printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", m, ma - 2, ma, ms + 1, ms);
	}
}

//game
bool game_over(int, bool);

bool game_over(int game, bool flag) {
	if (game == 1) {
		printf("YOU WIN!\n");
	}
	if (game == 2) {
		printf("GAME OVER! citizen dead...\n");
	}
	if (game == 3) {
		printf("GAME OVER! madongseok dead...\n");
	}
	if (game == 1 || game == 2 || game == 3) {
		flag = false;
	}
	return flag;
}

int main(void) {
	//citizen
	int c = 6, cp = 0, cm = 0, ca = 1;
	//zombie
	int z = 4, zm = 0, zd = 0;
	//madongseok
	int m = 2, ma = 1, mm = 5, md = 5, ms, mr = 0;
	//else
	int p = 0, w, t = 1, game = 0, bin = 0;
	bool flag = true;
	//main
	printf("train length(15~50)>> ");
	scanf_s("%d", &w);
	printf("madongseok stamina(0~5)>> ");
	scanf_s("%d", &ms);
	printf("percentile probability 'p'(10~100)>> ");
	scanf_s("%d", &p);
	train_print(w, c, z, m);
	while (flag) {

		printf("\n");
		//move
		//c
		cm = c_move(c, cm, cp, p);
		c = c_move_r(cm, c);
		ca = c_move_a(cm, ca);
		//z
		if (t % 2 == 1) {
			zm = z_move(c, ca, m, ma, md, z, zm);
			z = z_move_r(z, zm);
		}
		else if (t % 2 == 0) {
			zm = 0;
		}
		//now
		train_print(w, c, z, m);
		c_move_print(c, ca, cm, w);
		z_move_print(z, zm, w);
		printf("\n");
		//m
		mm = m_move(m, mm, z);
		m = m_move_r(m, mm);
		ma = m_move_a(ma, mm);
		train_print(w, c, z, m);
		m_move_print(m, ma, ms, mm, w);
		mm = 5;
		printf("\n");

		//doing
		// c
		game = c_doing(c, w, game);
		//z
		zd = z_doing(c, ca, m, ma, z, zd);
		game = z_doing_c(zd, game);
		ms = z_doing_m1(ms, zd);
		game = z_doing_m2(ms, zd, game);
		// now
		if (game == 0) {
			c_doing_print(game);
			z_doing_print(ca, ma, ms, zd);
			zd = 0;
			//m
			md = m_doing(m, z, md, mr, p);
			bin = ma;
			ma = m_doing_a(md, ma);
			ms = m_doing_s(md, ms);
			m_doing_print(m, md, ma, ms, bin);
			md = 5;
		}
		//game
		flag = game_over(game, flag);
		//turn
		t += 1;
	}
	return 0;
}