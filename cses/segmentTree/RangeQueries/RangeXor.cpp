#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
private:
    vector<ll> tree;
    vector<ll> arr;
    ll n;

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);

        tree[idx] = tree[2 * idx + 1]^
                        tree[2 * idx + 2];
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        // No overlap
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return tree[idx];

        int mid = (l + r) / 2;

        ll left_res = query(2 * idx + 1, l, mid, ql, qr);
        ll right_res = query(2 * idx + 2, mid + 1, r, ql, qr);

        return left_res ^right_res;
    }
public:

    SegmentTree(const vector<ll>& input) {
        arr = input;
        n = arr.size();

        tree.resize(4 * n);

        build(0, 0, n - 1);
    }

    ll getXOR(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    for (int j = 0; j < m; j++)
    {
        ll a, b; 
        cin >> a >> b; 
        a--; 
        b--;
        cout << st.getXOR(a,b) << endl;
    }
    
    return 0;
}