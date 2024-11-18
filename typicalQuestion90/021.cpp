#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define v(a,i,b) vector<ll> a(i,b)
#define vv(a,i,j,b) vector<vector<ll>> a(i, vector<ll>(j,b))
#define vp(a,i,b,c) vector<pll>> a(i,{b,c})
#define vvp(a,i,j,b,c) vector<vector<pll>> a(i, vector<>>(j,{b,c}))

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

//vectorのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//dequeのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::deque<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::deque<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//pairのcin,cout
template<typename T,typename U>
std::ostream &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
std::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
//vector<vector<T>>のcout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) {
for (const auto &row : v) {for (auto it = row.begin(); it != row.end(); ++it) { os << *it; if (std::next(it) != row.end()) { os << " "; } } os << "\n";} return os;}

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

struct SCC{
    vector<vector<int>> G, rG;

    vector<vector<ll>> scc;
    vector<ll> cmp;
    vector<vector<ll>> dag;

    SCC(ll n) : G(n), rG(n){}

    void addege(ll i, ll v){ G[i].pb(v); rG[v].pb(i); }

    vector<bool> used;
    vector<ll> vs,rvs;

    void dfs(ll v){
        used[v] = true;
        for(auto i : G[v]) if(!used[i]) dfs(i);
        vs.pb(v);
    }

    void rdfs(ll v, ll k){
        used[v] = true;
        cmp[v] = k;
        for(auto i : rG[v]) if(!used[i]) rdfs(i,k);
        rvs.pb(v);
    }

    set<pll> newEdges;
    void reconstruct(){
        ll n = G.size(); ll dv = scc.size();
        dag.resize(dv, vector<ll>(0));
        newEdges.clear();
        rep(n){
            ll u = cmp[i];
            for(auto j : G[i]){
                ll v = cmp[j];
                if(u == v) continue;
                if(newEdges.count({u,v})) continue;
                dag[u].pb(v);
                newEdges.insert({u,v});
            }
        }
    }

    void solve(){
        ll n = G.size();
        used = vector<bool>(n,false);
        rep(i,n) if(!used[i]) dfs(i);
        used = vector<bool>(n,false);

        ll k = 0;
        scc.clear();
        cmp = vector<ll>(n, -1);
        used = vector<bool>(n,false);
        rrep(i,vs.size()){
            if(!used[vs[i]]) rvs.clear(), rdfs(vs[i],k++), scc.pb(rvs);
        }
        reconstruct();
    }
};

int main(){
    LL(n,m);
    SCC scc(n);
    rep(m){
        LL(a,b);
        a--; b--;
        scc.addege(a,b);
    }
    scc.solve();

    ll ans = 0;
    rep(scc.scc.size()){
        ans += scc.scc[i].size() * (scc.scc[i].size()-1) / 2;
    }
    O(ans);
}