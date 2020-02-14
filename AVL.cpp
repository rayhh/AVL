#include"AVL.h"
#include<iostream>



inline int max(int a, int b) { return a > b ? a : b; }

TreeNode* AVL::Newnode(const int& value, TreeNode* lchild, TreeNode* rchild, int height) {
	TreeNode* node = new TreeNode;
	node->val = value;
	node->left = lchild;
	node->right = rchild;
	node->height = height;
	return node;
}

int AVL::getheight(TreeNode* root) {
	return root == nullptr ? 0 : root->height;
}

TreeNode* AVL::rotateLL(TreeNode* root) {
	TreeNode* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height=max(getheight(root->left),getheight(root->right)) + 1;
	tmp->height = max(root->height, getheight(tmp->right)) + 1;
	return tmp;
}

TreeNode* AVL::rotateRR(TreeNode* root) {
	TreeNode* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	tmp->height = max(root->height, getheight(tmp->left)) + 1;
	return tmp;
}

TreeNode* AVL::rotateLR(TreeNode* root) {
	root -> left = rotateLL(root->left);
	return rotateRR(root);
}

TreeNode* AVL::rotateRL(TreeNode* root) {
	root->right = rotateRR(root->right);
	return rotateLL(root);
}

TreeNode* AVL::_insert(TreeNode*& root, const int& value) {
	if (root == nullptr) return root = Newnode(value, nullptr, nullptr, 1);
	else if (value < root->val)
		root->left = _insert(root->left, value);
	else
		root->right = _insert(root->right,value);

	root->height = max(getheight(root->left),getheight(root->right)) + 1;

	if (getheight(root->left) - getheight(root->right) == 2) {
		if (value < root->left->val)
			root=rotateRR(root);
		else
			root=rotateLR(root);
	}
	else if (getheight(root->right) - getheight(root->left) == 2) {
		if (value < root->right->val)
			root=rotateRL(root);
		else
			root=rotateLL(root);
	}
	return root;
}


TreeNode* AVL::_deldata(TreeNode*& root, const int& value) {
	if (!root) return nullptr;
	if (root->val == value) {
		if (root->right == nullptr) {
			TreeNode* tmp = root;
			root = root->left;
			delete(tmp);
			return root;
		}
		else {
			TreeNode* tmp = root->right;
			while (tmp->left)
				tmp = tmp->left;
			root->val = tmp->val;
			root->right = _deldata(root->right, tmp->val);
		}
	}
	else if (value < root->val) _deldata(root->left, value);
	else _deldata(root->right,value);

	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	if (getheight(root->left) - getheight(root->right) >= 2) {
		if (getheight(root->left->left) > getheight(root->left->right))
			root=rotateRR(root);
		else
			root=rotateLR(root);
	}
	else if (getheight(root->right) - getheight(root->left) >= 2) {
		if (getheight(root->right->right) - getheight(root->right->left))
			root=rotateLL(root);
		else
			root=rotateRL(root);
	}
	return root;
}


void AVL::_Inorder(TreeNode* root) {
	if (root) {
		_Inorder(root->left);
		printf("val: %d, height: %d  ", root->val, root->height);
		if (root->left)
			printf("left val: %d,left hegiht: %d   ", root->left->val, root->left->height);
		if (root->right)
			printf("right val: %d,right hegiht: %d  ", root->right->val, root->right->height);
		printf("\n");
		_Inorder(root->right);
	}
}

