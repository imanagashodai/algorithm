// 【参考URL】
// https://www.slideshare.net/hcpc_hokudai/rmq-47663507

// 【ひとことコメント】
// Range Minimum Query。つまり「区間最小値」のこと。
// 区間内で何度もminを知りたいときに使用。

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

// 区間は必ず2の累乗以上をとる。
// BITと違い、0番目から数える。
int dat[2009];

// RMQ用のセグメント木作成。
// 配列、配列のサイズを代入。
void dat_junbi(vector<int> Vec, int Sz) {
  int Sz2 = 1;
  // 2の累乗のうち、Sz以上のものの最小値
  while (Sz2 <= Sz) Sz2 <<= 1;
  for (int i = 0; i < Sz; ++i) dat[Sz2 - 1 + i] = Vec[i];
  for (int i = Sz; i < Sz2; ++i) dat[Sz2 - 1 + i] = INF;
  for (int i = Sz2 - 2; i >= 0; --i) dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
}

// [Le, Ri]における最小値
int rmq(int Le, int Ri, int Sz) {
  int Sz2 = 1;
  while (Sz2 <= Sz) Sz2 <<= 1;
  int Mini = INF;
  Le += Sz2 - 1;
  Ri += Sz2 - 1;
  while (Ri - Le >= 0) {
    Mini = min({Mini, dat[Le], dat[Ri]});
    Le = Le / 2;
    Ri = Ri / 2 - 1;
  }
  return Mini;
}


int main() {
  // 下準備
  vector<int> v;
  int v_sz = 20;
  for (int i = 0; i < v_sz; ++i) v.push_back(i * 4 % 23);
  for (int i = 0; i < v_sz; ++i) cout << v[i] << " ";
  cout << endl;

  // RMQ実装
  dat_junbi(v, v_sz);
  for (int i = 3; i < v_sz; ++i) cout << rmq(i - 3, i, v_sz) << " ";
  cout << endl;

  return 0;
}