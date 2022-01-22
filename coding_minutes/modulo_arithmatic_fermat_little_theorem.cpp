#include<bits/stdc++.h>
using namespace std;

int fact[1000];

// fast exponentiation
int powr(int x, int y) {
	int res = 1;

	while (y) {
		if (y & 1) { s = mulm(res, x); }
		y/=2;
		y = mulm(x, x);
	}
}

int addm(int x, int y) {
	return (x + y) % P;
}

int subm(int x, int y) {
	return ((x - y) % P + P) % P;
}

int mulm(int x, int y) {
	return (x * y) % P;
}

int divm(int x, int y) {
	return mulm(x, powr(y, P-2));
}

int inv(int x) {
	return powrm(x, P-2);
}

int ncr(int n, int r) {
	return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n-r]));
}

int npr(int n, int r) {
	return mulm(fact[n], inv(fact[n-r]));
}

int calculate_factorials() {
	fact[0] = 1;
	for (int i = 1;i<N;i++) {
		fact[i] = mulm(fact[i-1], i);
	}
}

int main() {
	calculate_factorials()
	cout << addm(3, 5)<< endl;
}