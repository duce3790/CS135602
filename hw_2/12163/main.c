#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char data[21];
    struct _Node *next;
    struct _Node *prev;
} Node;

int main()
{
    int times;
    char cmd[3];
    Node *head = NULL;

    scanf("%d",&times);
    while(times--)
    {
        scanf("%s", cmd);
        if(strncmp (cmd,"I",2)==0)
        {
            char s[25];
            scanf("%s", s);
            if( head == NULL){
                head = (Node*)malloc(sizeof(Node));
                strcpy(head->data,s);
                head->next = NULL;
                head->prev = NULL;
            }
            else{
                Node *tmp = (Node*)malloc(sizeof(Node));
                strcpy(tmp->data,s);
                tmp->prev = cur;
                tmp->next = NULL;
                cur->next = tmp;
                cur = tmp;
            }
        }
        else if(strncmp (cmd,"RA",2)==0)
        {
            if( head != NULL ){
                Node *flag = cur;  // bug ¦b³o¸Ì
                while( flag != NULL){
                    //printf("enter while\n");
                    Node *tmp = (Node*)malloc(sizeof(Node));
                    strcpy(tmp->data,flag->data);
                    tmp->prev = cur;
                    tmp->next = NULL;
                    cur->next = tmp;
                    cur = tmp;
                    flag = flag->prev;
                }
            }
        }
        else if(strncmp (cmd,"DA",2)==0)
        {
            if( head != NULL){
                Node *flag = head, *stop_flag = cur;
                while( flag->prev != stop_flag){
                    Node *tmp = (Node*)malloc(sizeof(Node));
                    strcpy(tmp->data,flag->data);
                    tmp->prev = cur;
                    tmp->next = NULL;
                    cur->next = tmp;
                    cur = tmp;
                    flag = flag->next;
                }
            }
        }
        else if(strncmp (cmd,"S",2)==0)
        {
            if( head == NULL)
                printf("NULL \n");
            else{
                printf("%s",cur->data);
                cur = cur->prev;
                while( cur != NULL){
                    printf(" %s",cur->data);
                    cur = cur->prev;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
