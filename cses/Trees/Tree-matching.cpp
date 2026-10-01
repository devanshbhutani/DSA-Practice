#include<bits/stdc++.h>
using namespace std; 

#define ll long long 

void dfs(int node, int parent, vector<vector<ll>> &adj, vector<int> &vis, ll &cnt){
    for(auto neigh: adj[node]){
        if(neigh!=parent){
            dfs(neigh, node, adj, vis, cnt);
            if(!vis[neigh] && !vis[node]){
                cnt++;
                vis[neigh] =1 ;
                vis[node] =1;
            }
        }
    }

}

int main(){
    ll n ; cin >> n; 

    vector<vector<ll>> adj(n+1); 
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll cnt= 0; 
    vector<int> vis(n+1);
    dfs(1,-1, adj, vis, cnt); 

    cout << cnt << endl; 
    return 0;
}