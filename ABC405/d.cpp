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

const vector<ll> dx = {1, 0, -1, 0};
const vector<ll> dy = {0, 1, 0, -1};
const string dir = "^<v>";

int main(){
    LL(h,w);
    vector<string> s(h);
    rep(h) cin >> s[i];
    priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, greater<tuple<ll, ll, ll, ll>>> pq;
    vector<tuple<ll,ll,ll>> esc;
    rep(h){
        rep(j,w){
            if(s[i][j] == '#'){
            }else if(s[i][j] == 'E'){
                esc.pb({i, j, esc.size() + 1});
                pq.push({0, i, j, -1});
            }
        }
    }
    vector<string> ans = s;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    while(!pq.empty()){
        auto [dist, x, y, direction] = pq.top();
        pq.pop();
        if(used[x][y]) continue;
        if(direction != -1)ans[x][y] = dir[direction];
        used[x][y] = true;
        rep(i,4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(s[nx][ny] == '#' || s[nx][ny] == 'E') continue;
            if(used[nx][ny]) continue;
            pq.push({dist + 1, nx, ny, i});
        }
    }
    rep(ans.size()) cout << ans[i] << endl;
}