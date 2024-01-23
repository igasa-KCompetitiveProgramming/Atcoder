#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int n;
    int d;
    char s[100][100];
    int ans1=0;
    int ans2=0;
    int help=0;
    cin >> n >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin >> s[i][j];
        }
    }
    char od[100]={};
    
    
    for(int j=0;j<d;j++){
        for(int i=0;i<n;i++){
            if(s[i][j]=='o'){
                help++;    
            }
        }
        if(help==n){
            od[j]='1';
        }
        help = 0;
    }
    for(int i=0;i<d;i++){
        if(od[i]=='1'){
            ans1++;
        }else{
            if(ans1>ans2){
                ans2=ans1;
                ans1=0;
            }else{
                ans1=0;
            }
        }
    }
    if(ans2<ans1){
        ans2 = ans1;
    }
    cout << ans2;
}