#include<bits/stdc++.h>
using namespace std; 

#define ll long long 
int main(){
    ll n, k; 
    cin >> n >> k; 

    ll x, a, b, c; 
    cin >> x >> a >> b >> c; 

    vector<ll> nums(n); 
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            nums[i] = x; 
        }else{
            nums[i] = (a*nums[i-1] + b)% c; 
        }
    }

    int i = 0; 
    ll window = 0; 
    ll ans = 0; 
    for (int j = 0; j < n; j++)
    {
        window ^= nums[j]; 
        if (j-i+1 == k)
        {
            ans^= window;
            window^= nums[i]; 
            i++; 
            
        }
    }
    cout << ans << endl; 
    
    return 0; 

}