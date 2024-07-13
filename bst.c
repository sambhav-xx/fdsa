#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* Create(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed");
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return Create(data);
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}

void in_order_traversal(struct Node* root){
    if(root != NULL){
        in_order_traversal(root->left);
        printf("%d ",root->data);
        in_order_traversal(root->right);
    }
}

void pre_order_traversal(struct Node* root){
    if(root != NULL){
        printf("%d ",root->data);
        in_order_traversal(root->left);
        in_order_traversal(root->right);
    }
}

void post_order_traversal(struct Node* root){
    if(root != NULL){
        in_order_traversal(root->left);
        in_order_traversal(root->right);
        printf("%d ",root->data);
    }
}

int height_bst(struct Node* root){
    if(root == NULL){
        return -1;
    }
    int left_height = height_bst(root->left);
    int right_height = height_bst(root->right);
    return 1+(left_height > right_height ? left_height:right_height);
}

void search(struct Node* root, int data){
    if(root == NULL){
        printf("not found\n");
        return;
    }
    if(data == root->data){
        printf("found\n");
        return;
    }
    if(data < root->data){
        search(root->left,data);
    }else{
        search(root->right,data);
    }
}

void search_min(struct Node* root){
    if(root == NULL){
        printf("empty tree....\n");
        return ;
    }
    if(root->left != NULL){
        search_min(root->left);
    }else{
        printf("min: %d\n",root->data);
    }
}

void search_max(struct Node* root){
    if(root == NULL){
        printf("empty tree....\n");
        return ;
    }
    if(root->right != NULL){
        search_max(root->right);
    }else{
        printf("max: %d\n",root->data);
    }
}

int main(){
    struct Node* root = NULL;
    
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,60);
    root = insert(root,80);
    
    in_order_traversal(root);
    printf("\n");
    pre_order_traversal(root);
    printf("\n");
    post_order_traversal(root);
    printf("\n");
    
    printf("height_bst: %d\n", height_bst(root) );
    
    search(root,90);
    search_min(root);
    search_max(root);
    
}