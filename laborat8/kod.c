#include <stdio.h>

int max(int a, int b) {
	if (a >= b) {return a;}
	else {return b;}
}
int min(int a, int b) {
	if (a <= b) {return a;}
	else {return b;}
}

int mod(int a) {
	if (a < 0) {
		return -1 * a;
	}
	else {
		return a;
	}
}
	
int main() {
	// 20 пар чисел
	int N;
	FILE *myfile;
    myfile = fopen("27a.txt", "r");
	fscanf(myfile, "%d", &N);
	int min1 = 1000000000;
	int min2 = 1000000000;	
    int summa;
    for (int i = 0; i < N; i++) {
        int a, b;
        fscanf(myfile, "%d%d", &a, &b);
		summa = summa + min(a,b);
		if (mod(a - b) % 3 == 1) {
			min1 = min(mod(a - b), min1);
		}
		if (mod(a-b) % 3 == 1) {
			min2 = min(min2, mod(a - b));
		}
	}
	if (summa % 3 == 0) {
		printf("%d\n", summa);
		return 0;
	}
	else {
		if (summa % 3 == 1) {
			summa = summa + min1;
			printf("%d\n", summa);
			return 0;
		}
		else {
			summa = summa + min2;
			printf("%d\n", summa);
			return 0;
		}
		
	}
	fclose(myfile);
	return 0;
}
