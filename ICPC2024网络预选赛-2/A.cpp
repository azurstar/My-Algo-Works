#include<bits/stdc++.h>
using namespace std;
int n, k;
const int N = 1e5 + 10;
typedef pair<string, int> PSI;
PSI nums[N];



int main()
{
    cin>>n>>k;
    int tem = 1e9 + 10;
    for(int i = 1; i <= k; i ++ ) {
        int val; cin>>val;
        tem = min(tem, val);
    }

    map<string, priority_queue<int, vector<int>, greater<>>> m;
    for(int i = 0; i < n; i ++ ) {
        int val; string name;
        cin>>val>>name;
        nums[i].first = name;
        nums[i].second = val;
        m[name].push(val);
    }

    for (const auto &item: nums) {
        string name = item.first;
        int val = item.second;
        int idx = 0;
        for (const auto &item2: m) {
            string newName = item2.first;
            auto q = item2.second;

        }

    }


    return 0;
}