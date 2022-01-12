// using precomputed table -> creation takes O(NloglogN)
// query time -> O(log(N))

#include<iostream>
#include<vector>
using namespace std;

#define N 1000000


#include<iostream>
#include<vector>
using namespace std;
#define N 1000000
#define ll long long

// O(Nlog log N)
void primeSieve(vector<int> &sieve){

	for(int i=1; i<=N; i++){
		sieve[i] = i; 
	}

	//start from 2 to N
	for(ll i=2; i<=N; i++){
		//whether a no is prime 
		if(sieve[i]==i){

			// for every i, mark the multiples from i*i, only for the unmarked ones.
			// unmarked if sieve[j] == j
			for(ll j= i*i; j<=N; j = j + i){
				//mark of them if they are already not marked with the value i
				if(sieve[j]==j){
					sieve[j] = i;
				}
			}
		}
	}

}

// O(log N)
// whenever we want to find the prime factors of N
vector<int> getFactorisation(int number, vector<int> &sieve){
	vector<int> factors;
	while(number!=1){
		factors.push_back(sieve[number]);
		number = number/sieve[number];
	}
	return factors;
}


int main(){

	//Prime Sieve (NLogLogN)
	vector<int> sieveArr(N+1,0); // init with 0
	primeSieve(sieveArr); // pass by reference

	int number;
	cin>>number;
	// Method for multiple queries  (O(LogN))
	vector<int>  factors = getFactorisation(number,sieveArr);
	for(int f : factors){
		cout << f <<",";
	}

	return 0;
}