
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

    if(ans.size() == n){
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl; 
    }else{
        cout << "IMPOSSIBLE" << endl; 
    }
    
    return 0;
}