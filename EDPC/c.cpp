#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> dp(3,vector<int> (3,0));
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];
    rep(i,n-1){
        dp[0][i+1] = max(dp[1][i]+a[i+1],dp[2][i]+a[i+1]);
    }
    return 0;
}