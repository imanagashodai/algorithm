#include <bits/stdc++.h>
using namespace std;

int a, b;

long long mem[109][109];
long long combi(int le, int ri) {
	if (mem[le][ri] != 0) return mem[le][ri];
	if (le == ri) return mem[le][ri] = 1;
	if (ri == 1) return mem[le][ri] = le;
	return mem[le][ri] = combi(le - 1, ri) + combi(le - 1, ri - 1);
}

int main() {
	while (true) {
		cin >> a >> b;
		cout << combi(a, b) << endl;;
	}
	return 0;
}
