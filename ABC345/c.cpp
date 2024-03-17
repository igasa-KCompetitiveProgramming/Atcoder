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
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = n*(n-1)/2;
    map <char,ll> mp;
    bool flag = true;
    rep(i,n){
        mp[s[i]]++;
    }
    for(auto x:mp){
        ans -= x.second*(x.second-1)/2;
        if(x.second*(x.second-1)/2!=0){
            flag = false;
        }
    }
    if(!flag){
        ans++;
    }
    cout << ans << endl;
}