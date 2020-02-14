#include"AVL.h"
#include<vector>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8 };
	AVL tree;
	for (auto a : v)
		tree.insert(a);
	tree.deldata(3);
	tree.deldata(6);
	tree.Inorder();
	system("pause");
	return 0;
}