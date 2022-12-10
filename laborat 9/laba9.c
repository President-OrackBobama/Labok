#include <stdio.h>

int mod(int x, int y) {
    return (y + x % y) % y; //остаток от деления
}

int max(int x, int y) {  //максимальное число из двух
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int max3(int x, int y, int z) {
	if ((x >= y) && (x >= z)){
		return x;
	}
	else {
		if ((y >= x) && (y >= z)) {
			return y;
		}
		else {
			return z;
		}
	}
}

int min(int x, int y) {  //минимальное число из двух
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int abs(int i) {  //модуль
    if (i < 0) {
        return -i;
    } else {
        return i;
    }
}

int main() {
	int i0 = 12, j0 = 4,  l0 = 3;
	int i = i0, j = j0, l= l0;
	int ipr = i, jpr = j, lpr = l;
	for (int k = 0; k <= 50; k++) {
		ipr = i;
		jpr = j;
		lpr = lpr;
		i = mod((ipr * jpr / (abs(lpr) + 1) + jpr * lpr / (abs(ipr) + 1) + ipr * lpr / (abs(jpr) + 1)), 30);
		j = mod(ipr * max(jpr, lpr), 20) + mod((jpr * min(ipr, lpr)), 30) - k;
		l = mod(max3(ipr * jpr, ipr * lpr, jpr *lpr), 30) + 20;
		if ((i + j + 10 <= 0) && (i + j + 20 >= 0)) {
			printf("Попадание в заданную область на шаге %d, где i = %d, j = %d, l = %d\n", k, i, j, l);
			return 0;
		}
	}
	printf("Точка не попала в заданную область, i = %d, j = %d, l = %d\n", i, j, l);
			return 0;
}
