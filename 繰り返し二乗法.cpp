// https://www.akiradeveloper.com/post/algorithm-doubling/
// modが使われていれば繰り返し二乗法！？

#include <bits/stdc++.h>
using namespace std;

long long func(long long A, long long T) {
	long long Z[22];
	Z[0] = A;
	for (int i = 1; i <= 20; ++i) {
		Z[i] = Z[i-1] * Z[i-1];
	}
	long long N = 1;
	for (int i = 0; T > 0; ++i, T >>= 1) {
		if ((1ll & T) != 0ll) {
			N *= Z[i];
		}
	}
	return N;
}


int main() {
	cout << func(2, 20) << endl;
	cout << (int)pow(2, 20) << endl;



	return 0;
}
