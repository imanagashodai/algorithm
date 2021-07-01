// https://atcoder.jp/contests/typical90/tasks/typical90_i

#include <bits/stdc++.h>
using namespace std;

struct vec {
	int x, y;
};

// マイナスの例。必要になったら付け足す
vec operator-(vec a, vec b) {
	return {a.x - b.x, a.y - b.y};
}

int main() {
	vec ren = {4, 2};
	cout << (ren - ren).x << " " << (ren - ren).y << endl;
	
	return 0;
}