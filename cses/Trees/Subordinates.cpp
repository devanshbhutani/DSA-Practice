#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &ans) {
    ans[node] = 1;

    for (auto neigh : adj[node]) {

        if (neigh != parent) {

            dfs(neigh, node, adj, ans);

            ans[node] += ans[neigh];
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;

        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    vector<int> ans(n + 1);

    dfs(1, -1, adj, ans);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << " ";
    }

    cout << endl;

    return 0;
}