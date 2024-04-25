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
    string t;
    int n;
    cin >> t;
    cin >> n;
    vector<int> a(n);
    vector<vector<string>> s(n);
    rep(i,n){
        cin >> a[i];
        rep(j,a[i]){
            string tmp1;
            cin >> tmp1;
            s[i].push_back(tmp1);
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(t.size()+1, 1000));
    rep(i,n+1){
        dp[i][0] = 0;
    }
    rep(i,n){
        rep(j,a[i]){
            rep(k,t.size()){
                if(s[i][j][0] == t[k]){
                    if(dp[i][k] == -1) continue;
                    if(k+s[i][j].size() > t.size()) continue;
                    if(s[i][j] != t.substr(k,s[i][j].size())) continue;
                    dp[i+1][k+s[i][j].size()] = min(dp[i+1][k+s[i][j].size()], dp[i][k]+1);
                }
            }
        }
        rep(j,t.size()+1){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    if(dp[n][t.size()]==1000){
        cout << -1;
        return 0;
    }
    cout << dp[n][t.size()] << endl;
}