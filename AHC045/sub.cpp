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

ll n,m,q,l,w;

class UnionFind{
    public:
    UnionFind() = default;

    explicit UnionFind(size_t n) : m_parents(n){
        iota(m_parents.begin(), m_parents.end(), 0);
    }

    ll root(ll i){
        if(m_parents[i] == i) return i;
        return(m_parents[i] = root(m_parents[i]));
    }

    void merge(ll a,ll b){
        a = root(a);
        b = root(b);
        if(a != b) m_parents[b] = a;
    }

    bool connecter(ll a,ll b){
        return root(a) == root(b);
    }
    private:
    vector<ll> m_parents;
};

vector<pll> kruskal(vector<ll> edge_list, vector<pll> edge){
    UnionFind uf(n + 1);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
    rep(edge_list.size()){
        rep(j,edge_list.size()){
            if(i == j) continue;
            ll distance = pow((edge[edge_list[i]].fi - edge[edge_list[j]].fi),2) + pow(edge[edge_list[i]].se - edge[edge_list[j]].se, 2);
            pq.push({distance, edge_list[i], edge_list[j]});
        }
    }
    vector<pll> ret;
    while(!pq.empty()){
        auto [dist, u, v] = pq.top();
        pq.pop();
        if(uf.connecter(u,v)) continue;
        uf.merge(u,v);
        ret.pb({u,v});
        cout << u << spa << v << endl;
    }
    return ret;
}

int main(){
    cin >> n >> m >> q >> l >> w;
    vector<ll> g(m);
    vector<pll> lu(n),rd(n);
    rep(m) cin >> g[i];
    rep(n) cin >> lu[i].fi >> rd[i].fi >> lu[i].se >> rd[i].se;
    vector<pll> edge(n);
    rep(n) cin >> edge[i].fi >> edge[i].se;
    UnionFind uf(n);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
    rep(n){
        rep(j,i+1,n){
            ll dist = pow(edge[i].fi - edge[j].fi,2) + pow(edge[i].se - edge[j].se, 2);
            pq.push({dist,i,j});
        }
    }
    pq = priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>();
    map<pll,ll> mp;
    rep(2){
        vector<ll> edge_list;
        edge_list.pb(0);
        rep(j,2){
            //cout << i << spa << j << endl;
            edge_list.pb(i*2 + j + 1);
        }
        kruskal(edge_list, edge);
    }
}