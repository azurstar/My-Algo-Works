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
const int N = 0;

ll n, k;

void solve() {
    scanf("%lld%lld", &n, &k);
    if (k > n - k) k = n - k;
    ll res = 0;
    if (k == n - k) {
        res = n;
    }
    else {
        res = k * n + 1;
    }
    printf("%lld\n", res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // multiple case
    // int t; scanf("%d", &t);
    // while(t--) {
    //     solve();
    // }

    // single case
    solve();

    return 0;
}
