#include <bits/stdc++.h>
using namespace std;
 
int findMissing(vector<int> &arr , int n){
    int xorAll = 0, xorArr = 0;
 
    // XOR of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }
 
    // XOR of elements in the array
    for (int num : arr) {
        xorArr ^= num;
    }
 
    // Missing number
    return xorAll ^ xorArr;
}
 
int main() {
    int n;
    cin >> n; 
 
    vector<int> arr(n-1);
    for (int i = 0; i < n-1; i++) cin >> arr[i];
 
    cout << findMissing(arr, n) << endl;
    return 0;
}
