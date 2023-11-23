#include <iostream>
using namespace std;

struct Node
{
  char data;
  int parent;
  int lchild, rchild;
} nodes[101];
int n, lastchild[101];

void buildTree()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> nodes[i].data >> nodes[i].parent;
  for (int i = 2; i <= n; i++)
  {
    int f = nodes[i].parent;
    if (lastchild[f] == 0)
      nodes[f].lchild = lastchild[f] = i;
    else
    {
      int j = lastchild[f];
      while (nodes[j].rchild != 0)
        j = nodes[j].rchild;
      nodes[j].rchild = i;
    }
  }
}

void Preorder(Node &root)
{
  if (root.data != '\0')
  {
    cout << root.data ;
    if (root.lchild != 0)
      Preorder(nodes[root.lchild]);
    if (root.rchild != 0)
      Preorder(nodes[root.rchild]);
  }
}
void Midorder(Node &root)
{
  if (root.data != '\0')
  {
    if (root.lchild != 0)
      Midorder(nodes[root.lchild]);
    cout << root.data ;
    if (root.rchild != 0)
      Midorder(nodes[root.rchild]);
  }
}
void Postorder(Node &root)
{
  if (root.data != '\0')
  {
    if (root.lchild != 0)
      Postorder(nodes[root.lchild]);
    if (root.rchild != 0)
      Postorder(nodes[root.rchild]);
    cout << root.data;
  }
}

int main()
{
  buildTree();
  Preorder(nodes[1]);
  cout << "\n";
  Midorder(nodes[1]);
  cout << "\n";
  Postorder(nodes[1]);
  return 0;
}
