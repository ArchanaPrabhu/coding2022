#include<iostream>
using namespace std;

// n arrays yield n^2 
void printSubarrays(int arr[], int n) {
    for (int i=0;i<n;i++) {
        for (int j=i; j< n;j++) {
            for (int k =i;<=j;k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
    
}

int main() {

int arr[] = {10, 20, 30, 40, 550, 60};
intt n = sizeof(arr)/sizeof(int)
printSubarrays(arr, n);
}