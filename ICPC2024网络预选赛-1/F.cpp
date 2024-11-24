#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
bool st[maxn];
int n, a[maxn];
int ans, tem;

void solve()
{
    memset(st, false, sizeof(st));
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        tem = max(tem, a[i]);
    }
    for(int i = 1; i <= n; i ++ ){
        if(a[i] == tem) {
            st[i] = true;
        }
    }
    vector<int> res;
    tem = 0;
    for(int i = 1; i <= n; i ++ ) {
        if(st[i]) {
            if(tem != 0) {
                res.push_back(tem);
            }
            tem = 0;
            continue;
        }
        tem ++;
    }
//    for (int item : res) {
//        ans += 2 * item - 1;
//    }
//    cout<<ans<<endl;
    for(auto i : res) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {

    int t; cin>>t;
    while( t -- )
    {
        solve();
    }

    return 0;
}
