#include <stdio.h>
#include <iostream>
using namespace std;
const int Maxn = 10001;
int _col, _row;
int a[Maxn + 1][3], b[Maxn + 1][3];

void tri_trans()
{
	b[0][0] = a[0][1];
	b[0][1] = a[0][0];
	b[0][2] = a[0][2];
	int q = 1;
	for (int col = 1; col <= a[0][1]; col++) {
		for (int p = 1; p <= a[0][2]; p++) {
			if (a[p][1] == col ) {
				b[q][0] = a[p][1];
				b[q][1] = a[p][0];
				b[q][2] = a[p][2];
				q++;
			}
		}
	}
	for (int i = 0; i <= b[0][2]; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
		for (int i = 1; i <= b[0][2]; i++) {
			if (_col == b[i][1] && _row == b[i][0]  ) {
				cout << b[i][2];
				break;
			}
			cout << 0;
		}

}

int main()
{   
    
	for (int j = 0; j <= 2; j++)
		scanf("%d", &a[0][j]);
	for (int i = 1; i <= a[0][2]; i++)
		for (int j = 0; j <= 2; j++)
			scanf("%d", &a[i][j]);
	cin >> _row >> _col;
	tri_trans();
	return 0;
}
