#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

struct point {
    ll x,y;
} G,T;;

ld distance(point p1,point p2) {
    ld result=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    return result;
}

void solve() {
    cin>>G.x>>G.y>>T.x>>T.y;
    point p1=G; p1.x*=(-1);
    point p2=G; p2.y*=(-1);
    ld ans=min(distance(p1,T), distance(p2,T));
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0),cout.tie(0); cin.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    //solve();
    return 0;
}
