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
    LL(n,m);
    vector<ll> a(m),b(m),w(m);
    rep(m) cin >> a[i] >> b[i] >> w[i];
    vector<vector<vector<ll>>> g(n, vector<vector<ll>>(n));
    rep(m){
        a[i]--; b[i]--;
        g[a[i]][b[i]].pb(w[i]);

    }
    vector<set<ll>> used(n+1);
    queue<tuple<ll,ll,ll>> q; // (now, prev, weight)
    q.push({0, -1, 0});
    while(!q.empty()){
        auto [now, prev, weight] = q.front();
        q.pop();
        if(used[now].count(weight)) continue;
        //cout << now << spa << prev << spa << weight << endl;
        used[now].insert(weight);
        rep(i, n){
            rep(j, g[now][i].size()){
                bitset<20> tmp = weight ^ g[now][i][j];
                ll next_weight = tmp.to_ullong();
                if(!used[i].count(next_weight)){
                    q.push({i, now, next_weight});
                }
            }
        }
    }
    if(used[n-1].size() == 0){
        cout << -1 << endl;
    }else{
        ll ans = *used[n-1].begin();
        cout << ans << endl;
    }
}
    