#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
int main(){
    int m,n;
    string s;
    int ans= 0;
    int check[1000][2]={};
    int count=0;
    cin >> n >> m;
    cin >> s;
    rep(i,n){
        if(s[i]=='0'){
            count++;
        }else if(s[i]=='1'){
            check[count][0]++;
        }else{
            check[count][1]++;
        }
    }
    rep(i,count+1){
        int tmp=0;
        tmp += check[i][1];
        if(check[i][0]<m){
        }else{
            tmp += check[i][0]-m;
        }
        if(ans<tmp){
            ans = tmp;
        }
    }
    cout << ans;
}