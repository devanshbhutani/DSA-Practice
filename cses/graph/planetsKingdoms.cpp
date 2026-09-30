#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, reverseGraph;
vector<int> Vis;
stack<int> FinishOrder;

void dfs(int node) {

    Vis[node] = true;

    for (auto neigh : graph[node]) {
        if (!Vis[neigh]) {
            dfs(neigh);
        }
    }

    FinishOrder.push(node);
}

void dfsReverse(int node, vector<int>& component) {

    Vis[node] = true;
    component.push_back(node);

    for (auto neigh : reverseGraph[node]) {

        if (!Vis[neigh]) {
            dfsReverse(neigh, component);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    reverseGraph.resize(n + 1);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }


    Vis.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!Vis[i]) {
            dfs(i);
        }
    }

    Vis.assign(n + 1, 0);

    vector<int> kingdom(n + 1, 0);

    int currentKingdom = 1;

    while (!FinishOrder.empty()) {

        int u = FinishOrder.top();
        FinishOrder.pop();

        if (!Vis[u]) {

            vector<int> component;

            dfsReverse(u, component);

            for (int node : component) {
                kingdom[node] = currentKingdom;
            }

            currentKingdom++;
        }
    }

    cout << currentKingdom - 1 << endl;

    for (int i = 1; i <= n; i++) {
        cout << kingdom[i] << " ";
    }

    cout << endl;

    return 0;
}