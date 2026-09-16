#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long wt;

        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }

    // dp[v][0] = shortest distance
    // dp[v][1] = number of shortest routes
    // dp[v][2] = maximum flights among shortest routes
    // dp[v][3] = minimum flights among shortest routes

    vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = INF;
        dp[i][3] = INF;
    }

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    pq.push({0, 1});

    while (!pq.empty()) {

        auto [dist, node] = pq.top();
        pq.pop();

        if (dist > dp[node][0])
            continue;

        for (auto [neigh, wt] : adj[node]) {

            long long newDist = dist + wt;

            // Found a shorter route
            if (newDist < dp[neigh][0]) {

                dp[neigh][0] = newDist;

                dp[neigh][1] = dp[node][1];

                dp[neigh][2] = dp[node][2] + 1;

                dp[neigh][3] = dp[node][3] + 1;

                pq.push({newDist, neigh});
            }

            // Found another shortest route
            else if (newDist == dp[neigh][0]) {

                dp[neigh][1] =
                    (dp[neigh][1] + dp[node][1]) % MOD;

                dp[neigh][2] =
                    max(dp[neigh][2], dp[node][2] + 1);

                dp[neigh][3] =
                    min(dp[neigh][3], dp[node][3] + 1);
            }
        }
    }

    cout << dp[n][0] << " "
         << dp[n][1] << " "
         << dp[n][3] << " "
         << dp[n][2] << '\n';

    return 0;
}