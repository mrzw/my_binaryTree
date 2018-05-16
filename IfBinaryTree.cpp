// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
// 判断是否是二叉排序树
#include <iostream>
#include <vector>
using namespace std;

struct node {
  int key;
  struct node* left;
  struct node* right;
};
 
struct node *newNode(int item) {
	struct node *temp = new struct node;
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool isBST(node* root, node* l=NULL, node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist that check it has
    // correct data or not
    if (l != NULL and root->key < l->key)
        return false;
 
    // if right node exist that check it has
    // correct data or not
    if (r != NULL and root->key > r->key)
        return false;
 
    // check recursively for every node.
    return isBST(root->left, l, root) && isBST(root->right, root, r);
}

void Inorder(node* root, vector<int>& temp) {
    if(root == NULL) return;
    Inorder(root->left, temp);
    temp.push_back(root->key);
    Inorder(root->right, temp);
}

bool isBST1(node* root) {
    vector<int> data;
    Inorder(root, data);
    int n = data.size();
    for(int i=0; i<n-1; i++) {
        if(data[i] >= data[i+1]) return false;   
    }
    return true;
}

int main()
{
    struct node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
 
    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
 
    return 0;
}
