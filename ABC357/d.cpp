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
ll MOD = 998244353;

ll POW(ll x){
    ll ans = 1;
    rep(i,x){
        ans *= 10;
        ans %= MOD;
    }
    return ans;
}

ll POWER(ll n){
    ll m = n;
    string s = to_string(n);
    ll ans = 0;
    ll amari = POW(s.size());
    while(n != 0){
        if(n%2 == 0){
            amari *= POW(s.size());
            ans *= POW(s.size());
            ans %= MOD;
            ans += amari/(9);
            amari %= (9);
            ans %= MOD;
        }
        amari *= POW(s.size());
        ans *= POW(s.size());
        ans %= MOD;
        ans += amari/(9);
        amari %= (9);
        ans %= MOD;
        n /= 2;
        cout << ans << " " << amari << endl;
    }
    ans *= m;
    ans %= MOD;
    ans--;
    return (ans+amari)%MOD;
}

int main(){
    ll n;
    cin >> n;
    cout << POWER(n) << endl;
}