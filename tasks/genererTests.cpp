#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ofstream in("input");
	in << 100 << endl;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0LL, (int)1e18);
	for(int i = 0; i < 100; i++) {
		in << dis(gen) << endl;
	}
	in.close();
	system("./solution < input > output");
}
