#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to NULL
    n->right = NULL;                                // setting the left and right children to NULL
    return n;                                       // returning the created node
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
struct node *inOrderPred(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *inOrderSucc(struct node *root)
{
    root = root->right;

    while (root->right != NULL)
    {
        root = root->left; // leftmost not null node of right subtree of the value to be deleted will be the inorder successor of the value
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *ipre;
    struct node *insuc;
    // printf("%d ",root->data);
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == value)
    { // inorder predecessor of the value will always be a leaf node
        free(root);
        return NULL;
    }
    // searching for the node value
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // when the value is found
        if (root->left == NULL)
        {
            insuc = inOrderSucc(root);
            root->data = insuc->data;
            root->right = deleteNode(root->right, insuc->data);
        }
        else
        {
            ipre = inOrderPred(root); // finding the inorder predecessor
            root->data = ipre->data;
            root->left = deleteNode(root->left, ipre->data); // deletion of the predecessor data
        }
    }
    return root;
}

int main()
{

    // constructing nodes
    struct node *root = createNode(5);
    struct node *left = createNode(3);
    struct node *right = createNode(6);
    struct node *left01 = createNode(2);
    struct node *left02 = createNode(4);

    // linking Root node to second and third node
    root->left = left;
    root->right = right;
    left->left = left01;
    left->right = left02;

    int value;
    cout << "Enter a value to delete: ";
    cin >> value;

    cout << "BST: ";
    inOrder(root);
    cout << endl;

    deleteNode(root, value);
    cout << "New BST: ";
    inOrder(root);
    cout << endl;

    return 0;
}