#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5 + 10;
int T, n, ans, a[maxn];
int vis[maxn];

int main()
{
    cin >> T;
    while(T--){
        cin >> n;
        ans = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i ++ ){
            cin >> a[i];
        }

        for(int i = 1; i <= n; i ++ ){

            if(vis[i])continue;
            vis[i] = 1;
            for(int j = i + 1; j <= n; j ++ ){
                if(a[j] == a[i]) vis[j] = 1;
                else if(a[j] < a[i]) ans ++ ;
                else break;
            }

            for(int j = i - 1; j >= 1; j -- ){
                if(a[j] == a[i]) vis[j] = 1;
                else if(a[j] < a[i]) ans ++ ;
                else break;
            }

        }

        cout << ans << endl;
    }
    return 0;
}
