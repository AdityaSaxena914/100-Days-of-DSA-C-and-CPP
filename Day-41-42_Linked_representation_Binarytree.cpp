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
int main(){
    /*Contructing root node
    struct node* p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    //Contructing second node
    struct node* p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    //Contructing third node
    struct node* p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;*/


    //constructing nodes
    struct node* p = createNode(2);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(4);

    //linking Root node to second and third node
    p->left = p1;
    p->right = p2;
return 0;
}