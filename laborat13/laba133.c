#include <stdio.h>
#include <locale.h>
#include <wchar.h>

const int standart = 335814913; //00101000000010000100000100000001
const int standart2 = 1946427681; //11101000000010000100000100100001

int main(){
    
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wchar_t x;
    int cur_set = 0;
    while(wscanf(L"%lc", &x)!=EOF){
        if(x==' '){
            if(((cur_set & standart2) | standart )==standart){
                wprintf(L"%s ", "YES");
				break;
            } 
            cur_set = 0;
            continue;
        }
        cur_set = cur_set | (1 << ((int)x - 1072));
    }
    return 0;
}