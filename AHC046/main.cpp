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

vector<ll> dx = {1, 0, -1, 0};
vector<ll> dy = {0, 1, 0, -1};
string d = "DRUL";
map<char,char> reverse_d = {
    {'D', 'U'},
    {'R', 'L'},
    {'U', 'D'},
    {'L', 'R'}
};

class SOLVE{
  public:
    ll n, m;
    vector<pll> goal;
    vector<pair<char, char>> answer;

    vector<bool> usedBox;


    void input(){
        cin >> n >> m;
        goal.resize(m);
        rep(i, m){
            cin >> goal[i].fi >> goal[i].se;
        }

        usedBox.resize(m, false);
    }

    void dijkstra(){
        vector<vector<int>> field(n,vector<int>(n,-1));
        rep(i, m - 1){
            vector<vector<pair<pair<char,char>, pll>>> prev(n,vector<pair<pair<char,char>,pll>>(n, {{'-','-'},{-1,-1}}));
            priority_queue<tuple<ll, pll, pll, pair<char, char>>, vector<tuple<ll, pll, pll, pair<char, char>>>, greater<tuple<ll, pll, pll, pair<char, char>>>> pq;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            prev[goal[i].fi][goal[i].se] = {{'s','s'},{-1,-1}};
            pq.push({0, {goal[i]}, {-1,-1}, {'-','-'}});
            while(!pq.empty()){
                field[goal[i].fi][goal[i].se] = i;
                auto[dist, tmp, before, res] = pq.top();
                ll x = tmp.fi;
                ll y = tmp.se;
                pq.pop();
                if(visited[x][y]) continue;
                visited[x][y] = true;
                prev[x][y] = {res, before};
                if(x == goal[i + 1].fi && y == goal[i + 1].se){
                    //cout << spa << goal[i + 1].fi << ' ' << goal[i + 1].se << endl;
                    break;
                }
                rep(j,4){
                    ll nx = x + dx[j];
                    ll ny = y + dy[j];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(field[nx][ny] == -1) continue;
                    pq.push({dist + 1, {nx, ny}, {x, y}, {'M', d[j]}});
                }
                rep(j,4){
                    ll nx = x;
                    ll ny = y;
                    while(true){
                        ll cx = nx + dx[j];
                        ll cy = ny + dy[j];
                        if(cx < 0 || cx >= n || cy < 0 || cy >= n) break;
                        if(field[cx][cy] != -1){
                            usedBox[field[cx][cy]] = true;
                            break;
                        }
                        nx = cx,ny = cy;
                    }
                    pq.push({dist + 1, {nx, ny}, {x, y}, {'S', d[j]}});
                }
            }
            vector<pair<char, char>> ans;
            pll now = goal[i + 1];
            while(true){
                auto[res, before] = prev[now.fi][now.se];
                //cout << before.fi << ' ' << before.se << endl;
                if(res.fi == '-' && res.se == '-') break;
                if(res.fi != 's' && res.se != 's') ans.pb(res);
                now = before;
            }
            //cout << ans.size() << endl;
            bool flag = false;
            if(ans.size() > 1) flag = true;
            rep(j, ans.size()){
                if(ans[j].fi == 'S'){
                    flag = true;
                    break;
                }
            }
            if(flag){
                if(ans[ans.size() - 1].fi == 'S'){
                    ans.pb({'A', reverse_d[ans[ans.size() - 1].se]});
                    ans.pb({'M', reverse_d[ans[ans.size() - 1].se]});
                }else{
                    char rev = reverse_d[ans[ans.size() - 1].se];
                    ans.pop_back();
                    ans.pb({'A', rev});
                    ans.pb({'M', reverse_d[rev]});
                }
            }else{
                field[goal[i].fi][goal[i].se] = false;
            }
            //cout << ans.size() << endl;
            reverse(ans.begin(), ans.end());
            rep(j, ans.size()){
                answer.pb(ans[j]);
            }
        }
    }

    void improve(){

    }

    void guess(){
        rep(answer.size()) cout << answer[i].fi << spa << answer[i].se << endl;
    }
};

int main(){
    SOLVE solve;
    solve.input();
    solve.dijkstra();
}