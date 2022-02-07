// given a number convert it to the smallest version - this includes negative numbers

#include<bits/stdc++.h>
using namespace std;

long long smallestNumber(long long num) {
	string s = to_string(abs(num));
	if (num > 0) {
		sort(s.begin(), s.end());
	} else {
		sort(s.begin(), s.end(), greater<char>());
	}

	if (num > 0) {
		int i = s.find_first_not_of('0');
		swap(s[0], s[i]);
	}

	long long ans = stoll(s);

	if (num <0) { ans*=-1; }
	
	return num;

}