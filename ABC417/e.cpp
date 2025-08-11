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

void dfs(ll now, vector<set<ll>>& g, vector<bool>& visited, vector<ll>& prev) {
    visited[now] = true;
    for (ll next : g[now]) {
        if (!visited[next]) {
            prev[next] = now;
            dfs(next, g, visited, prev);
        }
    }
}

void hukugen(ll start, ll end, vector<ll>& prev) {
    vector<ll> path;
    for (ll v = end; v != -1; v = prev[v]) {
        path.pb(v);
    }
    reverse(path.begin(), path.end());
    for (ll v : path) {
        cout << v + 1 << " ";
    }
    cout << endl;
}

int main(){
    LL(t);
    rep(timer,t){
        LL(n,m,x,y);
        vector<ll> u(m), v(m);
        rep(m) cin >> u[i] >> v[i];
        vector<set<ll>> g(n);
        rep(m){
            g[u[i] - 1].insert(v[i] - 1);
            g[v[i] - 1].insert(u[i] - 1);
        }
        vector<bool> visited(n, false);
        vector<ll> prev(n, -1);
        dfs(x - 1, g, visited, prev);
        hukugen(x - 1, y - 1, prev);
    }
}