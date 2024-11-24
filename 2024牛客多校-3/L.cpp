#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const ld PI=acos(-1);
const ld EPS=1e-4;

void solve() {
    pll w;
    for(ll i=1;i<=9;i++) {
        for(ll j=1;j<=9;j++) {
            char tmp;cin>>tmp;
            if(tmp=='8' && i!=1 && i!=9 && j!=1 && j!=9) w.first=i,w.second=j;
        }
    }
    for(ll i=1;i<=9;i++) {
        for(ll j=1;j<=9;j++) {
            if(i==w.first && j==w.second) cout<<'8';
            else cout<<'*';
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
