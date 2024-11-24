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
const ll MOD=1<<21;


map<string, pll> wf46_board,wf47_board;
vector<string> wf46_teams,wf47_teams;
bool cmp1(string t1,string t2){
    if(wf46_board[t1].first>wf46_board[t2].first) return true;
    else if(wf46_board[t1].first==wf46_board[t2].first && wf46_board[t1].second<=wf46_board[t2].second) return true;
    else return false;
}

bool cmp2(string t1,string t2){
    if(wf47_board[t1].first>wf47_board[t2].first) return true;
    else if(wf47_board[t1].first==wf47_board[t2].first && wf47_board[t1].second<=wf47_board[t2].second) return true;
    else return false;
}

void solve() {
    set<string> sames;
    ll n;cin>>n;
    while(n--){
        string s;ll p,t;
        cin>>s>>p>>t;
        wf46_board[s]={p,t};
        wf46_teams.push_back(s);
    }
    ll m;cin>>m;
    while(m--){
        string s;ll p,t;
        cin>>s>>p>>t;
        wf47_board[s]={p,t};
        wf47_teams.push_back(s);
        if(wf46_board[s].first!=0 && s!="lzr010506") sames.insert(s);
    }
    sort(wf46_teams.begin(),wf46_teams.end(),cmp1);
    sort(wf47_teams.begin(),wf47_teams.end(),cmp2);
    ll wf46_ans=1,wf47_ans=1;
    ll wf46_front=0,wf47_front=0;
    for(;wf46_ans-1<wf46_teams.size();wf46_ans++){
        if(sames.count(wf46_teams[wf46_ans-1])==1) wf46_front++;
        else if(wf46_teams[wf46_ans-1]=="lzr010506") break;
    }
    for(;wf47_ans-1<wf47_teams.size();wf47_ans++){
        if(sames.count(wf47_teams[wf47_ans-1])==1) wf47_front++;
        else if(wf47_teams[wf47_ans-1]=="lzr010506") break;
    }
    ll ans=min(wf46_ans-wf46_front,wf47_ans-wf47_front);
    cout<<ans<<endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
//    ll t;cin>>t;
//    while(t--)
    solve();
    return 0;
}