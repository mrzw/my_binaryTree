// https://www.geeksforgeeks.org/iterative-preorder-traversal/
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
// https://www.geeksforgeeks.org/iterative-postorder-traversal/
// tree traversals iterative
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
 
using namespace std;
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// An iterative process to print Preorder traversal of Binary tree
void iterativePreorder(node *root)
{
    // Base Case
    if (root == NULL)
       return;
 
    // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
    cout << endl;
}

// An iterative process to print Inorder traversal of Binary tree
void iterativeInorder(node *root)
{
    if (root == NULL)
       return;

    node *current=root;
    stack<node* > s;
    bool done=0;
    while(!done)
    {
        if(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        else if(!s.empty())
        {
            current=s.top();
            s.pop();
            printf("%d ",current->data);
            current=current->right;
        }
        else
        done=1;
    }
    cout << endl;
}

// An iterative process to print Postorder traversal of Binary tree
void iterativePostorder(node *root)
{
    if(root==NULL)
        return;
    stack<node *> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        node *temp=s1.top();
        s2.push(temp);
        s1.pop();
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
 
    }
    while(!s2.empty())
    {
        node *t=s2.top();
        cout<<t->data<<" ";
        s2.pop();
    }
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  cout << "Preorder traversal of binary tree is " << endl;
  iterativePreorder(root);
  cout << "Inorder traversal of binary tree is " << endl;
  iterativeInorder(root);
  cout << "Postorder traversal of binary tree is " << endl;
  iterativePostorder(root);
  return 0;
}
