#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;

const ld pi=acos(-1);
const ld eps=1e-4;

void solve() {
    ll n,k;cin>>n>>k;
    ll t=0;
    priority_queue<ll> a;
    for(ll i=0;i<n;i++) {
        ll tmp;cin>>tmp;
        a.push(tmp);
    }
    ll ans=a.top();
    while(a.top()!=0 && k!=1) {
        ll tmp=a.top();a.pop();
        a.push(tmp/k);
        t++;
        ans=min(ans,a.top()+t);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
