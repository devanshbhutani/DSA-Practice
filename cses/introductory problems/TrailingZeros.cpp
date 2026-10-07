#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// const ll mod = 1e9 + 7;
 
int main() {
    ll n ; cin >> n; 
    ll total = 0; 
    while(n>0){
        n/=5; 
        total += n; 
    }
    cout << total << endl ;
    return 0;
}