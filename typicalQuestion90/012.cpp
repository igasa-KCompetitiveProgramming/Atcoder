#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define v(a,i,b) vector<ll> a(i,b)
#define vv(a,i,j,b) vector<vector<ll>> a(i, vector<ll>(j,b))
#define vp(a,i,b,c) vector<pll> a(i,{b,c})

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

class UnionFind{
public:
    vector<vector<pll>> par;

    UnionFind(ll h, ll w){
        par = vector<vector<pll>>(h, vector<pll>(w, {-1, -1}));
        rep(h) rep(j, w) par[i][j] = {i, j};
    }

    pll find(pll a){
        if(par[a.fi][a.se] == a) return {a};
        return par[a.fi][a.se] = find(par[a.fi][a.se]);
    }

    void merge(pll a, pll b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        par[a.fi][a.se] = b;
    }

    bool connected(pll a, pll b){
        return find(a) == find(b);
    }
};

int main(){
    const vector<pll> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    LL(h, w);
    LL(q);
    UnionFind uf(h, w);
    vector<vector<bool>> c(h, vector<bool>(w, false));
    vector<vector<ll>> query(q,vector<ll>(5));
    rep(i,q){
        cin >> query[i][0];
        if(query[i][0] == 1){
            cin >> query[i][1] >> query[i][2];
            query[i][1]--; query[i][2]--;
        }else{
            cin >> query[i][1] >> query[i][2] >> query[i][3] >> query[i][4];
            query[i][1]--; query[i][2]--; query[i][3]--; query[i][4]--;
        }
    }
    rep(q){
        if(query[i][0] == 1){
            c[query[i][1]][query[i][2]] = true;
            rep(j,4){
                ll nh = query[i][1] + dir[j].fi;
                ll nw = query[i][2] + dir[j].se;
                if(nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
                if(c[nh][nw]){
                    uf.merge({query[i][1], query[i][2]}, {nh, nw});
                }
            }
        }else{
            ll nh = query[i][1]; ll nw = query[i][2]; ll nh2 = query[i][3]; ll nw2 = query[i][4];
            if(!c[nh][nw]){ cout << "No" << endl; continue;}
            if(!c[nh2][nw2]) {cout << "No" << endl; continue;}
            if(uf.connected({query[i][1], query[i][2]}, {query[i][3], query[i][4]})){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}