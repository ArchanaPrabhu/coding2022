#include<bits/stdc++.h>
using namespace std;

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
	return mulm(x, powr(y, p-2));
}

int main() {

	cout << addm(3, 5)<< endl;
}