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
    vector<string> s(h);
    rep(h) cin >> s[i];
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(h, vector<ll>(w, inf)));
    pint start, goal;
    rep(h) rep(j, w){
        if(s[i][j] == 'S') start = {i, j};
        if(s[i][j] == 'G') goal = {i, j};
    }
    priority_queue<tuple<int, bool, pint>, vector<tuple<int, bool, pint>>, greater<tuple<int, bool, pint>>> pq;
    vector<vector<vector<bool>>> seen(2, vector<vector<bool>>(h, vector<bool>(w, false)));
    pq.push({0, true, start});
    const vector<int> dx = {1, -1, 0, 0};
    const vector<int> dy = {0, 0, 1, -1};
    while(!pq.empty()){
        auto [cost, swit, p] = pq.top(); pq.pop();
        //cout << endl << p.fi << spa << p.se << spa << swit << spa << cost << endl << endl;
        if(dp[swit][p.fi][p.se] <= cost) continue;
        dp[swit][p.fi][p.se] = cost;
        if(s[p.fi][p.se] == '?') swit = !swit;
        if(p == goal) break;
        rep(4){
            int nx = p.fi + dx[i], ny = p.se + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            //cout << nx << spa << ny << spa << swit << spa << s[nx][ny] << spa << dp[swit][nx][ny] << endl;
            if(s[nx][ny] == '#') continue;
            if(s[nx][ny] == 'x' && swit) continue;
            if(s[nx][ny] == 'o' && !swit) continue;
            if(dp[swit][nx][ny] <= cost) continue;
            pq.push({cost + 1, swit, {nx, ny}});
        }
    }
    if(dp[0][goal.fi][goal.se] == inf && dp[1][goal.fi][goal.se] == inf) print(-1);
    else print(min(dp[0][goal.fi][goal.se], dp[1][goal.fi][goal.se]));
}