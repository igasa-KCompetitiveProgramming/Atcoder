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
bool ans = true;

int dfs(int see, vector<vector<int>> &g, vector<bool> &used, vector<bool> &visited, int k){
    int cnt = k;
    int tmp = 0;
    visited[see] = true;
    for(auto x : g[see]){
        if(visited[x]) continue;
        tmp++;
        cnt = dfs(x, g, used, visited, cnt);
    }
    //cout << see << spa << tmp << spa << cnt << endl;
    if(tmp == 0 || cnt == k){
        return k-1;
    }else{
        if(cnt != 1){
            cout << endl;
            ans = false;
            return 0;
        }else{
            return k;
        }
    }
    return 0;
}

int main(){
    LL(n,k);
    vector<ll> u(n*k - 1),v(n*k - 1);
    vector<vector<int>> g(n*k);
    rep(n*k - 1) cin >> u[i] >> v[i];
    rep(n*k - 1){
        u[i]--;
        v[i]--;
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    vector<bool> used(n*k,false);
    vector<bool> visited(n*k,false);
    dfs(0, g, used, visited, k);
    if(ans) cout << "Yes";
    else cout << "No";
}