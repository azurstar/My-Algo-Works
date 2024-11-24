#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;
const int maxn = 1e5 + 10;
int T, n;
map < int, vector<string> >  M;

int main() {

    cin >> T;
    whie(T--){
        cin >> n;
        for(int i = 1; i <= n; i ++ ){
            cin >> s;
            for(int j = 0; j <= s.length() - 1; j ++ ){
                char problem;
                string name;
                int k, flag, num;
                if(s[j - 1] == ' ' && s[j + 1] == ' ' && s[j] >= 'A' && s[j] <= 'Z'){
                    problem = s[j];
                    k = j;
                }
                for(int j = 0; j <= k; j ++ ){
                    name[j] = s[j];
                }
                if(s[k + 2] == 'a') flag = 1;
                else flag = 0;

                if(flag == 0) continue;
                num = problem - 'A' + 1;



            }
        }
    }
    return 0;
}