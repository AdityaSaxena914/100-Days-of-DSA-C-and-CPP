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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left)) // Checking if the left side is BST
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) // Checking if the root data is smaller than parent data
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1; // if BST returning 1
    }
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL) // searching node
    {
        prev = root;
        if (root->data == key)
        {
            cout << "Cannot insert " << key << ", Already in BST";
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *New = createNode(key);
    if (key < prev->data) // checking if need to insert in left or right
    {
        prev->left = New;
    }
    else
    {
        prev->right = New;
    }
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

    int result = isBST(root);
    // Checking and printing if it is a BST
    if (result)
    {

        int key;
        cout << "Enter element to insert: ";
        cin >> key;
        cout << "BST: ";
        inOrder(root);
        cout << endl;
        insert(root, key);
        cout << "New BST: ";
        inOrder(root);
        cout << endl;
    }
    else
    {
        cout << "it is not a BST" << endl;
    }

    return 0;
}