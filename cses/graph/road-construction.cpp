#include <bits/stdc++.h>
using namespace std;

vector<int> parents, ranks, len;
int components, max_len;

int find(int x) {
    if (parents[x] != x) {
        parents[x] = find(parents[x]);
    }
    return parents[x];
}

void merge(int x, int y) {

    int lx = find(x);
    int ly = find(y);

    if (lx != ly) {

        if (ranks[lx] > ranks[ly]) {

            parents[ly] = lx;
            len[lx] += len[ly];

        } 
        else if (ranks[lx] < ranks[ly]) {

            parents[lx] = ly;
            len[ly] += len[lx];

        } 
        else {

            parents[ly] = lx;
            ranks[lx]++;
            len[lx] += len[ly];
        }

        components--;

        max_len = max(max_len, max(len[lx], len[ly]));
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    parents.resize(n + 1);
    ranks.resize(n + 1, 0);
    len.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    components = n;
    max_len = 1;

    for (int i = 0; i < m; i++) {

        int x, y;
        cin >> x >> y;

        merge(x, y);

        cout << components << " " << max_len << endl;
    }

    return 0;
}