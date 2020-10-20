//It used to deeply understand the binary search tree by hand
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct {
    Node* root;
}Tree;

void insert(Tree* tree, int value){
    Node* node  = (Node*)malloc(sizeof(Node));
    node -> data  = value;
    node -> right = NULL;
    node -> left  = NULL;

    if (tree -> root == NULL){
        tree -> root = node;
    }
    else{
        Node* temp = tree -> root;
        while(temp != NULL){
            if (value < temp -> data){        //left insert 
                if (temp -> left == NULL){
                    temp -> left = node;
                    return ;
                }
                else
                    temp = temp -> left;
            }
            else{                             //right insert
                if (temp -> right == NULL){
                    temp -> right = node;
                    return ;
                }
                else
                    temp = temp -> right;
            }
        }
    }
}

void preorder(Node* node){   //root left right
    if (node != NULL){
        cout << node  -> data ;
        preorder(node -> left);
        preorder(node -> right);
    }
}

void inorder(Node* node){   //left root right
    if (node != NULL){
        inorder(node -> left);
        cout << node -> data;
        inorder(node -> right);
    }
}

void posorder(Node* node){   //left root right
    if (node != NULL){
        posorder(node -> left);
        posorder(node -> right);
        cout << node  -> data;
    }
}

int hightget(Node* node){
    if (node == NULL)
        return 0;
    else{
        int left_hight = hightget(node -> left);
        int right_hight = hightget(node -> right);
        int max = left_hight;
        if (right_hight > max){
            max = right_hight;
        }
        return max + 1;
    }
}

int get_maximum(Node* node){
    if (node == NULL){ // empty node
        return -1;
    }
    else{
        int m1 = get_maximum(node -> left);
        int m2 = get_maximum(node -> right);
        int m3 = node -> data;
        int max = m1;
        if (m2 > max) { max = m2 ;}
        if (m3 > max) { max = m3 ;}
        return max;
    }
}

int main(){
    int arr[1000];
    int i = 0;
    while(cin)           //input nodes
        cin >> arr[i++];

    Tree tree;
    tree.root = NULL;

    for(int j = 0;j < i; j++)  //insert values
        insert(&tree, arr[j]);
    // preorder(tree.root);
    // inorder(tree.root);
    // posorder(tree.root);

    int h = hightget(tree.root) - 1; //eof contain in
    cout << "H = " << h << endl;
    cout << "The Max value is " << get_maximum(tree.root) << endl;
    return 0;
}