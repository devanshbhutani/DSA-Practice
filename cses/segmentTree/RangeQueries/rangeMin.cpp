#include<bits/stdc++.h>
using namespace std; 

#define ll long long

class SegmentTree{
    private:
    vector<ll> tree; 
    vector<ll> arr;
    int n; 

    void build(int idx, int l, int r){
        if(l == r){
            tree[idx] = arr[l];
            return; 
        }
        int mid = (l+r)/2; 
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        tree[idx] = min(tree[2*idx+1],tree[2*idx+2]);
    }

    ll query(int idx, int l, int r, int ql, int qr){
        if(ql > r || qr <l) return LLONG_MAX; 
        if(ql <= l && r <= qr) return tree[idx]; 

        int mid = (l+r)/2;
        ll leftRes = query(2*idx+1, l, mid, ql, qr);
        ll rightRes = query(2*idx+2, mid+1, r, ql, qr);

        return min(leftRes,rightRes); 

    }

    public:
    SegmentTree(const vector<ll> & input){
        arr = input; 
        n = arr.size(); 
        tree.resize(4*n); 
        build(0, 0, n-1);
    }

    ll getMin(int l, int r){
        return query(0, 0, n-1, l, r);
    }
};
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int n, m; 
    cin >> n >> m;
    vector<ll> arr(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
    
    SegmentTree st(arr); 
    for (int j = 0; j < m; j++)
    {
        int l, r; 
        cin >> l >> r;
        // 1-based indexing
        l--;
        r--;
        cout << st.getMin(l, r) << endl; 
    }
    return 0; 
}