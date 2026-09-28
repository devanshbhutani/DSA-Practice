#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
 
    int curr_len = 1, max_len = 1;
 
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            curr_len++;
        } else {
            curr_len = 1;
        }
        max_len = max(max_len, curr_len);
    }
    
    cout << max_len << endl;
    return 0;
}