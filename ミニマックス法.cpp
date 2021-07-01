// https://atcoder.jp/contests/abc201/tasks/abc201_d
#include <bits/stdc++.h>
using namespace std;

int h, w;
string ast;
int a[2009][2009];
int max2 = 4009;
int mem[2009][2009];

int opt(int i, int j) {
	if (mem[i][j] != max2) return mem[i][j];
	if (i == h && j == w) return mem[i][j] = 0;
	if ( ( i + j ) % 2 == 0 ) {
		if (i+1>h) return mem[i][j] = opt(i, j+1) + a[i][j+1];
		else if (j+1>w) return mem[i][j] = opt(i+1, j) + a[i+1][j];
		else return mem[i][j] = max(opt(i, j+1) + a[i][j+1], opt(i+1, j) + a[i+1][j]);
	} else {
		if (i+1>h) return mem[i][j] = opt(i, j+1) - a[i][j+1];
		else if (j+1>w) return mem[i][j] = opt(i+1, j) - a[i+1][j];
		else return mem[i][j] = min(opt(i, j+1) - a[i][j+1], opt(i+1, j) - a[i+1][j]);
	}
}

int main() {
	cin >> h >> w;

	for (int i = 1; i <= h; ++i) {
		cin >> ast;
		for (int j = 1; j <= w; ++j) {
			mem[i][j] = max2;
			if (ast[j-1] == '+') a[i][j] = 1;
			else a[i][j] = -1;
		}
	}

	int ans = opt(1,1);
	if (ans < 0) cout << "Aoki" << endl;
	else if (ans > 0) cout << "Takahashi" << endl;
	else cout << "Draw" << endl;



	return 0;
}
