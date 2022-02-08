// https://leetcode.com/problems/remove-invalid-parentheses/
#include<iostream>
using namespace std;

vector<string> res;
int getMinValid(string s) {

	stack<char> st;

	int i=0;
	while(i<s.size()) {
		if (s[i] == '(') {
			st.push('(');
		} else if (s[i] == ')') {
			if (st.size() > 0 && st.top() == '(') {
				st.pop();
			} else {
				st.push(')');
			}
		}
		i++;
	}
	return stck.size();
}

//recursion
int solve(string s, int interval) {
	if (interval < 0) {
		return;
	}

	if (interval == 0) { // this happens when the stack is empty. 
		if (!getMinValid(s)) { // Do we have to check again? Yes we do. interval can be 0 while recursing and the string s might be imbalanced. So check it. 
			res.push_back(s);
		}
		return;
	}

	for (int i=0;i<s.size(); i++) {
		string left = s.substr(0, i);
		string right = s.substr(i+1, s.size());

		// assuming that the excluded bracket is invalid, deduct 1 from interval
		solve(left + right, interval -1);

	}
}