#include <stdio.h>
#include <stdlib.h>
#include "11345.h"


int main(){

    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus(m));
    }

    return 0;
}

