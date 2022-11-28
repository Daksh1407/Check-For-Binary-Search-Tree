#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int x){
    static struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
}

void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int BST(struct node *root){
       static struct node *prev=NULL;
    if(root!=NULL){
        if(!BST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return BST(root->right);
    }
    else{
        return 1;
    }
}
int main() {
    struct node *root=createNode(5);
    struct node *c1=createNode(3);
    struct node *c2=createNode(6);
    struct node *c3=createNode(1);
    struct node *c4=createNode(4);
    root->left=c1;
    root->right=c2;
    c1->left=c3;
    c1->right=c4;
    inOrder(root);
    printf("\n");
    int val=BST(root);
    if(val==1){
        printf("YES!");
    }
    else{
        printf("NO!");
    }
    return 0;
}
