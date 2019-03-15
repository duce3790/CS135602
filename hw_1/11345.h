#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdlib.h>

typedef struct man {
    int id;
    struct man* next;
    struct man* prev;
} man;

man* head;

man* createList(int n){
    int num = n;
    man *init;
    head = (man*)malloc(n*sizeof(man));
    head = NULL;
    while(--n >= 0){
        man *tmp = (man*)malloc(sizeof(man));
        tmp->id = num - n;
        if( head != NULL){
            tmp->prev = head;
            head->next = tmp;
            head = tmp;
        }
        else {
            head = tmp;
            init = head;
        }
    }
    head->next = init;
    init->prev = head;
    head = init;
    return head;
}

int solveJosephus(int step){
    man *cur = head;
    int dir = 1,cross = 1;  // 1 means kill next , 0 means kill prev
    while( cur->next != cur){
        ++cross;
        if( dir == 1){
            cur = cur->next;
            if( cross == step){
                man* kill = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur = cur->prev;
                free(kill);
                dir = 0;
                cross = 1;
            }
        }
        else{
            cur = cur->prev;
            if( cross == step){
                man* kill = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur = cur->next;
                free(kill);
                dir = 1;
                cross = 1;
            }
        }
    }
    return cur->id;
}


#endif
