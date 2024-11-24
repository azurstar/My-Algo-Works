#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <numeric>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ld PI=acos(-1);
const ld EPS=1e-4;
const ll MOD=1<<21;
void solve() {
    vector<ll> a;
    ll q;cin>>q;
    while(q--){
        ll t,v;cin>>t>>v;
        while(t--) {
            a.pop_back();
        }
        a.push_back(((a.empty()?0:a.back())+v)%MOD);
        ll ans=a.back();
        for(ll i=0;i<a.size()-1;i++) ans^=(a.back()-a[i]);
        cout<<ans%MOD<<endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
//    ll t;cin>>t;
//    while(t--)
    solve();
    return 0;
}