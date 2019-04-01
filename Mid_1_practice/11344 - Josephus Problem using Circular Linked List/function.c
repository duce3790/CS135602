#include<stdio.h>
#include"function.h"

Node* create(int n){
    if( n == 0) return NULL;
    int num = n;
    Node *head = (Node*)malloc(sizeof(Node)), *cur = head;
    head->data = 1;
    head->next = NULL;
    --n;
    while( --n >= 0){
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = num - n;
        tmp->next = NULL;
        cur->next = tmp;
        cur = tmp;
    }
    cur->next = head;
    return head;
}
void josephus(int m,Node *head){
    Node *cur = head;
    int cross = 1;
    while( cur->next != cur){
        ++cross;
        if( cross == m){
            Node *kill = cur->next;
            printf("%d ",kill->data);
            cur->next = cur->next->next;
            free(kill);
            cross = 1;
        }
        cur = cur->next;
    }
    printf("%d\n",cur->data);
}
