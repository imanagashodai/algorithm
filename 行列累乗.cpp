// https://atcoder.jp/contests/typical90/tasks/typical90_e
#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const int MAX_N = 33;

// 最後にコロンつける！
struct Matrix {
	int sz; // 行列サイズ
	long long x[MAX_N][MAX_N]; // 行列を保存
};

Matrix multiply(Matrix A, Matrix B) {
	Matrix C; // 返り値の保管用
	C.sz = A.sz;
	memset(C.x, 0, sizeof(C.x));
	for (int i = 0; i < C.sz; ++i) {
		for (int j = 0; j < C.sz; ++j) {
			for (int k = 0; k < C.sz; ++k) {
				C.x[i][k] += A.x[i][j] * B.x[j][k];
				C.x[i][k] %= mod;
			}
		}
	}
	return C;
}

// aのt乗
Matrix powers(Matrix A, long long T) {
	Matrix C;
	Matrix D[64]; // 行列を多数保存。iにはa^(2^i)が保存。
	D[0] = A;
	for (int i = 1; i < 62; ++i) {
		D[i] = multiply(D[i-1], D[i-1]);
	}
	C.sz = A.sz;
	memset(C.x, 0, sizeof(C.x));
	for (int i = 0; i < C.sz; ++i) {
		C.x[i][i] = 1;
	}
	for (int i = 62; i >= 0; --i) {
		if ((T & (1ll << i)) != 0ll) {
			C = multiply(C, D[i]);
		}
	}
	return C;
}

long long n, b, k, c[11];

int main() {
	cin >> n >> b >> k;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}
	Matrix a; 
	a.sz = b;
	memset(a.x, 0, sizeof(a.x));
	for (int i = 0; i < b; i++) {
		for (int j = 1; j <= k; j++) {
			int nex = (i * 10 + c[j]) % b;
			a.x[i][nex] += 1;
		}
	}

	Matrix z = powers(a, n);

	long long answer = z.x[0][0];
	cout << answer << endl;


	return 0;
}