#define MAXN 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char expr[MAXN];
int pos = 0;


int cal(int A, int B, int C, int D){
    if(pos < strlen(expr)){
        char c = expr[pos++];

        if(c == '|'){
            return cal(A,B,C,D) | cal(A,B,C,D);
        }else if(c == '&'){
            return cal(A,B,C,D) & cal(A,B,C,D);
        }else if('A' <= c && c <= 'D'){
            switch (c-'A'){
                case 0:
                    return A;
                case 1:
                    return B;
                case 2:
                    return C;
                case 3:
                    return D;
                default:
                    return 0;
            }
        }
    }
}


int main (){

    scanf("%s",expr);
    int A, B, C, D;
    for(A = 0; A < 2; ++A){
        for(B = 0; B < 2; ++B){
            for (C = 0; C < 2; ++C){
                for (D = 0; D < 2; ++D){
                    pos = 0;
                    printf("%d %d %d %d %d\n", A, B, C, D, cal(A, B, C, D));
                }
            }
        }
    }
    return 0;
}
