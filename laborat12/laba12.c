#include <stdio.h>
#include <assert.h>

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}

int mod(int a) {
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

void t_min() {
	assert(min(5,7) == 5);
	assert(min(0,2) == 0);
	assert(min(2,2) == 2);
}

void t_max() {
	assert(max(5,7) == 7);
	assert(max(0,2) == 2);
	assert(max(2,2) == 2);
}

void t_mod() {
	assert(mod(3) == 3);
	assert(mod(-3) == 3);
	assert(mod(0) == 0);
}

void t_all() {
	t_mod();
	t_max();
	t_min();
}

int main() {
	t_all();
	
	int a, b, c;
	long long N;
	long long n = 0;
	int summ = 0;
	int maxi = -1;
	scanf("%lld", &N);
	n = N;
	while (n > 0) {
		if (n >= 100) {
			a = n % 10;
			b = (n % 100) / 10;
			c = (n % 1000) / 100;
			summ = a + b + c;
		    maxi = max(summ, maxi);
		}
		n = n / 10;
	}
	while (N > 0) {
		if (N >= 100) {
			a = N % 10;
			b = (N % 100) / 10;
			c = (N % 1000) / 100;
			if (a + b + c == maxi) {
				printf("%d %d %d\n", c, b, a);
			}
		}
		N = N / 10;
	}
	return 0;
}