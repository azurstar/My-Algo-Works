#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int a[N];

static bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    for(int i = 1; i <= 32; i ++ ) cin>>a[i];
    int tem = a[1];
    sort(a + 1, a + 1 + 32);
//    for(int i = 1; i <= 32; i ++ ) cout<<a[i]<<" ";
    for(int i = 1; i <= 32; i ++ ) {
        if(a[i] == tem) {
            tem = i;
            break;
        }
    }

    int ans;
    if(tem<=2) ans=32;
    else if(tem<=6) ans=16;
    else if(tem==7) ans=8;
    else if(tem<=15) ans=4;
    else if(tem<=31) ans=2;
    else ans=1;
    cout<<ans<<endl;

}

int main()
{
    int t; cin>>t;
    while( t -- )
    {
        solve();
    }
    return 0;
}