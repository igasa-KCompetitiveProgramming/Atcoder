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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n+10,vector<int>(3,0));
    dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
    rep(i,n){
        rep(j,3){
            rep(k,3){
                if(j==k) continue;

                if(s[i] == 'R' && k == 2) continue;
                if(s[i] == 'P' && k == 0) continue;
                if(s[i] == 'S' && k == 1) continue;

                if(s[i] == 'R' && k == 1) chmax(dp[i+1][k],dp[i][j]+1);
                else if(s[i] == 'P' && k == 2) chmax(dp[i+1][k],dp[i][j]+1);
                else if(s[i] == 'S' && k == 0) chmax(dp[i+1][k],dp[i][j]+1);
                else chmax(dp[i+1][k],dp[i][j]);
            }
        }
    }
    rep(i,n+1){
        rep(j,3){
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    int ans = 0;
    rep(i,3){
        ans = max(ans,dp[n][i]);
    }
    cout << ans << endl;
}