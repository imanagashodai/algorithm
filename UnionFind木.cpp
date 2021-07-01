// https://www.slideshare.net/iwiwi/ss-3578491

#include <bits/stdc++.h>
using namespace std;

int N = 5;
int par[5];

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

int main() {
	for (int i = 0; i < N; ++i) par[i] = i;

	for (int i = 0; i < N; ++i) cout << par[i] << " ";
	cout << endl;

	cout << find(3) << endl;
	cout << (same(2,3) ? "true" : "false") << endl;
	uni(3,4);

	for (int i = 0; i < N; ++i) cout << par[i] << " ";
	cout << endl;

	cout << (same(3,4) ? "true" : "false") << endl;

	return 0;
}