#include <bits/stdc++.h>
using namespace std;

#define int long long

const int oo = 1e9 + 7;

typedef vector<vector<int>> Matrix;

Matrix multiply(Matrix A, Matrix B) {
	Matrix C(2, vector<int>(2, 0));
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

Matrix mod(Matrix A) {
	Matrix B = A;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			B[i][j] = A[i][j] % (+oo);
		}
	}
	return B;
}

const Matrix Id = {{1, 0}, {0, 1}};

Matrix fastExpo(Matrix A, int n) {
	Matrix res = Id;
	while(n > 0) {
		if(n % 2 == 1)
			res = multiply(res, A);
		n /= 2;
		A = multiply(A, A);
		A = mod(A);
		res = mod(res);
	}
	return mod(res);
}

const Matrix transition = {{0, 1}, {1, 1}};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	for(int test = 0; test < T; test++) {
		int n;
		cin >> n;
		Matrix M = fastExpo(transition, n);
		cout << M[0][0] * 0LL + M[0][1] * 1LL;
		if(test != T-1)
			cout << endl;
	}
}
