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
    int mod = 998244353;
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n,vector<ll>(n));
    vector<vector<vector<ll>>> s(m,vector<vector<ll>>(3,vector<ll>(3)));
    vector<ll> startPoint(9);
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    rep(i,3){
        rep(j,3){
            rep(k,3){
                rep(l,3){
                    startPoint[i*3+j] += a[i*3+k][j*3+l];
                }
            }
        }
    }
    rep(i,m){
        rep(j,3){
            rep(k,3){
                cin >> s[i][j][k];
            }
        }
    }
    vector<vector<int>> ans(0,vector<int>(3));
    rep(i,3){
        rep(j,3){
            int maximamPoint = startPoint[i*3+j];
            ans.push_back({0,i*3,j*3});
            rep(k,20){
                ll ruiseki = 0;
                rep(l,3){
                    rep(m,3){
                        ruiseki += (s[k][l][m] + a[i*3+l][j*3+m])%mod;
                        ruiseki %= mod;
                    }
                }
                if(ruiseki > maximamPoint){
                    maximamPoint = ruiseki;
                    ans[ans.size()-1] = {k+1,i*3,j*3};
                }
            }
        }
    }
    int cnt = 0;
    rep(i,ans.size()){
        if(ans[i][0] == 0){
            cnt++;
        }
    }
    cout << 9-cnt << endl;
    rep(i,9){
        if(ans[i][0] != 0){
            cout << ans[i][0]-1 << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    }
    return 0;
}