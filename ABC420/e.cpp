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
    LL(n, q);
    UnionFind uf(n);
    vector<int> ans(n, 0);
    vector<bool> color(n, false);
    rep(q){
        //cout << spa << i + 2 << endl << endl;
        LL(type);
        if(type == 1){
            LL(u,v);
            if(u == v) continue;
            if(uf.issame(u-1, v-1)) continue;
            int check = ans[uf.root(u-1)] + ans[uf.root(v-1)];
            uf.merge(u-1, v-1);
            ans[uf.root(u-1)] = check;
        }else if(type == 2){
            LL(u);
            if(color[u-1]){
                ans[uf.root(u-1)]--;
            }else{
                ans[uf.root(u-1)]++;
            }
            color[u-1] = !color[u-1];
        }else if(type == 3){
            LL(u); 
            if(ans[uf.root(u-1)] == 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
        /*
        rep(n) cout << color[i] << spa;
        cout << endl;
        rep(n) cout << uf.root(i) << spa << ans[uf.root(i)] << endl;
        cout << endl;   
        */
    }
}