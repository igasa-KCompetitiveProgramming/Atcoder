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
    ll n;
    cin >> n;
    vector<vector<vector<ll>>> a(n,vector<vector<ll>>(n,vector<ll>(n)));
    vector<vector<vector<ll>>> ruiseki(n,vector<vector<ll>>(n+1,vector<ll>(n+1,0)));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                cin >> a[i][j][k];
                ruiseki[i][j+1][k+1] = ruiseki[i][j+1][k] + ruiseki[i][j][k+1] - ruiseki[i][j][k] + a[i][j][k];
            }
        }
    }

    ll q;
    cin >> q;
    vector<vector<ll>> l(q,vector<ll>(3));
    vector<vector<ll>> r(q,vector<ll>(3));
    rep(i,q){
        ll ans = 0;
        rep(j,3){
            cin >> l[i][j] >> r[i][j];
        }
        l[i][0]--;
        r[i][0]--;
        rep(j,r[i][0]-l[i][0]+1){
            ans += ruiseki[l[i][0]+j][r[i][1]][r[i][2]] - ruiseki[l[i][0]+j][l[i][1]-1][r[i][2]] - ruiseki[l[i][0]+j][r[i][1]][l[i][2]-1] + ruiseki[l[i][0]+j][l[i][1]-1][l[i][2]-1];
        }
        cout << ans << endl;
    }
}