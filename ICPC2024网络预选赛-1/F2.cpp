#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>


using namespace std;

const int maxn = 2e5 + 10;
int T, n, a[maxn], cnt, Max = -1;
int tag1[maxn], tag2[maxn];

int main()
{
    cin >> T;
    while(T--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i ++ ){
            cin >> a[i];
            Max = max(Max, a[i]);
        }
        memset(tag2, 0, sizeof tag1);
        memset(tag1, 0, sizeof tag2);

        for(int i = 1; i <= n - 1; i ++ ){

            if(a[i] < a[i + 1]) {

                tag1[i + 1] = tag1[i] + 1;
                a[i] = a[i + 1];
                cnt += tag1[i + 1];
            }
            else if(a[i] == a[i + 1])
                tag1[i + 1] = tag1[i] + 1;
        }

        for(int i = n; i >= 2; i -- ){
            if(tag1[i]){
                if(a[i] == Max) {
                    i = i - tag1[i];
                    continue;
                }
            }
            if(a[i - 1] > a[i]) {

                tag2[i - 1] = tag2[i] + 1;
                a[i] = a[i - 1];
                cnt += tag2[i - 1];
            }
            else if(a[i] == a[i - 1])
                tag2[i - 1] = tag2[i] + 1;
        }

        cout << cnt << endl;

    }

    return 0;
}
