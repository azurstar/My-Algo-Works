#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
ll n;
struct node{
    ll w, c, v;
}a[maxn];
bool cmp(node a, node b){
    return a.w * b.c > a.c * b.w;
}
ll b[maxn];
int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++ ){
        cin >> a[i].w >> a[i].v >> a[i].c;
    }

    sort(a + 1, a + n + 1, cmp);
    ll ans = 0;

    for(int i = 1; i <= n; i ++ )
        b[i] = b[i - 1] + a[i].w;

    for(int i = 1; i <= n; i ++ ){
        ans += a[i].v - (b[i - 1] * a[i].c);
    }

    cout << ans << endl;

    return 0;

}