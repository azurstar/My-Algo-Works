#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
const ll maxn=1e5;
ll ans[maxn];
typedef struct {
    ll id=0;
    ll score=0;
    string school;
} team;

bool cmp(team a,team b) {
    return a.score>b.score;
}

int main() {
    ll n,k;cin>>n>>k;
    ll c=1e9;
    for(ll i=0;i<k;i++) {
        ll tmp;cin>>tmp;
        c=tmp<c?tmp:c;
    }
    map<string,stack<ll>> p;
    vector<team> teams;
    for(ll i=1;i<=n;i++) {
        team T;
        T.id=i;
        cin>>T.score>>T.school;
        teams.push_back(T);
    }
    sort(teams.begin(),teams.end(),cmp);

    ll rank=0;
    for(team T:teams) {
        if(p[T.school].size()==c) {
            p[T.school].pop();
            rank--;
        }
        p[T.school].push(T.id);
        rank++;
        ans[T.id]=rank;
    }

    for(ll i=1;i<=n;i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
