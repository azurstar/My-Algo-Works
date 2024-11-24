#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
inline int read(){
    int s=0,w=1;char ch = getchar();
    while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return s*w;
}
int a[3][maxn],n,count_row[maxn],flag[maxn],Count[maxn],Flag[maxn];
int cnt,pre,ans,start;
void print(){
    cout<<"cnt = "<<cnt<<' '<<"pre = "<<pre<<endl;
    return ;
}
int main()
{
    n=read();
    for(int i=1;i<=2;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            if(s[j] == 'R'){
                a[i][j+1] = 1;
            }
            else a[i][j+1] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        int tmp = a[1][i] + a[2][i] ;
        if(tmp==1){
            if(a[1][i] == 1)flag[i] = 1;
            else flag[i] = 2;
        }
        if(tmp == 2)
            flag[i] = 3;
    }

//	for(int i=1;i<=n;i++)
//		cout<<a[1][i]<<' ';
//	puts("");
//	for(int i=1;i<=n;i++)
//		cout<<a[2][i]<<' ';
//	puts("");
//	for(int i=1;i<=n;i++)
//		cout<<count_row[i]<<' ';
//	puts(""); 
//	for(int i=1;i<=n;i++)
//		cout<<flag[i]<<' ';
//	puts(""); 

    int tot=0;

    for(int i=1;i<=n;i++){
        if(a[1][i] + a[2][i] == 2){
            int cnt = 1;
            while(a[1][i+1] + a[2][i+1] == 2 && i+1 <= n ){
                i++,cnt++;
            }
            count_row[++tot] = 2 * cnt ;
            Flag[tot] = 3;
        }
        else if(a[1][i] + a[2][i] == 1){
            int cnt = 1;
            Flag[++tot] = flag[i];

            while(a[1][i+1] + a[2][i+1] == 1 && flag[i] == flag[i+1] && i+1 <= n ){
                i++,cnt++;
            }
            count_row[tot] = 1 * cnt ;
        }
        else {
            int cnt = 1;
            while(a[1][i+1] + a[2][i+1] == 0 && i+1 <= n ){
                i++,cnt++;
            }
            count_row[++tot] = 0;
        }
    }

//	for(int i=1;i<=tot;i++)
//		cout<<count_row[i]<<' ';
//	puts("");
//	
//	for(int i=1;i<=tot;i++)
//		cout<<Flag[i]<<' ';
//	puts("");


    pre = -1, start = 0;
    for(int i=1;i<=tot;i++){
        if(!count_row[i]){
            pre = -1;
            ans = max(ans, cnt - 1);
            cnt = 0;

        }


        if(Flag[i] != 3 && pre == -1){
            pre = Flag[i];
            cnt = count_row[i];

            continue;
        }
        if(Flag[i] == 3 && pre == -1){
            pre = 3;
            cnt = count_row[i];

            continue;
        }


        if(pre != -1 ){
            if(pre == 3){
                cnt +=count_row[i];
                pre = Flag[i];

                continue;
            }

            if(Flag[i] == 3){
                cnt += count_row[i];

                continue;
            }

            if(Flag[i-1] == 3){
                if(Flag[i] == pre){

                    //cout<<"count_row[i-1] % 2 = "<<count_row[i-1] % 2<<endl;
                    if(count_row[i-1] / 2 == 1){
                        cnt += count_row[i] - 1, pre = Flag[i];
                        continue;
                    }

                    if( (count_row[i-1] / 2 ) % 2 == 0 )
                    {cnt += count_row[i], pre = Flag[i];}
                    else
                    {cnt += count_row[i] - 1, pre = Flag[i];}

                    continue;
                }

                else if(Flag[i] != pre){

                    if( (count_row[i-1] / 2 ) % 2 == 1 )
                        cnt += count_row[i], pre = Flag[i];
                    else
                        cnt += count_row[i] - 1, pre = Flag[i];

                    continue;
                }
            }

            if(Flag[i-1] != 3 && Flag[i] != pre){
                ans = max(ans, cnt - 1);
                cnt = count_row[i];
                pre = Flag[i];

                continue;
            }

        }

    }
    ans = max(ans, cnt - 1);

    cout<<ans<<endl;

    return 0;
}