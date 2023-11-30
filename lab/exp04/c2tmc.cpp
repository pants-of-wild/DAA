#include <iostream>
using namespace std;
struct Node {
	int parent;
	int lChild, rChild;
	char data;
}nodes[101];
int lastChild[101];
int n;
void buildTree() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i].data >> nodes[i].parent;
	}
	for (int i = 2; i <= n; i++) {
		int f = nodes[i].parent;
		if(lastChild[f] == 0) {
			nodes[f].lChild = lastChild[f] = i;
		} else {
			int j = lastChild[f];
			while (nodes[j].rChild != 0) {
				j = nodes[j].rChild;
			}
			nodes[j].rChild = i;
		}
	} 
}
void printPreOrder(Node &root) {
	cout << root.data;
	if (root.lChild != 0) {
		printPreOrder(nodes[root.lChild]);
	}
	if (root.rChild != 0) {
		printPreOrder(nodes[root.rChild]);
	}
}
void printMidOrder(Node &root) {
	if (root.lChild != 0) {
		printMidOrder(nodes[root.lChild]);
	}
	cout << root.data;
	if (root.rChild != 0) {
		printMidOrder(nodes[root.rChild]);
	}
}
void printPostOrder(Node &root) {
	if (root.lChild != 0) {
		printPostOrder(nodes[root.lChild]);
	}
	if (root.rChild != 0) {
		printPostOrder(nodes[root.rChild]);
	}
	cout << root.data;
}
int main() {
	buildTree();
	printPreOrder(nodes[1]);
	cout << endl;
	printMidOrder(nodes[1]);
	cout << endl;
	printPostOrder(nodes[1]);
	return 0;
}
