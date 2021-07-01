// 【参考URL】
// https://hcpc-hokudai.github.io/archive/structure_binary_indexed_tree_001.pdf

// 【ひとことコメント】
// 累積和の応用かつセグメント木の発展形！
// 値の更新が頻繁にあるとき、累積和だとTLEになる可能性がある。そんな場合に使用。

#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int bit[29];

// 番号iに数字Xを加算
void add(int i, int X) {
  while (i <= MAX) {
    bit[i] += X;
    // iに最下位ビットを加算
    i += i & -i;
  }
}

// 番号1~iの和
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    // iに最下位ビットを減算
    i -= i & -i;
  }
  return s;
}

int main() {
  int b[29];

  // 必ず番号1から始める
  // 配列の長さは2の累乗でなくても良い
  for (int i = 1; i <= MAX; ++i) b[i] = i;

  // 値の代入
  for (int i = 1; i <= MAX; ++i) add(i, b[i]);

  for (int i = 1; i <= MAX; ++i) cout << sum(i) << " ";
  cout << endl;

  for (int i = 1; i <= MAX; ++i) add(i, b[MAX + 1 - i] - b[i]);

  // 最後の数が上のと等しければ良い
  for (int i = 1; i <= MAX; ++i) cout << sum(i) << " ";
  cout << endl;


  return 0;
}