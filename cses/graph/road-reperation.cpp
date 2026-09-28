#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    vector<int> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<>
    > pq;

    pq.push({0, 1});

    long long TotalCost = 0;

    while (!pq.empty()) {

        auto [cost, node] = pq.top();
        pq.pop();

        if (vis[node]) {
            continue;
        }

        vis[node] = 1;
        TotalCost += cost;

        for (auto [neigh, edgeCost] : adj[node]) {

            if (!vis[neigh]) {
                pq.push({edgeCost, neigh});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << TotalCost << endl;

    return 0;
}