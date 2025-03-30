#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n;//creating node pointer
    n = (struct node *)malloc(sizeof(struct node)); //allocating memory in the heap
    n->data = data;//setting the data
    n->left = NULL;//setting the left and right children to NULL
    n->right = NULL;//setting the left and right children to NULL
    return n;// returning the created node
}

void preOrder(struct node* root){
    if(root!= NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node* root){
    if(root!= NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
void inOrder(struct node* root){
    if(root!= NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){

    //constructing nodes
    struct node* root = createNode(4);
    struct node* left = createNode(1);
    struct node* right = createNode(6);
    struct node* left01 = createNode(5);
    struct node* left02 = createNode(2);
    

    //linking Root node to second and third node
    root->left = left;
    root->right = right;
    left->left = left01;
    left->right = left02;

    //calling preOrder traversal
    cout<<"Pre-Order Traversal"<<endl;
    preOrder(root);
    cout<<endl;

    //calling postOrder traversal
    cout<<"Post-Order Traversal"<<endl;
    postOrder(root);
    cout<<endl;

    //calling inOrder traversal
    cout<<"In-Order Traversal"<<endl;
    inOrder(root);
    cout<<endl;

return 0;
}