#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

long double f(long double x) {
    return 3*x - 14 + expl(x) - expl(-x);
}

long double fproiz(long double x) {
    return 3 + expl(x) - expl(-x);
}

long double fprpr(long double x) {
	return expl(x) - expl(-x);
}

int main(void) {
    long double a = 1.0, b = 3.0, n;
    long double x = (a+b) / 2;
	if (llabs(f(x)*fprpr(x))<powl((fproiz(x)),2)) {
	    while (1) {
            n = x - f(x) / fproiz(x);
			if (fabs(n - x) < LDBL_EPSILON) {
				break;
			}
			x = n;
		}
	}
	else {
		printf("Проверка на сходимость провалена\n");
	}
    printf("%Lf\n", x);
    return 0;
	
}
