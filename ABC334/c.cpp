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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(k);
    rep(i,k){
        cin >> a[i];
    }
    ll ans = 0;
    if(k==1){
        cout << 0;
        return 0;
    }
    if(k%2==0){
        rep(i,k/2){
            ans += a[2*i+1] - a[2*i];
        }
    }else{
        ans = INF;
        vector<ll> frontSum(k/2);
        vector<ll> backSum(k/2);
        frontSum[0] = a[1] - a[0];
        backSum[0] = a[k-1] - a[k-2];
        rep(i,k/2-1){
            frontSum[i+1] = frontSum[i] + a[2*i+3] - a[2*i+2];
        }
        rep(i,k/2-1){
            backSum[i+1] = backSum[i] + a[k-2*i-3] - a[k-2*i-4];
        }
        rep(i,k/2-1){
            ans = min(ans,frontSum[i] + backSum[k/2-i-2]);
        }
        ans = min(ans,frontSum[k/2-1]);
        ans = min(ans,backSum[k/2-1]);
    }
    cout << ans << endl;
}