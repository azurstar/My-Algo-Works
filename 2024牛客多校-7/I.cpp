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
    ll m,k,h;
    cin>>m>>k>>h;
    if(h<=m) {
        cout<<h<<endl;
        return;
    }
    ll init=m;
    ll diff=m-k;
    if(diff==0) {
        cout<<init<<endl;
        return;
    }
    ll sum=init+k;
    while(sum<h) {
        init+=diff;
        sum+=m;
    }
    if(h-sum+m<diff) init=min(init,init-diff+h-sum+m);
    cout<<init<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}
