
#include <bits/stdc++.h>
using namespace std;

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

    vector<int> dp(n+1, INT_MIN); 
    vector<int> parent(n+1, -1);
    dp[1] = 1; 
    for(auto u : ans){
        if(dp[u] == INT_MIN) continue;
        for(auto v : adj[u]){
            if(dp[v]< dp[u] + 1){
                dp[v] = dp[u]+1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE" << endl; 
        return 0; 
    }

    vector<int> path; 
    int curr = n; 
    while (curr != -1)
    {
        path.push_back(curr); 
        curr = parent[curr]; 
    }
    reverse(path.begin(), path.end()); 
    cout << path.size() << endl ;
    for(auto node : path){
        cout << node << " ";
    }
    cout << endl; 
    
    return 0;
}