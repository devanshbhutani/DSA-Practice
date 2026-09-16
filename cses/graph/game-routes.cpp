
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q; 
    for (int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0){
            q.push(i); 
        }
    }
    vector<int> ans; 
    while (!q.empty())
    {
        auto node = q.front(); 
        q.pop(); 
        ans.push_back(node); 
        for(auto v : adj[node]){
            indegree[v]--; 
            if (indegree[v] == 0)
            {
                q.push(v); 
            }
            
        }
    }

    vector<int> dp(n+1, 0); 
    dp[1] = 1; 
    for(auto u : ans){
        for(auto v : adj[u]){
            dp[v] = (dp[u]+dp[v])%mod;
        }
    }

    cout << dp[n] << endl; 
    return 0;
}