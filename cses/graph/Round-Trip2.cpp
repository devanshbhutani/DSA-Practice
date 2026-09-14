#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<bool> reStack;
vector<int> parent;
int cycleStart = -1;
int cycleEnd = -1;

bool dfs(int u)
{
    vis[u] = true;
    reStack[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            parent[v] = u;

            if (dfs(v))
            {
                return true;
            }
        }
        else if (reStack[v])
        {
            cycleEnd = u;
            cycleStart = v;
            return true;
        }
    }
    reStack[u] = false;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, false);
    reStack.resize(n + 1, false);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!vis[u] && dfs(u))
        {
            break;
        }
    }

    if (cycleStart == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycleStart);

    for (int v = cycleEnd; v != cycleStart; v = parent[v])
    {
        cycle.push_back(v);
    }

    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (size_t i = 0; i < cycle.size(); i++)
    {
        cout << cycle[i] << " ";
    }
    
    cout << endl;

    return 0;
}