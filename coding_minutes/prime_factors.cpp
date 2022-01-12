#include<bits/stdc++.h>
using namespace std;

// O(N)

void findPrimeFactors(int N) {
	int count = 0;
	for (int i=0;i<N;i++) {
		if (N % i == 0) {
			count = 0;
			while (N % i == 0) {
				N = N/i;
				count++;
			}
			cout << i << " " << count << endl;
		} 
	}
}

void main() {
	int N = 100;
	findPrimeFactors(N);
}