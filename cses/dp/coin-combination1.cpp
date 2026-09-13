#include<bits/stdc++.h>
using namespace std; 

const int mod = 1e9+7; 
int main(){
    int n , m ; 
    cin >> n >> m ; 
    vector<int> coins(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i]; 
    }

    vector<int> dp(m+1, 0); 
    dp[0] = 1; 
    for(int i = 1; i <= m; i++){
        for(auto c : coins){
            if(i -c >=0)
            dp[i] = (dp[i]+dp[i-c])% mod; 
        }
    }
    cout << dp[m] << endl; 
    return 0;
}