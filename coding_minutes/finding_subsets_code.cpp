#include<bits/stdc++.h>
using namespace std;

void findSubsets(char * input, char * output, int i, int j) {
	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	output[j] = input[i]; // include the ith character. if it is not \0

	findSubsets(input, output, i + 1, j + 1);
	findSubsets(input, output, i + 1, j);

}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char input[100];
	char output[1000];

	cin >> input;
	findSubsets(input, output, 0, 0);

return 0; 
}

/*

					a b c
			a					   ""
	ab			a 			b 	   		  ""
abc		ab	ac 		a    bc 	b 	   c 	   ""

*/