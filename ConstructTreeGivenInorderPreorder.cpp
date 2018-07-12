#include <iostream>
#include<stdio.h> 
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {  
public:  
    struct TreeNode* PreInCreat(vector<int> pre,vector<int> in,int l1,int h1,int l2,int h2)  
    {  
        int i;
        TreeNode* root = new TreeNode(pre[l1]);  
        for(i=l2;in[i]!=root->val;i++); 
        int llen = i-l2;  
        int rlen = h2-i;
        if(llen)  
            root ->left = PreInCreat(pre,in,l1+1,l1+llen,l2,l2+llen-1);  
        else  
            root ->left = NULL;  
        if(rlen)  
            root ->right = PreInCreat(pre,in,h1-rlen+1,h1,h2-rlen+1,h2);  
        else  
            root ->right = NULL;  
        return root;  
    }  
       
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {  
        return PreInCreat(pre,in,0,pre.size()-1,0,in.size()-1);  
    }  
};  

void display(TreeNode* node) {
	if(node==NULL) return;
	display(node->left);
	cout << node->val << " ";
	display(node->right);
}
int main(int argc, char** argv) {
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> vin = {4,7,2,1,5,3,8,6};
	Solution *s = new Solution;
	TreeNode* node = s->reConstructBinaryTree(pre, vin);
	display(node);
	return 0;
}
