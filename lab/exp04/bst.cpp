#include <iostream>
#include <queue>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    int du = 0;
    int ceng = 1;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}


void inorderTraversal(TreeNode* root, int x) {
    if (root->left != NULL) {
        inorderTraversal(root->left, x + 1);
        root->du++;
        }
        cout << root->val << " ";
    if(root->right != NULL){
        inorderTraversal(root->right, x + 1);
        root->du++;
        }
        root->ceng = x + 1 ;

}


void levelInfo(TreeNode* root) {
    if (root ->left != NULL) {
        levelInfo(root->left);
        }
        cout << root->ceng << ' ';
    if (root ->right != NULL) {
        levelInfo(root->right);
        }
   
}

void degreeInfo(TreeNode* root) {
    if (root ->left != NULL) {
        degreeInfo(root->left);
        }
        cout << root->du << ' ';
    if (root ->right != NULL) {
        degreeInfo(root->right);
        }
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, nums[i]);
    }
    inorderTraversal(root, 0);
    cout << endl;
    levelInfo(root);
    cout << endl;
    degreeInfo(root);

    return 0;
}
