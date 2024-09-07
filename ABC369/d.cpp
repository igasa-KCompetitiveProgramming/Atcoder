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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[1][0] = a[0];
    dp[1][1] = 0;
    rep1(i,n-1){
        dp[i+1][1] = max(dp[i][0]+2*a[i],dp[i][1]);
        dp[i+1][0] = max(dp[i][0],dp[i][1]+a[i]);
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
}