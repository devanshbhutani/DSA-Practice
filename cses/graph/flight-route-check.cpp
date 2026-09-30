#include<bits/stdc++.h>
using namespace std; 

void dfs(int node, vector<vector<int>> &graph, vector<int> &Vis){
    if(Vis[node]) return ; 
    Vis[node] = true; 

    for(auto neigh : graph[node]){
        if(!Vis[neigh]){
            dfs(neigh, graph, Vis); 
        }
    }
}
int main(){
    int n, m; 
    cin >> n >> m; 

    vector<vector<int>> graph(n+1);
    vector<vector<int>> reverseGraph(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v; 
        cin >> u >> v; 

        graph[u].push_back(v);
        reverseGraph[v].push_back(u); 
    }

    vector<int> Vis(n+1,0); 

    dfs(1,graph, Vis); 
    for (int i = 1; i <=n; i++)
    {
        if(!Vis[i]){
            cout << "NO" << endl; 
            cout << 1 << " " << i << endl;
            return 0; 
        }
    }
    fill(Vis.begin(), Vis.end(), 0); 
    dfs(1, reverseGraph, Vis); 
    for (int i = 1; i <= n; i++)
    {
        if (!Vis[i])
        {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0; 
        }
        
    }

    cout << "YES"; 
    cout << endl; 
    return 0; 
}