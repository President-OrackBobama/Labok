#include <stdio.h>

#define maxn 100


int main() {
    int neo[maxn][maxn];
    int i, j, n, summ;
	int min = 10000000;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &neo[i][j]);  

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (min > neo[i][j])
                min = neo[i][j];
        }
    }

    for (int j = 0; j < n; ++j) {
        int summ = 0;
        for (int i = 0; i < n; ++i) {
            summ += neo[i][j];
        }
        for (int i = 0; i < n; ++i) {
            if (neo[i][j] == min) {
                neo[i][j] = summ;
            }
        }
    }
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            printf("%d ", neo[i][j]);  
        putchar('\n');
    }        
    return 0;
}
