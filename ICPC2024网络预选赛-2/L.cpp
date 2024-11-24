#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll n, T;
ll gcd(ll x, ll y){
    if(y % x == 0) return x;
    else return gcd(y % x, x);
}
int main()
{
    cin >> n;
    while(n--){
        cin >> T ;

        ll x = T + 1, y = 2;
        ll mod = gcd(x, y);
        cout << x / mod << " " << y / mod << endl;

    }
    return 0;
}