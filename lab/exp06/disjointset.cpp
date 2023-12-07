#include <iostream>
using namespace std;

#define MAX_NODES 2000000

int parent[MAX_NODES];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int countConnectedComponents(int n, int m) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unionSet(x, y);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << countConnectedComponents(n, m) << endl;
    return 0;
}
    
