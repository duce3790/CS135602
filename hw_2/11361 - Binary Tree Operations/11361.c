#include <stdio.h>
#include <stdlib.h>
#include "11361.h"


Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end) {
    Node *root = (Node*)malloc(sizeof(Node));
    if( inorder_start > inorder_end) return NULL;
    if (inorder_start == inorder_end){
        root->data = *preorder;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        int i = 0;
        while (*(inorder + inorder_start + i) != *(preorder)) ++i;
        root->data = *preorder;
        root->left = buildTree (inorder, preorder + 1, inorder_start, inorder_start - 1 + i);
        root->right = buildTree (inorder, preorder + i + 1, inorder_start + 1 + i, inorder_end);
    }
    return root;
}

void showPostorder(Node* root) {
    if (root != NULL) {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->data);
    }
}
