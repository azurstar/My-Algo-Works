#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#define endl '\n'

using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;
void solve() {
    ll n,len=0;
    string ans;
    set<string> allId;
    map<string, set<string> > board;
    cin>>n;
    for(ll i=0;i<n;i++) {
        string team,id,status;
        cin>>team>>id>>status;
        if(status=="accepted") board[id].insert(team);
        allId.insert(id);
    }
    for(string id:allId) {
        if(board[id].size()>len) {
            len=board[id].size();
            ans=id;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ll t;cin>>t;
    while(t--) solve();
}
