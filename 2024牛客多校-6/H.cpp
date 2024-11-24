#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const ld PI=acos(-1);
const ld EPS=1e-4;

void solve() {
    string s;cin>>s;
    ll t4=0,t5=0;
    char last5='U';
    for(char c:s) {
        t4++,t5++;
        if(c=='4') t4=0;
        if(c=='5' || c=='U') {
            if(last5=='5' && c!='U') {
                cout<<"invalid"<<endl;
                return;
            }
            t4=0,t5=0,last5=c;
        }
        if(t4>=10 || t5>=90) {
            cout<<"invalid"<<endl;
            return;
        }
    }
    cout<<"valid"<<endl;
}

int main() {
    ios::sync_with_stdio(0),cout.tie(0); cin.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}
