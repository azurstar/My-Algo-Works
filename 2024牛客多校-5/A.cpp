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

void solve() {
    ll n,k;cin>>n>>k;
    if(((1+k)%2==0 || (2+k)%2==0) && n!=2) {
        cout<<"YES"<<endl;
        for(ll i=1;i<n;i+=2) {
            ll l=i,r=i+1;
            if((l+k)*r%4==0) cout<<l<<" "<<r<<endl;
            else if((r+k)*l%4==0) cout<<r<<" "<<l<<endl;
        }
    }
    else cout<<"NO"<<endl;
}

int main() {
    std::ios::sync_with_stdio(0),cout.tie(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}