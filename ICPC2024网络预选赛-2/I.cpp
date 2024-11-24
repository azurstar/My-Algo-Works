#include <cstdio>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int a[1000], T, n;
ll b[100];
void work(ll x){
    ll mod = 2, k = 0;
    while(x){
        b[++k] = x % mod;
        x /= 2;
    }
    return ;
}
int main()
{
    cin >> T;
    while(T--){
        cin >> n;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        work(n);
        if(b[1] == 0 && b[2] == 0) {
            puts("NO");
            continue;
        }

        puts("YES");
        int i;
        if(b[0] == 1) i = 0;
        else i = 1;

        for(; i <= 31; i ++ ){
            if(b[i + 1] == 0 && b[i]){
                if(b[i] == 1){
                    b[i + 1] = 1, b[i] = -1;
                }
                else if(b[i] == -1){
                    b[i + 1] = -1, b[i] = 1;
                }
            }
        }

        int j = 1;
        for(int k = 1; k <= 4; k ++ ){
            for(int j = (k - 1) * 8 + 1; j <= k * 8; j ++ )
                cout << b[j] << " ";
            puts("");
        }

    }
    return 0;
}