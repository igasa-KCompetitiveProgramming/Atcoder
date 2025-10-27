#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

//！？！？
#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

//int INF = 2147483647; // おおよそ2*10^9
ll inf = 1LL<<60; //おおよそ10^18
//ull UINF == おおよそ1.8*10^19


ll solve_jury(ll n, ll m, ll c, vector<ll> a){
    ll ans = 0;
    map<ll, ll> mp;
    rep(a.size()){
        mp[a[i]]++;
    }
    rep(m){
        ll temp = 0;
        rep(j, m){
            temp += mp[(i + j) % m];
            if(temp >= c) break;
        }
        ans += temp;
    }
    return ans;
}

ll solve(ll n, ll m, ll c, vector<ll> a){
    map<ll, ll> mp;
    vector<pll> p;
    rep(n){
        mp[a[i]]++;
    }
    for(auto x : mp){
        p.pb(make_pair(x.fi, x.se));
    }
    vector<ll> ruiseki(p.size() + 1);
    ruiseki[0] = 0;
    rep(p.size()){
        ruiseki[i + 1] = ruiseki[i] + p[i].se;
    }
    ll ans = 0;
    rep(i, 1, p.size()){
        //cout << p[i - 1].fi << spa << p[i].fi << spa << ruiseki[i + 1] << spa << ruiseki[i] << endl;
        ll target = c;
        //cout << ruiseki[ruiseki.size() - 1] << spa << ruiseki[i] << endl;
        if(ruiseki[ruiseki.size() - 1] - ruiseki[i] < c){
            target -= ruiseki[ruiseki.size() - 1] - ruiseki[i];
            int left = -1;
            int right = ruiseki.size(); // rightは各自設定
            while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
                int mid = left + (right - left) / 2;
                if(ruiseki[mid] >= target){ //配列[mid]より比較対象が小さい場合
                    right = mid;
                }else{
                    left = mid;
                }
                if(right < left) break;
            }
            //cout << left << spa << right << endl;
            //cout << ruiseki[left] << spa << ruiseki[right] << spa << c << spa << target << endl;
            ans += (p[i].fi - p[i - 1].fi) * (ruiseki[right] + c - target);
            //cout << ans << endl;
        }else{
            int left = -1;
            int right = ruiseki.size(); // rightは各自設定
            while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
                int mid = left + (right - left) / 2;
                if(ruiseki[mid] - ruiseki[i] >= c){ //配列[mid]より比較対象が小さい場合
                    right = mid;
                }else{
                    left = mid;
                }
                if(right < left) break;
            }
            //cout << left << spa << right << endl;
            //cout << ruiseki[left] << spa << ruiseki[right] << endl;
            ans += (p[i].fi - p[i - 1].fi) * (ruiseki[right] - ruiseki[i]);
            //cout << ans << endl;
        }
    }
    int left = -1;
    int right = ruiseki.size(); // rightは各自設定
    while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
        int mid = left + (right - left) / 2;
        if(ruiseki[mid] >= c){ //配列[mid]より比較対象が小さい場合
            right = mid;
        }else{
            left = mid;
        }
        if(right < left) break;
    }
    if(p.size() == 1) ans += m * (ruiseki[right]);
    else ans += (m - p[p.size() - 1].fi + p[0].fi) * (ruiseki[right]);
    //cout << ans << endl;
    return ans;
}

int main(){
    ll n, m, c;
    vector<ll> a;
    while(true){
        n = 1 + rand() % 4;
        m = 1 + rand() % 4;
        c = 1 + rand() % (n - 1);
        a.resize(n);
        rep(n) a[i] = rand() % m;
        cout << n << spa << m << spa << c << endl;
        rep(n) cout << a[i] << spa;
        cout << endl << endl;
        if(solve(n, m, c, a) != solve_jury(n, m, c, a)){
            cout << solve(n, m, c, a) << spa << solve_jury(n,m,c,a) << endl;
            cout << n << spa << m << spa << c << endl;
            rep(n) cout << a[i] << spa;
            cout << endl;
            return 0;
        }
    }
}