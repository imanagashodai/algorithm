#include <bits/stdc++.h>
using namespace std;

// 例1
int main() {
	int h, w, v;
	vector<int> a[2009];
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		a[i].push_back(0);
		for (int j = 1; j <= w; ++j) {
			cin >> v;
			a[i].push_back(v);
		}
	}
	return 0;
}

// 例2
int main() {
	int h, w, v;
	vector<vector<int>> a;
	cin >> h >> w;
	a.push_back({0});
	for (int i = 1; i <= h; ++i) {
		a.push_back({0});
		for (int j = 1; j <= w; ++j) {
			cin >> v;
			a[i].push_back(v);
		}
	}
	return 0;
}

// エラー(AtCoder環境では大丈夫かも)
int main() {
	int h, w, v;
	int a[2009][2009];
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> a[i][j];
		}
	}
	return 0;
}