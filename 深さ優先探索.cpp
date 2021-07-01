// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-3-%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%85%A8%E6%8E%A2%E7%B4%A2

#include <bits/stdc++.h>
using namespace std;

int N = 3, M = 3;

// 再帰関数
// void func(string cur) {
//   if (cur.size() == N) { cout << cur << endl; return; }
//   int last = 1;
//   if (cur.size() >= 1) {
//     last = cur[cur.size()-1] - '0';
//   }
//   for (int i = last; i <= M; ++i) {
//     string nex = cur; nex += to_string(i);
//     func(nex);
//   }
// }

// int main() {
//   for (int i = 1; i <= M; ++i) func(to_string(i));

//   return 0;
// }

// スタック
string cur;

int main() {
  stack<string> st;
  st.push("");
  while (!st.empty()) {
    cur = st.top();
    st.pop();
    if (cur.empty()) {
      for (int i = M; i >= 1; --i) {
        st.push(to_string(i));
      }
    } else if (cur.size() == N) {
      cout << cur << endl;
    } else {
      for (int i = M; i >= cur[cur.size()-1] - '0'; --i) {
        st.push(cur + to_string(i));
      }
    }
  }

  return 0;
}