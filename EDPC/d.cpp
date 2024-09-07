#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    ll n,w;
    cin >> n >> w;
    vector<vector<ll>> wv(n,vector<ll> (2,0));
    rep(i,n){
        rep(j,2){
            cin >> wv[i][j];
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll> (w+1,-1));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,w+1){
            if(dp[i][j] != -1){
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                if(j+wv[i][0] <= w){
                    dp[i+1][j+wv[i][0]] = max(dp[i+1][j+wv[i][0]],dp[i][j]+wv[i][1]);
                }
            }
        }
    }
    ll ans = 0;
    rep(i,w+1){
        ans = max(ans,dp[n][i]);
    }
    cout << ans << endl;
}