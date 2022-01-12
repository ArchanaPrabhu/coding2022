#include<bits/stdc++.h>
using namespace std;
#define N 100000

// 0 .. 10^9
// query range 10^5

// we have a precomputed array in which we mark if a number is prime or not
// we mark all the numbers that are not prime.
//we try to find one divisor of N that is present in the range 0 .. √N



int sieveArr[N+1] = {0};


vector<int> primes; // we have a vector known as primes 

void sieve() {
	for (long long i = 2; i<=N; i++) {
		if(sieveArr[i] == 0) {
			primes.push_back(i);
			for (long long j = i*i;j<=N;j+=i) {
				sieveArr[j] = 1;
			}
		}
	}
}


int main() {
	sieve();

	int t;
	cin >> t;

	while(t--) {
		int m, n;
		cin >> m >> n;

		vector<int> segment(n-m+1, 0);

		for (auto p : primes) {
			// stop when p^2 > n
			if (p*p > n) {
				break;
			}

			//otherwise we need to find the nearest starting multiple >= m
			int start = (m/p)*p; // IMPORTANT

			// when value of m < sieve, then we get (m/p)*p as 0.
			// hence when m <p, start = 2*p = p+p
			if (p >= m and p <= n) {
				start = 2*p;
			}

			for (int j= start;j<=n;j+=p) {
				if (j < m) {
					continue;
				}
				segment[j-m] = 1; // mark it as not prime.
			}

		}

		// segment starts with 0 index
		for (int i=m;i<=n;i++) {
			if (segment[i-m] == 0 and i!=1) {
				cout << i << endl;
			}
		}
		
		cout << endl;
	}
	return 0;
}