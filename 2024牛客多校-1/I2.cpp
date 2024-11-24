#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1005;
const int dx[5] = {0,-1,0,1,0},
        dy[5] = {0,0,1,0,-1};
inline ll read(){
    ll s=0,w=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return s*w;
}
ll n,m,a[maxn][maxn],q,F[maxn][maxn][5],vis[maxn][maxn][5],check[maxn][maxn];
ll cnt,flag,mark_x,mark_y;
struct edge{
    ll x,y;
    ll dir;
}node[maxn*10];

ll change_dir(ll k,ll kind){
    if(k == 1){
        if(kind == 1) return 3;
        if(kind == 2) return 1;
        if(kind == 3) return 4;
        if(kind == 4) return 2;
    }
    if(k == 2){
        if(kind == 1) return 2;
        if(kind == 2) return 4;
        if(kind == 3) return 3;
        if(kind == 4) return 1;
    }
    if(k == 3){
        if(kind == 1) return 1;
        if(kind == 2) return 3;
        if(kind == 3) return 2;
        if(kind == 4) return 4;
    }
    if(k == 4){
        if(kind == 1) return 4;
        if(kind == 2) return 2;
        if(kind == 3) return 1;
        if(kind == 4) return 3;
    }
    return k;
}

ll dfs(ll x,ll y,ll dir,ll step){
    if(F[x][y][dir])
        return F[x][y][dir];

    ll tx = x + dx[dir], ty = y + dy[dir];
    ll new_dir = change_dir(dir,a[tx][ty]);

//	printf("Step %lld : ( %lld , %lld )  direction: %lld\n",step+1,tx,ty,new_dir);
//	int xz;cin>>xz;

    if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty][new_dir]){
        if(!check[tx][ty])
            check[tx][ty] = step + 1, cnt++;
        vis[tx][ty][new_dir] = 1;
        F[x][y][dir] = 0;
        ll tmp = dfs(tx,ty,new_dir,step+1);
        if(flag == 1){
            F[x][y][dir] = tmp;
            if(x==mark_x&&y==mark_y)
                flag = 0;
            return tmp;
        }
        else {
            F[x][y][dir] = tmp + 1;
            return F[x][y][dir];
        }

    }
    else if(tx<1||tx>n||ty<1||ty>m){
        F[tx][ty][dir] = 0;
        return 0;
    }
    else if(vis[tx][ty][new_dir]){
        ll ring_len = step - check[tx][ty] ; //********//
        F[x][y][dir] = ring_len;
        flag = 1,mark_x = tx,mark_y = ty;
        return ring_len;
    }
    return 0;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;    // 1 -   2 |   3 \   4 /
            if(ch=='-')a[i][j] = 1;
            else if(ch == '|')a[i][j] = 2;
            else if(ch == 92)a[i][j] = 3;
            else if(ch == '/')a[i][j] = 4;
        }

    q=read();
    for(int i=1;i<=q;i++){
        node[i].x = read(),
                node[i].y = read();
        string s ; cin>>s;
        if(s == "above")node[i].dir = 1; //1上 2右 3下 4左
        if(s == "right")node[i].dir = 2;
        if(s == "below")node[i].dir = 3;
        if(s == "left") node[i].dir = 4;
    }

    for(int i=1;i<=q;i++){
        memset(check,0,sizeof(check));
        memset(vis,0,sizeof(vis));
        ll x = node[i].x , y = node[i].y ;
        ll d = node[i].dir;
        cnt = 0;
        ll ans = dfs(x,y,d,0);
        cout<<ans<<endl;
    }
    return 0;
}

