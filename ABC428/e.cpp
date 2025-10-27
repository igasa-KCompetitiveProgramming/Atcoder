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
    LL(n);
    vector<int> u(n - 1), v(n - 1);
    vector<vector<int>> g(n);
    rep(n - 1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    vector<int> res;
    vector<pint> dist;
    vector<bool> used(n, false);
    queue<pint> q;
    q.push({0, 0});
    while(true){
        if(q.empty()) break;
        auto [now, d] = q.front(); q.pop();
        if(used[now]) continue;
        used[now] = true;
        dist.pb({d, now});
        int cnt = 0;
        rep(g[now].size()){
            if(used[g[now][i]]) continue;
            q.push({g[now][i], d + 1});
            cnt++;
        }
        if(cnt == 0) res.pb(now);
    }
    vector<pint> oya(n, {-1,-1});
    rep(res.size()){
        q.push({res[i], 0});
        oya[res[i]] = {0, -1};
    }
    used.resize(n, false);
    while(true){
        auto[now, _] = q.front(); q.pop();
        if(used[now]) continue;
        used[now] = true;
        rep(g[now].size()){
            int next = g[now][i];
            
        }
    }
    cout << endl;
    rep(dist.size()){
        cout << dist[i].se + 1 << spa << dist[i].fi << endl;
    }
}