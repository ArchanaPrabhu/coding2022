#include<bits/stdc++.h>
using namespace std;

bool valid_pair(int a , int b)
{

	int n2 = (a+b)/2;
	int n1 = (a-b)/2;
 
	if(n1>=0 and n2>=0 and n2>=n1) return true;
 
	return false;
}

int solve(int n){
    int ans = 0;
    for (int i=1;i*i<n;i++) {
        if (n%i == 0) {
            int first = i, second = n/i;
            
            if ((first%2 == 0 and second%2 == 0) or  (first%2 and second%2)){
                if(valid_pair(first,second)) ans++;
				if(i*i!=n and valid_pair(second,first)) ans++;
            }
        }
    }
    return ans;
}