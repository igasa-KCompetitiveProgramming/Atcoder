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

ll calc_time(vector<vector<ll>> &graph, vector<vector<ll>> &graph_list, vector<bool> &have_air, vector<ll> &air_list, ll t){
    ll answer = 0;
    rep(graph.size()){
        priority_queue<pll, vector<pll>, greater<pll>> que; // {cost, next}
        que.push({0, i});
        vector<ll> dist(graph.size(), -1);
        vector<bool> visited(graph.size(), false);
        dist[i] = 0;
        while(!que.empty()){
            auto [cost, now] = que.top();
            que.pop();
            if(visited[now]) continue;
            //cout << cost << spa << now << endl;
            visited[now] = true;
            dist[now] = cost;
            //cout << spa << spa << now << spa << cost << endl;
            if(have_air[now]){
                rep(j, air_list.size()){
                    if(now == air_list[j]) continue;
                    ll next = air_list[j];
                    if(visited[next]) continue;
                    //cout << spa << "air" << spa << next << endl;
                    ll next_cost = cost + t;
                    que.push({next_cost, next});
                }
            }
            for(auto next : graph_list[now]){
                ll next_cost = cost + graph[now][next];
                if(visited[next]) continue;
                que.push({next_cost, next});
            }
        }
        rep(j, dist.size()){
            if(dist[j] == -1) continue; // 到達不可能
            answer += dist[j];
        }
    }
    return answer;
}

int main(){
    LL(n,m);
    vector<ll> a(m), b(m), c(m);
    vector<vector<ll>> graph(n, vector<ll>(n, 0));
    vector<vector<ll>> graph_list(n);
    rep(m) cin >> a[i];
    rep(m) cin >> b[i];
    rep(m) cin >> c[i];
    rep(m){
        a[i]--; b[i]--;
        graph[a[i]][b[i]] = c[i];
        graph[b[i]][a[i]] = c[i];
        graph_list[a[i]].pb(b[i]);
        graph_list[b[i]].pb(a[i]);
    }
    LL(k,t);
    vector<ll> d(k);
    vector<bool> have_air(n, false);
    vector<ll> air_list;
    rep(k){
        cin >> d[i];
        d[i]--;
        have_air[d[i]] = true;
        air_list.push_back(d[i]);
    }
    ll ans = 0;
    ans = calc_time(graph, graph_list, have_air, air_list, t);
    LL(q);
    bool flag = true;
    rep(q){
        LL(type);
        if(type == 1){
            LL(x, y, time);
            x--; y--;
            if(graph[x][y] == 0 || graph[x][y] > time){
                flag = false;
                graph[x][y] = time;
                graph[y][x] = time;
                graph_list[x].pb(y);
                graph_list[y].pb(x);
            }
        }else if(type == 2){
            LL(x);
            x--;
            if(!have_air[x]){
                have_air[x] = true;
                air_list.pb(x);
                flag = false;
            }
        }else{
            if(!flag) ans = calc_time(graph, graph_list, have_air, air_list, t);
            flag = true;
            cout << ans << endl;
        }
    }
}