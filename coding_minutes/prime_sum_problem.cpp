#include<bits/stdc++.h>
using namespace std;

int solve(int N){
    vector<int> v(N+1, 1);
    
    for(int i=2;i<=N;i++) {
        if (v[i]) { 
            for (int j=i*i;j<=N;j += i) {
                v[j] = 0;
            }
        }
    }
    
    int count = 0;
    for (int i=3;i<=N;i++) {
        if (v[i]) {
            int checkVal = i + 2;
            if (checkVal <=N && v[checkVal]) { 
                // cout << i << " " << 2 << endl;
                count++; }
        }
    }
    
    return count;
}

int main() {
    
    int n;
    cin >> n;
    cout << solve(n) <<endl;


    return 0;
}