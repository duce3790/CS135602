// 3 AC 1 WA
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
} Node;


void createTree(Node **root, int n);
void printInorder(Node *root);
void GetMax(Node *root,int h);
void sumLevel(Node *root, int h, int h_cur);
void aveLevel(Node *root, int h, int h_cur);

int maxHeight = 0, sum = 0, level, amount;

int main()
{
    int n, m;
    char ins[20];
    Node* root = NULL;
    scanf("%d", &n);
    createTree(&root,n);
    scanf("%d", &m);
    while (m--) {
        scanf("%s", ins);
        switch (ins[0]) {
            case 'P':
                if (root == NULL)   printf("NULL");
                else    printInorder(root);
                printf("\n");
                break;
            case 'G':
                maxHeight = 0;
                GetMax(root, 0);
                printf("%d\n", maxHeight);
                break;
            case 'S':
                scanf("%d", &level);
                sum = 0;
                sumLevel(root,level,1);
                printf("%d\n", sum);
                break;
            case 'A':
                scanf("%d", &level);
                sum = 0;
                amount = 0;
                aveLevel(root, level, 1);
                if (amount == 0) {
                    printf("0\n");
                }
                else {
                    printf("%.3f\n",(float)sum / (float)amount);
                }
                break;
        }
    }
    return 0;
}

void createTree(Node **root, int n){
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


void printInorder(Node *cur){
    if(cur != NULL){
        printInorder(cur->left);
        printf("%d ",cur->data);
        printInorder(cur->right);
    }
}

void GetMax(Node *root, int h){
    if (root != NULL) {
        GetMax(root->left, h+1);
        GetMax(root->right, h+1);
    }
    else {
        if (h > maxHeight) {
            maxHeight = h;
        }
    }
}

void sumLevel(Node *root,int h, int h_cur){
    if( root != NULL){
        if( h_cur != h){
            sumLevel(root->left, h, h_cur+1);
            sumLevel(root->right, h, h_cur+1);
        }
        else
            sum += root->data;
    }
}

void aveLevel(Node *root,int h, int h_cur){
    if( root != NULL){
        if( h_cur != h){
            aveLevel(root->left, h, h_cur+1);
            aveLevel(root->right, h, h_cur+1);
        }
        else{
            sum += root->data;
            amount++;
        }
    }
}

