#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

unsigned int len = 0;
int i;

void do_I(Node **head,size_t pos,unsigned short val) {

    Node *new = (Node *)malloc(sizeof(Node ));

    new->val = val;

    if(len == 0){
        *head = new;
        new->next = NULL;
        new->prev = NULL;
    }else{

        Node *temp = *head;
        if(pos >= len) {
            while(temp->next != NULL ) temp = temp->next;
            new->next = NULL;
            new->prev = temp;
            temp->next = new;
            ++len;
            return;
        }
//      go to the pos_th node
        for(i = 0; i < pos; ++i) temp = temp->next;

        if( temp == (*head) ) {
            new->prev = NULL;
            new->next = *head;
            (*head)->prev = new;
            (*head) = new;
        } else {
            new->prev = temp->prev;
            new->next = temp;
            temp->prev->next = new;
            temp->prev = new;
        }
    }
    len++;

}
void do_E(Node **head,size_t begin_pos,size_t end_pos) {
    if(len == 0) return;
    if(end_pos >= len ) end_pos = len;
    if(begin_pos >= len ) begin_pos = len;
    if(begin_pos >= end_pos) return;

    Node *start = *head;
    Node *end = *head;
    for(i = 0; i < begin_pos; ++i) start = start->next;
    for(i = 0; i < end_pos; ++i) end = end->next;

    if(start == *head){
        *head = end;
    }else if(end == NULL){
        start->prev->next = NULL;
    }else {
        start->prev->next = end;
        end->prev = start->prev;
    }

    len -= (end_pos - begin_pos);
}
void do_P(Node  *head,size_t pos){
    Node *temp = head;
    if(len == 0) return;
    if(pos >= len) pos = len-1;
    for(i = 0; i < pos; ++i) temp = temp->next;
    if(temp != NULL) printf("%d ", temp->val);
}
void do_R(Node **head, unsigned short val) {
    Node *temp = *head;
    while( temp != NULL ) {
        if( temp->val == val ) {
            Node *d = temp;

            if(temp == *head) *head = (*head)->next;
            else temp->prev->next = temp->next;

            if(temp->next == NULL) ;
            else temp->next->prev = temp->prev;

            temp = temp->next;
            free(d);

            --len;
        }else{
            temp = temp->next;
        }

    }
}
void do_S(Node  *head) {
    if(head == NULL) return;

    Node *temp = head;
    while( temp != NULL ) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
