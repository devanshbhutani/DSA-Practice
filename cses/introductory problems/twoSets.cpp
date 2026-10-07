#include<bits/stdc++.h>
using namespace std; 

#define ll long long
int main(){

    ll n; cin >> n; 
    ll sum = n*(n+1)/2; ; 
    
    if(sum%2 !=0){
        cout << "NO" << endl; 
        return 0; 
    } 
   
    cout << "YES" << endl; 
    ll target = sum/2; 
    vector<ll> set1, set2; 
    for (ll i = n; i>=1; i--)
    {
        if(target >= i){
            set1.push_back(i); 
            target-=i; 
        }else{
            set2.push_back(i); 
        }
    }
    cout << set1.size() << endl; 
    for(auto it : set1){
        cout << it << " "; 
    }
    cout << endl; 
    cout << set2.size() << endl; 
    for(auto it : set2){
        cout << it << " "; 
    }
    cout << endl ;
    
    return 0;
}