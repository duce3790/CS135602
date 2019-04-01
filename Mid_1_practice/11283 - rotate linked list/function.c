#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void rotateList(Node** head,int k){
    int i;
    Node *tail = *head, *tmp = *head;
    while( tail->next != NULL) tail = tail->next;
    for(i = 0; i < k - 1; ++i) tmp = tmp->next;

    tail->next = *head;
    *head = tmp->next;
    tmp->next = NULL;
}
