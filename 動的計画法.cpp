// メモ化再帰
// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-6-%E7%99%BA%E5%B1%95%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%85%A8%E6%8E%A2%E7%B4%A2%E3%81%AE%E5%BF%9C%E7%94%A8%E3%83%A1%E3%83%A2%E5%8C%96%E5%86%8D%E5%B8%B0

// #include <bits/stdc++.h>
// using namespace std;

// int memo[1000];
// int func(int a) {
//   if (a == 0) return 1;
//   if (memo[a] >= 1) return memo[a];
//   int z1 = func(a-1);
//   int z2 = (a >= 2 ? func(a-2) : 0);
//   memo[a] = z1 + z2;
//   return memo[a];
// }

// int main() {
//   int N = 40;
//   cout << func(N) << endl;

//   return 0;
// }

// ナップサックDP
// https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-2%E3%83%8A%E3%83%83%E3%83%97%E3%82%B5%E3%83%83%E3%82%AF%E5%95%8F%E9%A1%8C

// #include <bits/stdc++.h>
// using namespace std;

// int n = 6;
// // {weight, value}
// vector<vector<int>> wv = {{2,3},{1,2},{3,6},{2,1},{1,3},{5,85}};
// int W = 9;

// // dp[k][w]はi番目までの数値を用いた時の重さがw以下となるときの総和価値の最大
// // よってdp[0][w]=0。kとwはどちらも1つ多めにとる

// int main() {
//   int dp[1009][1009];
//   for (int i = 0; i <= n; ++i) dp[0][i] = 0;

//   for (int k = 1; k <= n; ++k) {
//     for (int w = 0; w <= W; ++w) {
//       if (w >= wv[k-1][0]) {
//         dp[k][w] = max(dp[k][w-wv[k-1][0]] + wv[k-1][1], dp[k][w]);
//       } else {
//         dp[k+1][w] = dp[k][w];
//       }
//     }
//   }
//   cout << dp[n][W] << endl;

//   return 0;
// }

// 区間DP
// http://kutimoti.hatenablog.com/entry/2018/03/10/220819

// #include <bits/stdc++.h>
// using namespace std;

// int n = 5;
// int w[5] = {40, 1, 2, 3, 1};

// // dp[l][r]は区間[l,r]で取り除くことのできるブロックの数
// int dp[5][5];

// // func(l,r)も区間[l,r]で取り除くことのできるブロックの数
// int func(int l,int r) {
//   if (dp[l][r] != -1) return dp[l][r];
//   if (r == l) return dp[l][r] = 0;
//   if (r - l == 1) return dp[l][r] = (abs(w[r]-w[l])<=1 ? 2 : 0);

//   if (abs(w[r]-w[l]) <= 1 && func(l+1,r-1) == r-l-1) {
//     return dp[l][r] = r-l+1;
//   } else {
//     int mx = 0;
//     for (int i = l; i <= r-1; ++i) {
//       mx = max(func(l,i) + func(i+1,r), mx);
//     }
//     return dp[l][r] = mx;
//   }
// }

// int main() {
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       dp[i][j] = -1;
//     }
//   }

//   cout << func(0,n-1) << endl;

//   return 0;
// }

// bitDP
// https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp

#include <bits/stdc++.h>
using namespace std;

int N = 4;
int Dist[4][4] = {{0,8,7,3},{8,0,9,1},{7,9,0,4},{3,1,4,0}};

// dpテーブルは余裕をもったサイズにする
int dp[1000][4];

// bitを探索済で、現在地がvの時の最小値
int rec(int bit, int v) {
  // すでに探索済みだったらリターン
  if(dp[bit][v] != -1) return dp[bit][v];
  // 初期値
  if (bit == (1<<v)) return dp[bit][v] = 0;
  // 答えを格納する変数
  int res = 100000;
  // bit の v を除いたもの
  int prev_bit = bit & ~(1<<v);
  // v の手前のノードとして u を全探索
  for (int i = 0; i < N; ++i) {
    // u が prev_bit になかったらダメ
    if (prev_bit & (1<<i)) {
      res = min(res, rec(prev_bit, i) + Dist[i][v]);
    }
  }
  return dp[bit][v] = res;
}

int main() {
  for (int i = 0; i < (1<<N); ++i) {
    for (int j = 0; j < N; ++j) {
      dp[i][j] = -1;
    }
  }

  int ans = 100000;

  for (int i = 0; i < N; ++i) {
    ans = min(ans, rec((1<<N)-1,i));
  }

  cout << ans << endl;

  return 0;
}