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

const ll maxn=1e6+7;
vector<pll> mov={{-1,0},{1,0},{0,-1},{0,1}};

void solve() {
    ll ans=0;
    ll n;cin>>n;
    vector<ll> grid;
    for(ll i=0;i<n;i++){
        char tmp;cin>>tmp;
        if(tmp=='R') grid.push_back(1);
        else grid.push_back(0);
    }
    for(ll i=0;i<n;i++){
        char tmp;cin>>tmp;
        if(tmp=='R' && grid[i]==1) grid[i]++;
        else if(tmp=='R' && grid[i]==0) grid[i]=-1;
    }
    ll num=0;
    ll status=0;
    ll last=0;
    ll index=0;
    for(ll p:grid) {
        if(last*p==-1 || status*p==-1 || p==0) num=0,status=p;
        if(abs(p)==1) status=p,num++;
        if(p==2) {
            num+=2,status*=-1;
            if(status==0 && index<n-1) status=abs(grid[index+1])==1?grid[index+1]:0;
        }
        index++;
        ans=max(ans,num);
        last=p;
    }
    ans=ans>0?ans-1:ans;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
