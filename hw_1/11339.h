#ifndef NODE
#define NODE
#include<stddef.h>
#include<stdlib.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

int num = 0;
int i;

void do_I(Node **head,size_t pos,unsigned short val){
    printf("enter do_I suceed\n");
    Node *cur = *head;
    for( i = 0; i <= pos; i++){
        if( i >= num){
            if( cur == NULL){
                printf("enter\n");
                cur->val = val;
                printf("1 safe\n");
                cur->next = cur;
                printf("2 safe\n");
                cur->prev = cur;
                printf("3 safe\n");
                ++num;
                printf("leave\n");
            }
            else{
                printf("first enter\n");
                Node *tmp = (Node*)malloc(sizeof(Node));
                tmp->val = val;
                cur->next = tmp;
                tmp->prev = cur;
                tmp->next = head;
                (*head)->prev = tmp;
                ++num;
                printf("first out\n");
            }
            break;
        }
        else{
            if( i != pos) cur = cur->next;
            else{
                Node *tmp = (Node*)malloc(sizeof(Node));
                tmp->val = val;
                tmp->prev = cur;
                tmp->next = cur->next;
                cur->next->prev = tmp;
                cur->next = tmp;
                ++num;
            }
        }
    }
    printf("out of do_I\n");
}
void do_E(Node **head,size_t begin_pos,size_t end_pos){
    printf("enter do_I suceed\n");
    if( begin_pos == end_pos) return;
    Node *cur = *head;
    for( i = 0; i <= end_pos, i < num; i++){
        if( i >= begin_pos){
            Node *tmp = cur;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur = cur->next;
            free(tmp);
            --num;
        }
        else cur = cur->next;
    }
}
void do_P(Node  *head,size_t pos){
    printf("enter do_I suceed\n");
    if( pos >= num) return;
    Node *cur = head;
    for(i = 0; i <= pos; i++){
        if( i !=  pos) cur = cur->next;
        else    printf("%d ",cur->val);
    }
}
void do_R(Node **head,unsigned short val){
    printf("enter do_I suceed\n");
    Node *cur = *head;
    for( i = 0; i < num; i++){
        if( cur->val == val ){
            Node *tmp = cur;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur = cur->next;
            free(tmp);
            --num;
        }
    }
}
void do_S(Node  *head){
    printf("enter do_I suceed\n");
    Node *cur = head;
    for( i = 0; i < num; i++){
        printf("%d ",cur->val);
        cur = cur->next;
    }
}

#endif

