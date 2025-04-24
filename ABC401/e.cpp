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

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

// union by size + path having
class UnionFind {
    public:
        vector <ll> par; // 各元の親を表す配列
        vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    
        // Constructor
        UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
            for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
        }
        void init(ll sz_) {
            par.resize(sz_);
            siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
            for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
        }
    
        // Member Function
        // Find
        ll root(ll x) { // 根の検索
            while (par[x] != x) {
                x = par[x] = par[par[x]]; // x の親の親を x の親とする
            }
            return x;
        }
    
        // Union(Unite, Merge)
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
    vector<ll> u(m),v(m);
    vector<vector<ll>> g(n);
    rep(m) cin >> u[i] >> v[i];
    rep(m) u[i]--, v[i]--;
    rep(m){
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    UnionFind uf(n);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(0);
    vector<ll> ans(n,-1);
    vector<bool> used(n,false);
    set<ll> st;
    ll next = 1;
    while(!pq.empty()){
        ll now = pq.top();
        pq.pop();
        if(used[now]) continue;
        used[now] = true;
        next = max(next, now + 1);
        st.insert(now);
        for(auto x : g[now]){
            if(used[x]) continue;
            uf.merge(now, x);
            pq.push(x);
        }
        if(st.size() == next) ans[next - 1] = uf.size(now) - next;
        //cout << now << spa << uf.size(now) << spa << st.size() << spa << next << endl;
    }
    rep(n) cout << ans[i] << endl;
}