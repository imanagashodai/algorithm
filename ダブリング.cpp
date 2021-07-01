// https://algo-logic.info/doubling/
// https://www.akiradeveloper.com/post/algorithm-doubling/
// https://satanic0258.hatenablog.com/entry/2017/02/23/222647
// https://atcoder.jp/contests/abc167/tasks/abc167_d
// 純粋関数やmodを使うときは真っ先に疑う！
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[200009];
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	// 提出時には↓に変える
	// int dp[63][2000009];
	int dp[63][2009];
	for (int i = 1; i <= n; ++i) {
		dp[0][i] = a[i];
	}

	for (int i = 1; i <= 62; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}

	int ans = 1;

	for (int i = 0; k > 0; ++i, k >>= 1) {
		if ((k & 1) != 0) {
			ans = dp[i][ans];
		}
	}

	cout << ans << endl;

	return 0;
}