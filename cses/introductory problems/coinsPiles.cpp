#include<bits/stdc++.h>
using namespace std; 

#define ll long long 
int main(){
    ll n; cin >> n; 

    while (n--)
    {
        ll a, b; 
        cin >> a >> b; 
        cout << ((a+b)%3==0 && 2*a>=b && 2*b>=a ? "YES" : "NO") << endl; 
    }
    
}