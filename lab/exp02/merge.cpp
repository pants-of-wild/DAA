#include <stdio.h>

const int maxn = 1000000;

int m, n;
int a[maxn + 1];
int b[maxn + 1];
int c[maxn * 2 + 1];


int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	int i = 0,j = 0,s = 0;
	while(i!=m||j!=n){
		if(i==m){
			 c[s] = b[j];
			 j++;
			 s++;
			 continue;
		}
		if(j==n)
		{
			c[s] = a[i];
			i++;
			s++;
			continue;
		}
		if(a[i]>=b[j]) c[s] = b[j],j++;
		else c[s] = a[i],i++;
		s++;
	}
	for (int i = 0; i < s; i++)
		printf("%d ", c[i]);

	return 0;
}
