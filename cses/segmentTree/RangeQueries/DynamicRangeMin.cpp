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

        tree[idx] = min(tree[2 * idx + 1],
                        tree[2 * idx + 2]);
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        // No overlap
        if (r < ql || l > qr)
            return LLONG_MAX;

        if (ql <= l && r <= qr)
            return tree[idx];

        int mid = (l + r) / 2;

        ll left_res = query(2 * idx + 1, l, mid, ql, qr);
        ll right_res = query(2 * idx + 2, mid + 1, r, ql, qr);

        return min(left_res, right_res);
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            arr[l] = val;
            tree[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx + 1, l, mid, pos, val);
        }
        else {
            update(2 * idx + 2, mid + 1, r, pos, val);
        }

        tree[idx] = min(tree[2 * idx + 1],
                        tree[2 * idx + 2]);
    }

public:

    SegmentTree(const vector<ll>& input) {
        arr = input;
        n = arr.size();

        tree.resize(4 * n);

        build(0, 0, n - 1);
    }

    ll getMin(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void setValue(int pos, ll val) {
        update(0, 0, n - 1, pos, val);
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

    for (int j = 0; j < m; j++) {

        ll t;
        cin >> t;

        if (t == 1) {
            ll i, v;
            cin >> i >> v;
            i--;

            st.setValue(i, v);
        }
        else {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;

            cout << st.getMin(l, r) << '\n';
        }
    }

    return 0;
}