#include <stdio.h>
#include <assert.h>

int proverka(char s) {
    return ((s != EOF) && (s != '\n') && (s != '.') && (s != ',') && (s != ' '));
}

int main() {
    int c = 0, f = 1, num = 0;
    char s;
    s = getchar();
    while (1) {
        if (proverka(s)) {
            if ((s == '1' || s == '0') && f) {
                if (s == '1') {
                    num = (num * 10) + 1;
                } else {
                    num = num * 10;
                }
            } else {
                num = 0;
                f = 0;
            }
        }
        if (!proverka(s)) {
            if (f) {
                ++c;
                if (c % 3 == 0) {
                    printf("%d ", num);
                }
            }
            f = 1;
            num = 0;
        }
        if (s == EOF) {
            break;
        }
        s = getchar();
    }
    return 0;
}