#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n; cin>>n;
    int t = 1e9 + 10;
    for(int i = 1; i <= n; i ++ ) {
        cin>>a[i];
        t = min(t, a[i]);
    }
    cout<<t;
    return 0;
}