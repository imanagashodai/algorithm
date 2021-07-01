// https://atcoder.jp/contests/typical90/tasks/typical90_c

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1 << 18], b[1 << 18];

const int INF = (1 << 29);
vector<int> g[1 << 18];
int dist[1 << 18];

void getdist(int start) {
	for (int i = 1; i <= n; ++i) dist[i] = INF;

	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int pos = q.front(); q.pop();
		for (int to : g[pos]) {
			if (dist[to] == INF) {
				dist[to] = dist[pos] + 1;
				q.push(to);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	getdist(1);
	int maxn1 = -1, maxid1 = -1;
	for (int i = 1; i <= n; ++i) {
		if (maxn1 < dist[i]) {
			maxn1 = dist[i];
			maxid1 = i;
		}
	}

	getdist(maxid1);
	int maxn2 = -1, maxid2 = -1;
	for (int i = 1; i <= n; ++i) {
		if (maxn2 < dist[i]) {
			maxn2 = dist[i];
			maxid2 = i;
		}
	}

	cout << maxn2 + 1 << endl;


	return 0;
}