#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;

const ld pi=acos(-1);
const ld eps=1e-4;
const ll mod=1e9+7;

void solve() {
    ll n;cin>>n;
    vector<string> a;
    while(n--) {
        string tmp;cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end(),[](string a,string b) {return a+b>b+a;});
    for(string s:a) cout<<s;
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
