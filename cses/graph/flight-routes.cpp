
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    vector<vector<long long>> dist(n + 1);

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u].size() >= static_cast<size_t>(k))
            continue;

        dist[u].push_back(d);

        for (auto [v, w] : adj[u]) {
            pq.push({d + w, v});
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }

    cout << '\n';

    return 0;
}