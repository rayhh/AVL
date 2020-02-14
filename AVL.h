#pragma once


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	int height;
};

class AVL {
private:
	TreeNode* root;
	TreeNode* rotateLL(TreeNode* node);
	TreeNode* rotateRR(TreeNode* node);
	TreeNode* rotateLR(TreeNode* node);
	TreeNode* rotateRL(TreeNode* node);
	TreeNode* Newnode(const int& value, TreeNode* lchild, TreeNode* rchild, int height);
	int getheight(TreeNode* root);
	TreeNode* _insert(TreeNode*& root, const int& value);
	TreeNode* _deldata(TreeNode*& root, const int& value);
	void _Inorder(TreeNode* root);
public:
	AVL() { root = nullptr; }
	TreeNode* insert(const int& value) { return _insert(root, value); };
	TreeNode* deldata(const int& value) { return _deldata(root, value); };
	void Inorder() { _Inorder(root); };
};