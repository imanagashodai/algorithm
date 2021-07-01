// 計算量に余裕のある時or負の辺がある時だけ！O(V^3)
// 普通はダイクストラ法を回す。O(V^2logV)
// つまり、あまり使われない(´；ω；`)

#include <bits/stdc++.h>
using namespace std;

int v = 4, e = 5, r = 0;
int es[5][3] = {{2,0,4},{1,2,2},{0,1,1},{1,3,5},{2,3,1}};


int main() {
	int dp[v][v];

	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			dp[i][j] = 100000;
		}
	}

	for (int i = 0; i < v; ++i) dp[i][i] = 0;

	for (int i = 0; i < e; ++i) {
		dp[es[i][0]][es[i][1]] = es[i][2];
		dp[es[i][1]][es[i][0]] = es[i][2];
	}

	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			for (int k = 0; k < v; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}


	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			if (dp[i][j] != 100000) cout << dp[i][j];
			else cout << "INF";
		}
		cout << endl;
	}

	
	return 0;
}