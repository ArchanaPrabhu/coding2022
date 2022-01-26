#include<bits/stdc++.h>
using namespace std;


int getIthBit(int n, int i) {
	int mask = 1<<i;
	return (n & mask) > 0 ? 1 : 0;
}

void setIthBit(int n, int i) {
	int mask = 1<<i;
	n = n | mask;
}

void clearIthBit(int n, int i) {
	int mask = 1 << i;
	mask = ~mask;
	n = n & mask;
}

void clearBitsInRange(int &n, int i, int j) {
	int a = (~0)<<(j+1);
	int b = (1<<i)-1;
	int mask = a|b;
	n = n&mask;
}

void replaceBits(int &n, int i, int j, int m) {
	clearBitsInRange(n, i, j);
	int mask = m<<i;
	n = n | mask;
}

void checkIfPowerOf2(int n) {
/**
16 -> 10000
15 -> 01111
16&15 == 0
*/

	if (n & (n-1) == 0) {
		cout << "Power of 2" << endl;
	}
}

int main() {

}