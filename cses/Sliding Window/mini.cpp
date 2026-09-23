#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> nums(n);

    // Generate array
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            nums[i] = x;
        } else {
            nums[i] = (a * nums[i - 1] + b) % c;
        }
    }

    deque<pair<ll, int>> dq;

    int i = 0;
    ll ans = 0;

    for (int j = 0; j < n; j++) {

        // Remove elements larger than current element
        while (!dq.empty() && dq.back().first > nums[j]) {
            dq.pop_back();
        }

        dq.push_back({nums[j], j});

        if (j - i + 1 < k) {
            continue;
        }

        // Minimum of current window
        ans = ans ^ dq.front().first;

        // Remove outgoing element
        if (dq.front().second == i) {
            dq.pop_front();
        }

        i++;
    }

    cout << ans << endl;

    return 0;
}