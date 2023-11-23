#include <stdio.h>

const int MAXN = 12000;
int n, a[MAXN + 1], dp[MAXN + 1];

int longestNum()
{
	dp[0] = 1;
	int max = 1;
	// Insert your code here
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = dp[i] > dp[j] + 1?dp[i]:dp[j] + 1;
			}
		}
		max = max > dp[i]? max: dp[i];
	}
	return max;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", longestNum());
	return 0;
}
