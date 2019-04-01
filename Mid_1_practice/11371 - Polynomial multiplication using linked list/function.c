#include "function.h"
#include<stdio.h>

void printNode(Node* head){
    while( head != NULL){
        if( head->data != 0)
            printf(" %ld %d",head->data,head->power);
        head = head->next;
    }
}
Node* create(){
    Node *head, *cur;
    long cof;
    int pow;
    scanf("%ld%d", &cof, &pow);
    head = malloc(sizeof(Node));
    cur = head;
    cur->data = cof;
    cur->power = pow;
    cur->next = NULL;
    while (pow != 0) {
        scanf("%ld%d", &cof, &pow);
        cur->next = malloc(sizeof(Node));
        cur = cur->next;
        cur->data = cof;
        cur->power = pow;
        cur->next = NULL;
    }
    return head;
}
void destroy(Node *node){
    if (node != NULL) {
        destroy(node->next);
        free(node);
    }
}
Node* insert (Node **head, Node *p1, Node *p2)
{
    Node *new = (Node *)malloc(sizeof(Node ));
    new->data = p1->data * p2->data;
    new->power = p1->power + p2->power;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
    } else {
        Node *temp = *head;
        Node *pre = *head;
        int is_add = 0;
        while (temp != NULL && temp->power >= new->power) {
            if (temp->power == new->power) {
                temp->data += new->data;
                is_add = 1;
            }
            pre = temp;
            temp = temp->next;

        }

        if (!is_add) {
            new->next = temp;
            pre->next = new;
        }

    }
    return *head;
}
Node* multiple (Node* p1, Node* p2)
{
    Node *head = NULL;
    Node *tmp2 = p2;
    while( p1 != NULL && p1->data != 0){
        while( tmp2 != NULL && tmp2->data != 0){
            head = insert(&head,p1,tmp2);
            tmp2 = tmp2->next;
        }
        p1 = p1->next;
        tmp2 = p2;
    }
    return head;
}
