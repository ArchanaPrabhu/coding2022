#include<bits/stdc++.h>
using namespace std;

// O(Sqrt(N))
// once N is reduced a prime number, only the number is divisible by it.
// if a number does not have any factor till √N, then the number is a prime number.

void findPrimeFactors(int N) {
	int count = 0;
	for (int i=2;i*i<=N;i++) {
		cout << "debug log : " << i*i << endl;
		if (N % i == 0) {
			count = 0;
			while (N % i == 0) {
				N = N/i;
				count++;
			}
			cout << i << "^" << count << endl;
		} 
	}

	if (N != 1) {
		cout << N << "^" << 1 << endl;
	}
}

int main() {
	int N = 100;
	findPrimeFactors(N);
}

// output
/*

debug log : 4
2^2
debug log : 9
debug log : 16
debug log : 25
5^2

*/