#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void solve() {
    ll n;cin>>n;
    ll ans=0;
    ll wa[n+1],aw[n+1];
    for(ll i=1;i<=n;i++) {
        cin>>wa[i];
        aw[wa[i]]=i;
    }
    if(n>4) {
        while(n)
    }else{
        for(ll i=1;i<=n;i++) {
            if(wa[i]!=i) {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0),cout.tie(0); cin.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    //solve();
    return 0;
}
