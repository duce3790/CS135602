#include<stdio.h>
#include"11349.h"


void create_tree(Node **root, int n){
    *root = (Node*) malloc(sizeof(Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    int i, val;
    Node *cur;
    if (n == 0) {
        return;
    }
    scanf("%d", &val);
    (*root)->data = val;
    for (i = 1; i < n; ++i) {
        cur = *root;
        scanf("%d", &val);
        for(;;) {
            if (val < cur->data) {
                if ( cur->left == NULL) {
                    cur->left = (Node*) malloc(sizeof(Node));
                    cur->left->data = val;
                    cur->left->left = NULL;
                    cur->left->right = NULL;
                    break;
                }
                cur = cur->left;
            }
            else if (val > cur->data) {
                if (cur->right == NULL) {
                    cur->right = (Node*) malloc(sizeof(Node));
                    cur->right->data = val;
                    cur->right->left = NULL;
                    cur->right->right = NULL;
                    break;
                }
                cur = cur->right;
            }
            else {
                break;
            }
        }
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
    printf("\npostorder:");
    postorder(root);
}

