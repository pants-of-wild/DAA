#include <iostream>
using namespace std;
struct biTree{
    char data;
    biTree* lChild;
    biTree* rChild;
    int numberOfChild;
    biTree(char d):data(d) {
        lChild = NULL;
        rChild = NULL;
        numberOfChild = 0;
    }
};
biTree* creatTree(biTree* root) {
    char s;
    cin >> s;
    if (s == '#') {
        return NULL;
}
   root = new biTree(s);
   root->lChild = creatTree(root->lChild); 
   if (root->lChild != NULL) {
      root->numberOfChild++;
   }
   
   root->rChild = creatTree(root->rChild);
   if (root->rChild != NULL) {
       root->numberOfChild++;
   }
   return root;
}
int countSingle(biTree* root) {
    int count = 0;
    if (root != NULL && root->numberOfChild == 1) {
        count++;
    }
    if (root->lChild != NULL) {
        count += countSingle(root->lChild);
    }
    if(root->rChild != NULL) {
        count += countSingle(root->rChild);
    }
    return count;
}
int main() {
    biTree *root = NULL;
    root = creatTree(root);
    cout << countSingle(root);
}
