#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct edge{
    int t, nex, w;
}e[maxn * 10];
void add_edge(int x, int y, int s){
    e[++tot].t = y, e[tot].w = s;
    e[tot].nex = head[x];
    head[x] = tot;
}
int n, m, tot, head[maxn];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        int x, y, z;
        cin >> x >> y >> z;
        add_edge(x, y, z);
    }

}
