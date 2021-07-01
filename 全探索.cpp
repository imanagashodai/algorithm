// bit全探索
// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-1-bit-%E5%85%A8%E6%8E%A2%E7%B4%A2

// #include <bits/stdc++.h>
// using namespace std;

// int n = 8, A[8] = {100,500,1,50,10,5,1000,5000}, X = 6161;
// bool flag = false;

// int main() {
// 	for (int i = 0; i < (1 << n); ++i) {
// 		int bit[30], sum = 0;

// 		for (int j = 0; j < n; ++j) {
// 			bit[j] = (i >> j) % 2;
// 		}

// 		for (int j = 0; j < n; ++j) sum += A[j] * bit[j];

// 		if (sum == X) {flag = true; break;}
// 	}

// 	cout << (flag ? "Yes" : "No") << endl;

// 	return 0;
// }

// 順列全探索
// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-2-%E9%A0%86%E5%88%97%E5%85%A8%E6%8E%A2%E7%B4%A2

#include <bits/stdc++.h>
using namespace std;

int N = 3, A[3][3] = {{0,2,3},{5,0,2},{1,4,0}};
int P[3] = {1,2,3};
int ans = 10000000;

int main() {
	do {
		cout << P[0] << " " << P[1] << " " << P[2] << endl;
		int ret = 0;
		for (int i = 0; i < N - 1; ++i) ret += A[P[i]][P[i + 1]];
		ans = min(ans, ret);
	} while(next_permutation(P, P + N));


	cout << ans << endl;

	return 0;
}