#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    ll n;cin>>n;
    ll vis[n];
    memset(vis,0,sizeof vis);
    vector<ll> an;
    vector<pll> hw;
    for(ll i=0;i<n;i++) {
        ll tmp;cin>>tmp;
        an.push_back(tmp);
        hw.push_back({tmp,i});
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}
