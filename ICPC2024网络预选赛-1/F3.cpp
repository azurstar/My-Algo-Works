#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    ll n;cin>>n;
    ll vis[n],ans=0;
    memset(vis,0,sizeof vis);
    vector<ll> an;
    vector<pll> hw;
    for(ll i=0;i<n;i++) {
        ll tmp;cin>>tmp;
        an.push_back(tmp);
        hw.push_back({tmp,i});
    }
    for(pll p:hw) {
        ll high=p.first,index=p.second;
        if(vis[index]==1) continue;
        vis[index]=1;
        for(ll i=index+1;i<n;i++) {
            if(an[i]<high) ans++;
            else if(an[i]==high) vis[i]=1;
            else break;
        }
        for(ll i=index-1;i>=0;i--) {
            if(an[i]<high) ans++;
            else if(an[i]==high) vis[i]=1;
            else break;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}
