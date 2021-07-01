// c++にしか使わない？
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an

#include <bits/stdc++.h>
using namespace std;

long long modpow(long long A, long long B, long long MOD) {
	long long D = 1;
	while (B > 0) {
		if (B & 1) D = D * A % MOD;
		A = A * A % MOD;
		B >>= 1;
	}
	return D;
}

int main() {
	cout << modpow(3,45,100000) << endl;
	// long longでも計算できない！c++不便！
	cout << (long long)pow(3, 45) % 100000 << endl;
	return 0;
}