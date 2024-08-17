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
    cin >> n;
    vector<string> s(n);
    int m = 0;
    rep(i,n){
        cin >> s[n-i-1];
        m = max(m,(int)s[n-i-1].size());
    }
    vector<string> ans(m);
    rep(i,m){
        rep(j,n){
            if(s[j].size() <= i){
                ans[i] += "*";
            }else{
                ans[i] += s[j][i];
            }
        }
    }
    vector<int> counter(m,0);
    rep(i,m){
        int cnt = 0;
        rep(j,ans[i].size()){
            if(ans[i][j] != '*'){
                cnt = j;
            }
        }
        counter[i] = cnt;
    }
    rep(i,m){
        rep(j,counter[i]+1){
            cout << ans[i][j];
        }
        cout << endl;
    }
}