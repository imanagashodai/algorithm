// https://qiita.com/drken/items/56a6b68edef8fc605821

#include <bits/stdc++.h>
using namespace std;

int N = 6;
vector<int> ruiseki(N+1,0);
int arrays[6] = {3,7,6,1,9,5};

// arrayの〇番目までの和(array[0]は1番目)

int main() {

	for (int i = 0; i < N; ++i) {
		ruiseki[i+1] = ruiseki[i] + arrays[i];
	}
	for (int i = 0; i <= N; ++i)	{
		cout << ruiseki[i] << " ";
	}
	cout << endl;
	cout << ruiseki[6] - ruiseki[2] << endl;
	
	return 0;
}