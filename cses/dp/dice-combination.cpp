#include<bits/stdc++.h>
using namespace std; 

const int mod = 1e9 + 7; 

// solved using memoization
int solveMem(int n, vector<int> &dp){
    if(n == 0){
        return 1; 
    }
    if (dp[n]!= -1)
    {
        return dp[n];
    }

    int ways = 0; 
    for (int i = 1; i <= 6; i++)
    {
        if (n-i >= 0)
        {
            ways = (ways+ solveMem(n-i,dp))%mod; 
        }
        
    }
    return dp[n] = ways; 
    
}
int main(){
    int n ; cin >> n; 

    // vector<int> dp(n+1, -1);
    // int ans = solveMem(n, dp);
    // cout << ans << endl; 


    // solve using tabulation 
    vector<int> dp(n+1, 0); 
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if(i-j >=0) {
                dp[i] = (dp[i] + dp[i-j])%mod; 
            }
        }
    }
    cout << dp[n] << endl; 


    

    return 0;
}