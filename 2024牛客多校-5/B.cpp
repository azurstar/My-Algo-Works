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
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    if((n*m)%2==0) {
        if(a==1 && b==1) cout<<"Yes";
        else if(a==0 && b==0) {
            if((n*m)==2) cout<<"Yes";
            else cout<<"No";
        }
        else if(a==0 && b==1) {
            if(n%2==0 || m%2==0) cout<<"Yes";
            else cout<<"No";
        }
        else if(a==1 && b==0) {
            if(min(n,m)==1 && max(n,m)%2==0) cout<<"Yes";
            else cout<<"No";
        }
    }else cout<<"No";
    cout<<endl;
}

int main() {
    std::ios::sync_with_stdio(0),cout.tie(0);cin.tie(0);
    ll t;cin>>t;
    while(t--) solve();
    return 0;
}