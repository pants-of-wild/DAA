#include <iostream>
using namespace std;
struct treeNode {
	int val;
	int layer = 1;
	int branch = 0;
	treeNode* left;
	treeNode* right;
	treeNode(int x): val(x), left(NULL), right(NULL) {
	}
};

treeNode* insert(treeNode* root, int x) {
	if (root == NULL) {
		return new treeNode(x);
	}
	if (x < root->val) {
		root->left = insert(root->left, x);
	}else {
		root->right = insert(root->right, x);
	}
	return root;
}

void midOrderTriversal(treeNode* root, int layer) {
	if (root->left != NULL) {
		midOrderTriversal(root->left, layer + 1);
		root->branch++;
	}
	cout << root->val << " ";
	if (root->right != NULL) {
		midOrderTriversal(root->right, layer + 1);
		root->branch++;
	}
    root->layer = layer + 1; // the argument layer is important!
}

void printLayer(treeNode *root) {
	if (root->left != NULL) {
		printLayer(root->left);
	}
	cout << root->layer << " ";
	if (root->right != NULL) {
		printLayer(root->right);
	}	
}
void printBranch(treeNode *root) {
	if (root->left != NULL) {
		printBranch(root->left);
	}
	cout << root->branch << " ";
	if (root->right != NULL) {
		printBranch(root->right);
	}	
}

int main() {
	int n;
	cin >> n;
	int data[n];
	treeNode* root = NULL;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
		root = insert(root, data[i]);
	}
	midOrderTriversal(root, 0);
	cout << endl;
	printLayer(root);
	cout << endl;
	printBranch(root);
	cout << endl;
	return 0;
}
