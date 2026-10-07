#include<bits/stdc++.h>
using namespace std; 

#define ll long long
int main(){

    int t; cin >> t; 
    for (int i = 1; i <= t; i++)
    {
        ll t_cells = i*i; 
        if(i==1){
            cout << 0 << endl; 
        }else{
            ll total = (t_cells*(t_cells-1))/2; 
            ll slabs = 4*(i-1)*(i-2); 
            ll ans = total - slabs;
            cout << ans << endl;  
        }
    }
    return 0;
}