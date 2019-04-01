#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
    if (inorder_start > inorder_end) return NULL;
    static int cur = 0;
    Node *root = (Node*)malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->data = preorder[cur++];

    if (inorder_start == inorder_end){
        root->left = NULL;
        root->right = NULL;
    }
    else{
        int ind = inorder_start;
        while (inorder[ind] != root->data) ind++;
        root->left = buildTree(inorder, preorder, inorder_start, ind - 1);
        root->right = buildTree(inorder, preorder, ind + 1, inorder_end);
    }
}

int cal_sum(Node* root){
    if( root->left == NULL && root->right == NULL)
        return root->data;
    else if( root->left == NULL) return cal_sum(root->right);
    else if(root->right == NULL) return cal_sum(root->left);
    else return cal_sum(root->left) + cal_sum(root->right);

}

void caculateLeafNodesSum(Node* root){
    printf("%d\n",cal_sum(root));
}
