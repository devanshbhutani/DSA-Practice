#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll power(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * a) % mod;
        }

        a = (a * a) % mod;
        b /= 2;
    }

    return ans;
}

int main() {
    ll n;
    cin >> n;

    cout << power(2, n) << endl;

    return 0;
}