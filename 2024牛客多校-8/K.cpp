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
    string s;cin>>s;
    ll t=0;
    char last='v';
    for(char c:s) {
        if (c!='a' && c!='v') {
            cout<<"No"<<endl;
            return;
        }
        else if(c=='a' && last=='a' && (t==3 || t==5)) t=0;
        t++;
        if(t%2==1 && c=='a')  last=c;
        else if(t%2==0 && c=='v') last=c;
        else {
            cout<<"No"<<endl;
            return;
        }
    }
    if(t!=3 && t!=5) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}
