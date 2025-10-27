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
int main(){
    auto start = chrono::high_resolution_clock::now();
    LL(n);
    vector<ll> x(n),y(n);
    rep(n) cin >> x[i] >> y[i];
    set<ll> st;
    set<tuple<ll,ll,ll>> used;
    while(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() < 1900){
        ll tmp = rand() % n;
        ll res = rand() % n;
        if(tmp == res) continue;
        if(tmp < res) swap(tmp, res);
        ll now = tmp * n + res;
        if(st.count(now)) continue;
        st.insert(now);
        ll a = y[tmp] - y[res];
        ll b = x[res] - x[tmp];
        ll c = (x[tmp] - x[res])*y[tmp] + (y[res] - y[tmp])*x[tmp];
        //cout << a << spa << b << spa << c << '\n';
        if(used.count({a,b,c})) continue;
        used.insert({a,b,c});
        ll ans = 0;
        rep(n){
            if(a * x[i] + b * y[i] + c == 0) ans++;
        }
        if(ans > n / 2){
            cout << "Yes" << '\n';
            cout << a << spa << b << spa << c << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}