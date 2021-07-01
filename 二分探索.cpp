// https://atcoder.jp/contests/typical90/tasks/typical90_a

#include <bits/stdc++.h>
using namespace std;

long long n, l, k, a[100009], len, cnt;

bool yokan(long long cp) {
	len = 0;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] - len >= cp) {
			cnt++;
			len = a[i];
		}
	}
	if (l - len >= cp) cnt++;
	if (cnt >= k + 1) return true;
	return false;
}


int main() {

	cin >> n >> l >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	long long le = 0;
	long long ri = l;
	while (le != ri - 1) {
		if (yokan((le + ri) / 2)) {
			le = (le + ri) / 2;
		} else {
			ri = (le + ri) / 2;
		}
	}

	cout << le << endl;

  return 0;
}

// lower_boundの使い方。vectorじゃなくてもsortは可能！
// https://atcoder.jp/contests/typical90/tasks/typical90_g
// int main() {
// 	long long n, q, a[300009], b[300009];

// 	cin >> n;
// 	for (int i = 1; i <= n; ++i) cin >> a[i];
// 	cin >> q;
// 	for (int i = 1; i <= q; ++i) cin >> b[i];
// 	sort(a + 1, a + n + 1);

// 	for (int i = 1; i <= q; ++i) {
// 		long long num = lower_bound(a + 1, a + n + 1, b[i]) - a;
// 		long long ans = abs(a[num] - b[i]);
// 		long long ans2 = 20000000000;
// 		if (num - 1 > 0) ans2 = b[i] - a[num - 1];
// 		cout << min(ans, ans2) << endl;
// 	}

// 	return 0;
// }