#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<ll> g(n + 1);
    g[1] = x;

    for (int i = 2; i <= n; i++)
        g[i] = (a * g[i - 1] + b) % c;

    ll start = 1, end = 1, cnt = 0, sum = 0, ans = 0;

    while (end <= n) {
        if (cnt == k) {
            ans ^= sum;
            sum -= g[start++];
            cnt--;
        } else {
            sum += g[end++];
            cnt++;
        }
    }

    if (cnt == k) ans ^= sum;

    cout << ans << '\n';
}