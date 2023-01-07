#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>

long double f(long double x) {
    return (1 + 2*(powl(x,2)))*(expl(powl(x, 2)));
}

long double fact(long double n) {
    long double res = 1;
    for (long double i = 1; i <= n; i++) res *= i;
    return res;
}

void tablica() {
    printf("Таблица значений ряда Тейлора для функции f(x) = (1 + 2*(x^2))*e^(x^2)\n");
    printf(" ------------------------------------------------------------------------------------------\n");
    printf("| x \t| Ряд Тейлора\t\t     | Функция\t\t          | Итерации | Разница\t\t      |\n");
    printf(" -------+------------------------+------------------------+-------+------------------------\n");
}

void str(long double x, long double summ, int n) {
    if (summ < 0) {
        printf("| %.2Lf\t| %.19Lf | %.19Lf | %d\t  | %.19Lf |\n", x, summ, f(x), n, fabsl(f(x) - summ));
    } else {
        printf("| %.2Lf\t| %.19Lf  | %.19Lf  | %d\t  | %.19Lf |\n", x, summ, f(x), n, fabsl(f(x) - summ));
    }
}


int main() {
    const long double a = 0, b = 1;
    long double summ, t, k;
    int c = 0;
    int n;

    printf("Количество итераций(n): \n");
    scanf("%d", &n);
    assert((n > 0) && "n должно быть больше нуля!");
    printf("Коэффицент(k): ");
    scanf("%Lf", &k);
    printf("\n\n");
    tablica();

    long double pl = (b - a) / n;
    for (long double x = a; x <= b; x += pl) {
        for (int i = 0; i < 99; ++i) {
            t = ((2*i + 1)/(fact(i)))*powl(x, 2*i);
            summ += t;
            ++c;
            if (fabsl(summ - f(x)) < LDBL_EPSILON * k) {
                break;
            }
        }
        str(x, summ, c);
        summ = 0;
        c = 0;
    }
}
