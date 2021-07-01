// 通常

// #include <bits/stdc++.h>
// using namespace std;

// int square(int n) { 
// 	return floor(sqrt(n)); 
// }

// bool is_prime(int n) {
// 	for (int i = 2; i <= square(n); ++i) if (n % i == 0) return false;
// 	return n != 1; // 1の場合は例外
// }

// int main() {
// 	cout << square(102) << endl;
// 	cout << is_prime(101) << endl;
// 	return 0;
// }

// エラトステネスの篩
// n以下の素数を全て表示

#include <bits/stdc++.h>
using namespace std;

int square(int n) {
	return floor(sqrt(n));
}

bool is_prime(int n) {
	for (int i = 2; i <= square(n); ++i) if (n % i == 0) return false;
	return n != 1; // 1の場合は例外
}

vector<int> sieve(int n) {
	vector<int> v; // 素数ボックス
	vector<bool> v2(n+1, true);
	v2[0] = v2[1] = false;
	for (int i = 0; i <= n; ++i) {
		if (v2[i]) {
			v.push_back(i);
			for (int j = 2; j <= n / i; ++j) {
				v2[i * j] = false;
			}
		}
	}
	return v;
}

int main() {
	vector<int> v = sieve(70);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	return 0;
}