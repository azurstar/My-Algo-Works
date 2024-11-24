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
using pll = pair<ll, ll>;

const ld PI=acos(-1);
const ld EPS=1e-4;

map<char,pll> mov={{'A',{-1,0}},
                   {'D',{1,0}},
                   {'W',{0,1}},
                   {'S',{0,-1}}};

void solve() {
    ll ans=0;
    ll n;cin>>n;
    pll p;cin>>p.first>>p.second;
    set<pll> ps;
    ps.insert({0,0});
    pll current = {0, 0};

    if(p.first==0 && p.second==0){
        ans=4+n*(n-1)/2;
        cout<<ans<<endl;
        return;
    }
    ll t=0;
    for(ll i=0;i<n;i++) {
        ans+=t;
        char tmp;cin>>tmp;
        current.first += mov[tmp].first;
        current.second += mov[tmp].second;
        pll target = {current.first - p.first, current.second - p.second};
        if(ps.count(target)) ans++,t++;
        ps.insert(current);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}