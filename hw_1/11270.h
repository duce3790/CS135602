#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
    struct _Node *prev;
} Node;

Node* createList(){
    Node *head = NULL;
    int data;
    while( scanf("%d",&data) != EOF && data != -1){
        if( head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            head->data = data;
        }
        else{
            Node *tmp = (Node*)malloc(sizeof(Node));
            tmp->data = data;
            head->next = tmp;
            tmp->prev = head;
            head = tmp;
        }
    }
    return head;
}
Node* reverse(Node* head){
    Node *init = head;
    while( head->prev != NULL){
        head->next = head->prev;
        head = head->prev;
        //printf("reverse ok\n");
    }
    head->next = NULL;
    head->prev = NULL;
    return init;
}

#endif

