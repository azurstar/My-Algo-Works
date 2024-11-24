#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;

const ld pi=acos(-1);
const ld eps=1e-4;

struct point {
    ll x,y;
};

ll gcd(ll a,ll b) {
    return b>0?gcd(b,a%b):a;
}

void solve() {
    ll n,m;cin>>n>>m;
    point leftUp={500,500},rightDown={0,0};
    char mat[n+1][m+1];
    for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin>>mat[i][j];
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            if(mat[i][j]=='x') {
                if(i<leftUp.x) leftUp.x=i;
                if(j<leftUp.y) leftUp.y=j;
                if(i>rightDown.x) rightDown.x=i;
                if(j>rightDown.y) rightDown.y=j;
            }
        }
    }
    ll x=rightDown.x-leftUp.x+1;
    ll y=rightDown.y-leftUp.y+1;
    ll gcd_v=gcd(x,y);
    x/=gcd_v,y/=gcd_v;
    for(ll i=0;i<x;i++) {
        for(ll j=0;j<y;j++) {
            cout<<'x';
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
