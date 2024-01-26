#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
    ll n,k;
    cin >> n >> k;
    ll max = 0;
    vector<vector<ll>> a(n,vector<ll>(2));
    rep(i,n){
        cin >> a[i][0] >> a[i][1];
        max += a[i][1];
    }
    
    sort(a.begin(),a.end());

    if(k>=max){
        cout << 1 << endl;
        return 0;
    }

    rep(i,n+1){
        if(k>=max){
            cout << a[i-1][0] + 1 << endl;
            break;
        }
        rep(j,n){
            if(i+j>=n){
                break;
            }
            if(a[i][0] == a[i+j][0]){
                max -= a[i+j][1];
            }else{
                i += j-1;
                break;
            }
        }
    }
}