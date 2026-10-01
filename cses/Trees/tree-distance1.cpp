#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(int node, int parent, vector<vector<ll>> &adj, vector<ll> &dist)
{
    for (auto neigh : adj[node])
    {
        if (neigh != parent)
        {
            dist[neigh] = dist[node] + 1;
            dfs(neigh, node, adj, dist);
        }
    }
}
int main()
{
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dist1(n + 1), dist2(n+1);
    dfs(1, -1, adj, dist1);
    ll firstendpoint = -1;
    ll maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist1[i] > maxi)
        {
            maxi = dist1[i];
            firstendpoint = i;
        }
    }
    dist1.assign(n + 1, 0);
    dfs(firstendpoint, -1, adj, dist1);

    ll secondendpoint = 0;
    maxi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (dist1[i] > maxi)
        {
            maxi = dist1[i];
            secondendpoint = i;
        }
    }

    dfs(secondendpoint, -1, adj, dist2);

    vector<ll> res(n+1);
    for (int i = 1; i <= n; i++)
    {
        res[i] = max(dist1[i], dist2[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}