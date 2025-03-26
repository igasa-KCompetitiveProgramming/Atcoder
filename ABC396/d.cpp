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

unsigned long long ans = INF;

void dfs(int n, vector<vector<pair<int,bitset<63>>>> &g, bitset<63> b, vector<bool> used){
    int tmp = b.to_ullong();
    if(n == g.size()-1){
        ans = min(ans, b.to_ullong());
        return;
    }
    used[n] = true;
    for(auto x : g[n]){
        if(used[x.fi]) continue;
        b ^= x.se;
        tmp = b.to_ullong();
        dfs(x.fi, g, b, used);
        b ^= x.se;
    }
}

int main(){
    LL(n,m);
    vector<vector<pair<int, bitset<63>>>> g(n);
    rep(m){
        LL(u,v,w);
        bitset<63> b(w);
        u--; v--;
        g[u].pb({v,b});
        g[v].pb({u,b});
    }
    vector<bool> used(n,false);
    bitset<63> b(0);
    dfs(0, g, b, used);
    cout << ans << endl;
}