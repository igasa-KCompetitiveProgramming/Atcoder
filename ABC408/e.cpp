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

// union by size + path having
class UnionFind {
    public:
        vector <ll> par; // 各元の親を表す配列
        vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    
        UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
            for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
        }
        void init(ll sz_) {
            par.resize(sz_);
            siz.assign(sz_, 1LL);  
            for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
        }
    
        ll root(ll x) { // 根の検索
            while (par[x] != x) {
                x = par[x] = par[par[x]]; // x の親の親を x の親とする
            }
            return x;
        }
    
        bool merge(ll x, ll y) {
            x = root(x);
            y = root(y);
            if (x == y) return false;
            // merge technique（データ構造をマージするテク．小を大にくっつける）
            if (siz[x] < siz[y]) swap(x, y);
            siz[x] += siz[y];
            par[y] = x;
            return true;
        }
    
        bool issame(ll x, ll y) { // 連結判定
            return root(x) == root(y);
        }
    
        ll size(ll x) { // 素集合のサイズ
            return siz[root(x)];
        }
};

int main(){
    LL(n,m);
    vector<ll> u(m), v(m), w(m);
    rep(m) cin >> u[i] >> v[i] >> w[i];
    rep(m){
        u[i]--, v[i]--;
    }
    ll ans = 0;
    vector<bool> canUse(m, true);
    for(int i = 30; i >= 0; i--){
        vector<bool> check(m, false);
        rep(j,m){
            if (w[j] & (1LL << i) && canUse[j]) {
                canUse[j] = false;
                check[j] = true;
            }
        }
        UnionFind uf(n);
        rep(j,m) if (canUse[j]) uf.merge(u[j], v[j]);
        if(uf.issame(0, n - 1)) continue;
        rep(j,m){
            if (w[j] & (1LL << i) && check[j]) {
                canUse[j] = true;
            }
        }
        ans += (1LL << i);
    }
    cout << ans << endl;
}