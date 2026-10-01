#include<bits/stdc++.h>
using namespace std;

#define ll long long


void dfs(int node, int parent , vector<vector<ll>> &adj, vector<ll> &dist){
    for(auto neigh : adj[node]){
        if(neigh != parent){
            dist[neigh] = dist[node]+1;
            dfs(neigh, node, adj, dist); 
        }
    }
}
int main(){
    ll n ; cin >> n;

    vector<vector<ll>> adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u , v; 
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<ll> dist(n+1);
    dfs(1,-1,adj,dist);
    ll firstendpoint = -1; 
    ll maxi = 0; 
    for (int i = 1; i <= n; i++)
    {
        if (dist[i]> maxi)
        {
            maxi = dist[i];
            firstendpoint = i;
        }
        
    }
    dist.assign(n+1,0);
    dfs(firstendpoint, -1, adj, dist); 
    ll diameter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i]> diameter)
        {
            diameter = dist[i];
        }
        
    }
    
    cout << diameter << endl;
    return 0;
}