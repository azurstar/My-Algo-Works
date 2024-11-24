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
using pii = pair<ll, ll>;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const ull P = 131;
const double eps = 1e-4;
const int N = 2e5 + 10;

vector<vector<pii>> e0(N);
vector<vector<int>> e(N);
int c[N], dep[N];
int n;

// dep[1] = 1;
void dfs0(int u, int p) {
    dep[u] = dep[p] + 1;
    for (auto [v, t] : e0[u]) {
        if (v == p) continue;
        c[v] = t;
        e[u].push_back(v);
        dfs0(v, u);
    }
}

pii dfs(int u) {
    pii res = {0, 0};
    if (dep[u] % 2 == 1) {
        // 1 first
        for (auto v : e[u]) {
            pii t = dfs(v);
            if (res.fi == 0 && res.se == 0) {
                res = t;
            }
            else if (res.fi * (t.fi + t.se) < t.fi * (res.fi + res.se)) {
                res = t;
            }
        }
    }
    else {
        // 0 first
        for (auto v : e[u]) {
            pii t = dfs(v);
            if (res.fi == 0 && res.se == 0) {
                res = t;
            }
            else if (res.se * (t.fi + t.se) < t.se * (res.fi + res.se)) {
                res = t;
            }
        }
    }
    if (c[u] == 0) res.se ++;
    else res.fi ++;
    // printf("u=%d, res =<%d,%d>\n", u, res.fi, res.se);
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        e0[i].clear();
        e[i].clear();
    }
    for (int i=1; i<n; i++) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        e0[u].push_back({v, a});
        e0[v].push_back({u, a});
    }
    dfs0(1, 0);
    // for (int i=1; i<=n; i++) printf("%d%c", c[i], " \n"[i==n]);
    // for (int i=1; i<=n; i++) {
    //     printf("%d: ", i);
    //     for (auto v : e[i]) printf("->%d", v);
    //     puts("");
    // }

    pii res = {0, 0};
    for (auto u : e[1]) {
        if (c[u] == 1) {
            pii t = dfs(u);
            // printf("u=%d t=<%d,%d>\n", u, t.fi, t.se);
            if (res.fi == 0 && res.se == 0) {
                res = t;
            }
            else if (res.fi * (t.fi + t.se) < t.fi * (res.fi + res.se)) {
                res = t;
            }
        }
    }
    // printf("<%d,%d>\n", res.fi, res.se);
    if (res.fi == 0 && res.se == 0) {
        printf("%.11lf\n", 0.0);
        return;
    }

    double one = res.fi, zero = res.se;
    printf("%.11lf\n", one / (one + zero));
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
