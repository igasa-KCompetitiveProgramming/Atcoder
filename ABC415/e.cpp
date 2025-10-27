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
    LL(h,w);
    vector<vector<ll>> field(h, vector<ll>(w));
    rep(h) rep(j,w) cin >> field[i][j];
    vector<ll> p(h + w - 1);
    rep(h + w - 1) cin >> p[i];
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<tuple<ll, ll, ll, ll>> que;
    ll sigmP = 0;
    vector<ll> ruiseki(h + w, 0);
    rep(h + w - 1) ruiseki[i + 1] = ruiseki[i] + p[i];
    sigmP = ruiseki[h + w - 1];
    //cout << sigmP << endl;
    que.push({sigmP, 0, 0, 0}); // {cost, i, j}
    ll ans = inf;
    while(!que.empty()){
        auto [cost, i, j, coin] = que.front();
        que.pop();
        cout << i << spa << j << spa << coin << spa << cost << spa << field[i][j] << endl;
        coin += field[i][j];
        ll befCost = cost;
        cout << cost << spa << ruiseki[i + j] << endl;
        cout << sigmP - ruiseki[i + j] << endl;
        cost -= min(coin, sigmP - ruiseki[i + j]);
        coin -= befCost - cost;
        cout << cost << spa << coin << endl;
        if(i + 1 < h && !visited[i + 1][j]){
            que.push({cost , i + 1, j, coin});
        }
        if(j + 1 < w && !visited[i][j + 1]){
            que.push({cost, i, j + 1, coin});
        }
        if(i == h - 1 && j == w - 1){
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
}