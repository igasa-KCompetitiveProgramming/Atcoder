#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

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
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> y(m);
    rep(i,m){
        cin >> y[i].fi;
        y[i].fi--;
    }
    rep(i,m){
        cin >> y[i].se;
    }
    v(x,m);
    v(a,m);
    rep(i,m){
        x[i] = y[i].fi;
    }
    rep(i,m){
        a[i] = y[i].se;
    }
    ll ans = 0;
    v(check, m);
    ll prev = 0;
    ll cnt = 0;
    
    ll cnt2 = 0;
    rep(i,m-1){
        if(x[i+1] - x[i] > a[i] + cnt2){
            print(-1);
            return 0;
        }
        cnt2 += a[i] - (x[i+1] - x[i]);
    }

    rrep(i,m){
        check[i] = cnt;
        cnt = 0;
        check[i] += prev - x[i] - 1;
        if(check[i] > a[i] - 1) cnt += check[i] - a[i];
        prev = x[i];
    }
    if(cnt > 0){
        print(-1);
        return 0;
    }
    prev = 0;
    rep(i,m - 1){
        ans += (x[i+1] - x[i])*(x[i+1] - x[i] - 1)/2;
        if(check[i] - a[i] > 0) ans += (x[i+1] - x[i])*(check[i] - a[i]);
    }
    ans += (n - x[m-1])*(n - x[m-1] - 1)/2;
    cout << ans << endl;
}