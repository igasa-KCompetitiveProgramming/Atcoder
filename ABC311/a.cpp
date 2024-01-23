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
    char s[100];
    int help=1;
    int A,B,C;
    A=0;
    B=0;
    C=0;
    int ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    
    for(int i=0;i<n;i++){
        if(help!=0){
            if(s[i]=='A'){
                A=1;
            }else if(s[i]=='B'){
                B=1;
            }else if(s[i]=='C'){
                C=1;
            }
            if(A==1&&B==1&&C==1){
                help=0;
                ans=i+1;
            }
        }
    }
    cout << ans << endl;
}