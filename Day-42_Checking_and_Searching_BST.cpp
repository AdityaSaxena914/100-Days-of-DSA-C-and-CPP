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

struct node *searchBST(node *root, int key) // recursive approach
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key) // If found return root
    {
        return root;
    }
    else if (root->data < key) // if key is greater check right
    {
        return searchBST(root->right, key);
    }
    else
    {
        return searchBST(root->left, key); // if key is smaller check left
    }
}

struct node *searchLoop(node *root, int key) // iterative approach
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
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
    return NULL;
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

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = isBST(root);
    struct node *ans1 = searchLoop(root, key);
    struct node *ans2 = searchBST(root, key);
    
    // Checking and printing if it is a BST
    if (result)
    {
        cout << "BST: ";
        inOrder(root);
        cout << endl;
        if (ans1 != NULL && ans2 != NULL)
        {
            cout << "Element found";
        }
        else
        {
            cout << "Element not found";
        }
        cout << endl;
    }
    else
    {
        cout << "it is not a BST" << endl;
    }

    return 0;
}