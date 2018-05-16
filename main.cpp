// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
// 二叉搜索树查询，插入，删除
#include <iostream>
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

void inorder(struct node *root) {
	if(root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

struct node *insert(struct node *node, int key) {
	if(node == NULL) return newNode(key);
	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	return node;
}

struct node *search(struct node *node, int key) {
	if(node == NULL || node->key == key) return node;
	if(key < node->key)
		return search(node->left, key);
	else if(key > node->key)
		return search(node->right, key);
}

int main()
{
	struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    inorder(root);
    
    return 0;
}
