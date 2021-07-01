// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-4-%E5%B9%85%E5%84%AA%E5%85%88%E6%8E%A2%E7%B4%A2


#include <bits/stdc++.h>
using namespace std;

int N = 5; // 都市数
int M = 5; // 道路数
int A[5] = {1,1,2,3,4};
int B[5] = {2,3,4,4,5};

int main() {
	int INF = N;
	int d[M];
	int cur;
	queue<int> que;

	for (int i = 0; i < M; ++i) d[i] = (i ? INF : 0);
	que.push(1);

	while (!que.empty()) {
		cur = que.front();
		que.pop();
  
	  for (int i = 0; i < M; ++i) {
	  	if (A[i] == cur) {
	  		if (d[B[i] - 1] == INF) {
	  			que.push(B[i]);
	  			d[B[i]-1] = d[A[i]-1] + 1;
	  		}
	  	}

	  	if (B[i] == cur) {
	  		if (d[A[i] - 1] == INF) {
	  			que.push(A[i]);
	  			d[A[i]-1] = d[B[i]-1] + 1;
	  		}
	  	}
	  }
	}

  for (int i = 0; i < N; ++i) {
  	cout << d[i] << endl;
  }

  return 0;
}
