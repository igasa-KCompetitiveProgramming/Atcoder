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

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, -1)));
    int ans = 0;
    rep(i,n){
        dp[i][0][0] = 0;
    }
    priority_queue<pint> p;
    p.push({0,0});
    rep(i,n){
        rep(j,p.size()){
            int nx = get<0>(p.top());
            int ny = get<1>(p.top());
            if(nx > x || ny > y){
                continue;
            }
            if(nx+a[i]<=x&&ny+b[i]<=y){
                dp[i+1][nx+a[i]][ny+b[i]] = max(dp[i+1][nx+a[i]][ny+b[i]], dp[i][nx][ny]+1);
                ans = max(ans, dp[i+1][nx+a[i]][ny+b[i]]);
                p.push({nx+a[i],ny+b[i]});
            }else{
                dp[i+1][nx][ny] = max(dp[i+1][nx][ny], dp[i][nx][ny]);
                ans = max(ans, dp[i+1][nx][ny]);
            }
        }
    }
    if(ans!=n){
        ans++;
    }
    cout << ans << endl;
    return 0;
}
