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

const ll N=1e5;
struct node{
    ll x,y;
    ll dir;
} ray[N];

ll maze[1001][1001];
map<char,ll> mirrors={{'-',1},{'|',2},{'/',3},{'\\',4}};
map<string,ll> dirs={{"above",1},{"below",2},{"left",3},{"right",4}};

vector<vector<ll>> change={{0,0,0,0,0},
                           {0,2,1,3,4},
                           {0,1,2,4,3},
                           {0,4,3,2,1},
                           {0,3,4,1,2}};

vector<vector<ll>> mov={{0,0},{-1,0},{1,0},{0,-1},{0,1}};

node next(node p) {
    node r;
    vector<ll> m=mov[p.dir];
    r.x=p.x+m[0],r.y=p.y+m[1];
    r.dir=change[maze[r.x][r.y]][p.dir];
    return r;
}

void solve() {
    ll n,m;cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++) {
            char tmp;cin>>tmp;
            maze[i][j]=mirrors[tmp];
        }
    }
    ll q;cin>>q;
    for(ll i=0;i<q;i++) {
        string d;
        cin>>ray[i].x>>ray[i].y>>d;ray[i].dir=dirs[d];
    }
    for(ll i=0;i<q;i++) {
        ll ans=0;
        bool vis[1001][1001]={{false}};
        ll back=0;
        ll last_dir=ray[i].dir;
        node r=next(ray[i]);
        while(true) {
            if((r.x<1 || r.x>n) || (r.y<1 || r.y>m)) break;
            if(last_dir!=r.dir && !vis[r.x][r.y]) {
                ans++;
                vis[r.x][r.y]=true;
            }
            last_dir=r.dir;
            r=next(r);
            if(vis[r.x][r.y] && back==0) {
                back++;
                r=ray[i];
                if(!vis[r.x][r.y]){
                    ans++;
                    vis[r.x][r.y]=true;
                }
                if(maze[r.x][r.y]==3 && r.dir==1) r.dir=3;
                else if(maze[r.x][r.y]==3 && r.dir==2) r.dir=4;
                else if(maze[r.x][r.y]==3 && r.dir==3) r.dir=1;
                else if(maze[r.x][r.y]==3 && r.dir==4) r.dir=2;

                else if(maze[r.x][r.y]==4 && r.dir==1) r.dir=4;
                else if(maze[r.x][r.y]==4 && r.dir==2) r.dir=3;
                else if(maze[r.x][r.y]==4 && r.dir==3) r.dir=2;
                else if(maze[r.x][r.y]==4 && r.dir==4) r.dir=1;
                if(maze[r.x][r.y]==3 || maze[r.x][r.y]==4) r=next(r);
                else break;
            }else if(vis[r.x][r.y]) break;
        }
        cout<<ans<<endl;
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