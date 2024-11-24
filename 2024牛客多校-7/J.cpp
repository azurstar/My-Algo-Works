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
    ll l,x,y;
    cin>>l>>x>>y;
    ld r0=sqrt(x*x+y*y);
    ld rl=sqrt((x-l)*(x-l)+y*y);
    ld minR=min(r0,rl);
    if(minR<=l) {
        cout<<"Yes"<<endl;
        if(minR==r0) cout<<0<<endl;
        else if(minR==rl) cout<<l<<endl;
    } else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}
