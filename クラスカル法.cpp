// https://www.slideshare.net/iwiwi/ss-3578491

#include <bits/stdc++.h>
using namespace std;

int N = 3;
int E = 3; // 経路の数
int par[3];
vector<vector<int>> edges = {{20,0,1},{3,1,2},{100,2,0}};

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	par[x] = y;
}

int kruskal() {
	int res = 0;
	for (int i = 0; i < N; ++i) {
		if (!same(edges[i][1],edges[i][2])) {
			res += edges[i][0];
			uni(edges[i][1],edges[i][2]);
		}
	}
	return res;
}

int main() {
	sort(edges.begin(), edges.end());
	for (int i = 0; i < N; ++i) par[i] = i;
	cout << kruskal() << endl;

	return 0;
}