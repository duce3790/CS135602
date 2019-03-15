#include<stdio.h>
#include"11349.h"


void create_tree(Node** root, int n){
    *root = (Node*)malloc(sizeof(Node));
    int i, j, val;
    Node *cur = *root;
    for( i = 0; i < n; ++i){
        scanf("%d",&val);
        if( cur == NULL){
            cur->data = val;
            cur->left = NULL;
            cur->right = NULL;
        }
        else{
            for(;;){
                if( val < cur->data){
                    if( cur->left == NULL){
                        Node *tmp = (Node*)malloc(sizeof(Node));
                        tmp->data = val;
                        cur->left = tmp;
                        tmp->left = NULL;
                        tmp->right = NULL;
                        break;
                    }
                    cur = cur->left;
                }
                else if( val > cur->data){
                    if( cur->right == NULL){
                        Node *tmp = (Node*)malloc(sizeof(Node));
                        tmp->data = val;
                        cur->right = tmp;
                        tmp->left = NULL;
                        tmp->right = NULL;
                        break;
                    }
                    cur = cur->right;
                }
                else break;
            }
        }
        cur = *root;
    }
}

void preorder(Node *cur){
    if(cur != NULL){
        printf(" %d",cur->data);
        preorder(cur->left);
        preorder(cur->right);
    }
}

void inorder(Node *cur){
    if(cur != NULL){
        inorder(cur->left);
        printf(" %d",cur->data);
        inorder(cur->right);
    }
}
void postorder(Node *cur){
    if(cur != NULL){
        postorder(cur->left);
        postorder(cur->right);
        printf(" %d",cur->data);
    }
}

void print_tree(Node *root){
    printf("preorder:");
    preorder(root);
    printf("\ninorder:");
    inorder(root);
    //system("pause");
    printf("\nout from inorder");
    printf("\npostorder:");
    postorder(root);
    printf("\nout from postorder\n");
}

