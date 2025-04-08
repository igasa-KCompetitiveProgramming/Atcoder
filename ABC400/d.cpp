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

vector<ll> dx = {0, 1, 0, -1};
vector<ll> dy = {1, 0, -1, 0};

int main(){
    LL(h,w);
    vector<string> s(h);
    rep(h) cin >> s[i];
    pll start,goal;
    cin >> start.fi >> start.se >> goal.fi >> goal.se;
    start.fi--;
    start.se--;
    goal.fi--;
    goal.se--;
    vector<vector<int>> visited(h, vector<int>(w, -1));
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
    pq.push({0,start.fi,start.se});
    while(!pq.empty()){
        auto [dist,x,y] = pq.top();
        pq.pop();
        //cout << dist << spa << x << spa << y << endl;
        if(visited[x][y] <= dist && visited[x][y] != -1) continue;
        visited[x][y] = dist;
        if(x == goal.fi && y == goal.se){
            cout << dist << endl;
            return 0;
        }
        rep(i,4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            ll nxx = x + dx[i] * 2;
            ll nyy = y + dy[i] * 2;
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(visited[nx][ny] != -1 && visited[nx][ny] <= dist) continue;
            if(s[nx][ny] == '#') pq.push({dist + 1, nx, ny});
            else pq.push({dist, nx, ny});
            if(s[nx][ny] == '#' && nxx >= 0 && nxx < h && nyy >= 0 && nyy < w){
                if(visited[nxx][nyy] != -1 && visited[nxx][nyy] <= dist + 1) continue;
                if(s[nxx][nyy] == '#') pq.push({dist + 1, nxx, nyy});
            }
        }
    }
}