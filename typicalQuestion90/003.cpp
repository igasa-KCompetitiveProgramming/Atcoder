#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

//可変長引数で入力を受け取りつつ変数を宣言
inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__) 

#define v(a,i) vector<ll> a(i)
#define vv(a,i,j) vector<vector<ll>> a(i, vector<ll>(j))
#define vp(a,i) vector<pll>> a(i)
#define vvp(a,i,j) vector<vector<pll>> a(i, vector<>>(j))

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

int main(){
    LL(n);
    v(a,n-1);v(b,n-1);
    vv(g,n,0);
    rep(n-1){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    v(c,n);
    c = vector<ll>(n,-1);
    c[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        auto v = q.front();q.pop();
        for(auto nv : g[v]){
            if(c[nv] == -1){
                c[nv] = c[v]+1;
                q.push(nv);
            }
        }
    }
    ll mv = -1;ll mx = -1;
    rep(n){
        if(c[i] > mx){
            mx = c[i];
            mv = i;
        }
    }
    c = vector<ll>(n,0);
    ll ans = 0;
    q.push(mv);
    c = vector<ll>(n,-1);
    c[mv] = 0;
    while(!q.empty()){
        auto v = q.front();q.pop();
        for(auto nv : g[v]){
            if(c[nv] == -1){
                c[nv] = c[v]+1;
                q.push(nv);
            }
        }
    }
    rep(n){
        ans = max(ans,c[i]);
    }
    O(ans+1);
}