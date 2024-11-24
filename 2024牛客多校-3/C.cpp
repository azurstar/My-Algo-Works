#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const ld PI=acos(-1);
const ld EPS=1e-4;

ll gcd(ll a,ll b) {
    return b>0?gcd(b,a%b):a;
}

void solve() {
    ll n,d;cin>>n>>d;
    ll gcd_v;
    for(ll i=0;i<n;i++) {
        ll tmp;cin>>tmp;
        if(i==0) gcd_v=tmp;
        else gcd_v=gcd(gcd_v,tmp);
    }
    ll ans=d%gcd_v;
    if(ans>gcd_v-ans) ans=gcd_v-ans;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
