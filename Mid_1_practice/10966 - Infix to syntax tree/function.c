#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

BTNode* EXPR(){
    char c;
    BTNode *father = NULL, *right = NULL;

    if (pos >= 0) {
        right = FACTOR();
        c = expr[pos];
        if (pos > 0) {
            if(c == '&' || c == '|') {
                father = makeNode(c);
                father->right = right;
                pos--;
                father->left = EXPR();
            } else father = right;
        } else father = right;
    }

    return father;
}
BTNode* FACTOR(){
    char c;
    BTNode *node = NULL;

    if (pos >= 0) {
        c = expr[pos--];
        if ('A' <= c && c <= 'D') {
            node = makeNode (c);
        } else
        if (c == ')') {
            node = EXPR();
            if(expr[pos--] != '(' ) {
                printf("ERROR parenthesis!!\n");
            }
        }
    }

    return node;
}
BTNode* makeNode(char c){
    int i;
    BTNode* new = (BTNode* )malloc(sizeof(BTNode));
    new->right = NULL; new->left = NULL;
    for (i = 0; i < NUMSYM; ++i)
        if (c == sym[i]) new->data = i;
    return new;
}

