#include<bits/stdc++.h>
using namespace std; 


int main(){
    int n , m; // reading input
    cin >> n >> m ; 

    vector<int> nums(n); // making of the array numbers of coins 
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; 
    }

    const int INF = 1e9; 
    vector<int> dp(m+1, INF); // making of dp vector initializing with infinity because we have to find the minimum no. , also the size of the dp array is m+1 because we are starting form back right form the target like dp[11] in the given example.

    dp[0] = 0; // to make zero we need zero coin.
    for (int i = 1; i <= m; i++) // running it to m times because we start with dp[1] to dp[target=m]
    {
        for(auto coin : nums){
            if(i - coin >= 0 && dp[i - coin] != INF){ 
                dp[i] = min(dp[i], dp[i-coin]+1); 
            }
        }
        
    }
    if(dp[m]==INF){
        cout << -1 << endl; 
    }else{
        cout << dp[m] << endl; 
    }
   
    return 0;
}