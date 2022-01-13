#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define N 1000000

// complexity of prime sieve = O(NloglogN)
void primeSieve(vector<int> &sieve) {
	sieve[1] = sieve[0] = 0;

	// an optimization is to make sure we mark all the odd numbers as prime

	// start from 2 and mark all multiples of ith number as non prime
	for (ll i=2;i<=N;i++) {
		if(sieve[i]) {
			for (ll j = i*i; j<=N; j = j+i) {
				sieve[j] = 0;
			}
		}
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n; 

	vector<int> sieve(N, 1); // fill constructor
	primeSieve(sieve); // pass by reference

	for (int i = 0; i<100;i++) {
		if (sieve[i]) {
			cout << i << " ";
		}
	}
	return 0;
}