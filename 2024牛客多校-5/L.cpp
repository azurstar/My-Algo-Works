#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <numeric>

#define fi first
#define se second

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const ull P = 131;
const double eps = 1e-4;
const int N = 110, mod = 998244353;


void solve() {
    ll n;
    scanf("%lld", &n);
    ll a[n+1];
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        //s[i] = a[i] + s[i-1];
    }

    priority_queue<ll, vector<ll>, greater<ll> > hp;
    for (int i=1; i<=n; i++) {
        if (hp.size()) {
            while (hp.top() < a[i] - 1) {
                a[i] --;
                ll t = hp.top();
                hp.pop();
                hp.push(t + 1);
            }
        }
        hp.push(a[i]);
    }
    ll res = 1;
    while (hp.size()) {
        res = res * hp.top() % mod;
        hp.pop();
    }
    printf("%lld\n", res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // multiple case
    int t; scanf("%d", &t);
    while(t--) {
        solve();
    }

    // single case
    // solve();

    return 0;
}
