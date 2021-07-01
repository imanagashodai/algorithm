#include <bits/stdc++.h>
using namespace std;

int v = 4; // 都市数
int e = 5; // 道路数
int r = 0; // 開始地点
int es[5][3] = {{2,0,4},{1,2,2},{0,1,1},{1,3,5},{2,3,1}};
int d[4]; // この地点への距離

int main() {
  for (int i = 0; i < v; ++i) {
    if (i == r) d[i] = 0;
    else d[i] = 100000;
  }

  priority_queue<int, vector<int>, greater<int>> pque;

  pque.push(r * 1000); // 距離*1000+現在地

  int nex;
  int dd;
  int cur;

  while (!pque.empty()) {
    cur = pque.top();
    pque.pop();
    for (int i = 0; i < e; ++i) {
      if (es[i][0] == cur % 1000 || es[i][1] == cur % 1000) {
        if (es[i][0] == cur % 1000) nex = es[i][1];
        else nex = es[i][0];
        dd = es[i][2] + cur / 1000;
        if (dd < d[nex]) {
          d[nex] = dd;
          pque.push(d[nex] * 1000 + nex);
        }
      }
    }
  }

  for (int i = 0; i < v; ++i) {
    if (d[i] == 1000) cout << "INF" << endl;
    else cout << d[i] << endl;
  }

  return 0;
}