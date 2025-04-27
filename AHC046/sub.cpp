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

// ！？！？
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

clock_t start;

string d = "UDLR";
vector<ll> dx = {0,0,-1,1};
vector<ll> dy = {-1,1,0,0};

class s {
  public:
    ll n, m;
    vector<pll> goal;
    vector<vector<ll>> field;

    pll now;
    vector<pair<char, char>> ans;
    vector<pair<char, char>> final_ans;
    set<ll> goal_set;
    vector<char> goal_dir;

    void input() {
        cin >> n >> m;
        goal.resize(m);
        field.resize(n, vector<ll>(n));
        goal_dir.resize(m);
        rep(m) cin >> goal[i].fi >> goal[i].se;
        rep(m) {
            if (i == 0) continue;
            field[goal[i].fi][goal[i].se] = i;
        }
    }

    bool checker(vector<bool> use) {
        rep(n) {
            if(use[field[now.fi][i]]) return true; 
        }
        return false;
    }

    void check(char dir, vector<bool> use){
        if(checker(use)){
            if(!use[field[now.fi][now.se]]) return;
            char rev;
            if(dir == 'U') rev = 'D';
            else if(dir == 'D') rev = 'U';
            else if(dir == 'L') rev = 'R';
            else if(dir == 'R') rev = 'L';
            ans.pb({'A',rev});
            field[now.fi][now.se] = 0;
        }
    }

    // Dijkstra法で最短経路を計算
    void dijkstra(pll start, pll goal) {
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        priority_queue<tuple<ll, ll, ll, char>> pq;  // (cost, x, y, action)
        dist[start.fi][start.se] = 0;
        pq.push({0, start.fi, start.se, ' '});

        while (!pq.empty()) {
            ll cost, x, y;
            char last_action;
            tie(cost, x, y, last_action) = pq.top();
            pq.pop();

            if (cost > dist[x][y]) continue;

            if (x == goal.fi && y == goal.se) break;

            // 各方向に移動
            rep(k, 4) {
                ll nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    ll new_cost = cost + 1;
                    if (new_cost < dist[nx][ny]) {
                        dist[nx][ny] = new_cost;
                        pq.push({-new_cost, nx, ny, d[k]});
                    }
                }
            }
        }
    }

    // 近くのゴール方向に移動
    bool near(char dir, pll g) {
        ll i = now.fi;
        ll j = now.se;
        pll cnt = {0, 0};
        if (dir == 'U' || dir == 'D') cnt.se = abs(i - g.fi);
        else cnt.se = abs(j - g.se);
        rep(k, d.size()) {
            if (d[k] == dir) {
                while (true) {
                    if (i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= n) break;
                    if (field[i + dy[k]][j + dx[k]] < 0) break;
                    i = i + dy[k];
                    j = j + dx[k];
                }
            }
        }
        if (dir == 'U' || dir == 'D') cnt.fi = abs(i - g.fi);
        else cnt.fi = abs(j - g.se);
        return cnt.fi < cnt.se;
    }

    void move(char dir, ll i, vector<bool> use) {
        rep(k, d.size()) {
            if (d[k] == dir) {
                if (now.fi + dy[k] < 0 || now.fi + dy[k] >= n || now.se + dx[k] < 0 || now.se + dx[k] >= n) return;
                if (field[now.fi + dy[k]][now.se + dx[k]] < 0) {
                    ans.pb({'A', dir});
                    field[now.fi + dy[k]][now.se + dx[k]] = 0;
                }
                ans.pb({'M', d[k]});
                check(dir, use);
                now.fi += dy[k];
                now.se += dx[k];
            }
        }
    }

    void slide(ll &i, ll &j, char dir) {
        ans.pb({'S', dir});
        rep(k, d.size()) {
            if (d[k] == dir) {
                while (true) {
                    if (now.fi + dy[k] < 0 || now.fi + dy[k] >= n || now.se + dx[k] < 0 || now.se + dx[k] >= n) break;
                    if (field[i + dy[k]][j + dx[k]] < 0) break;
                    now.fi = i + dy[k];
                    now.se = j + dx[k];
                }
            }
        }
    }

    void first(vector<bool> use) {
        now = goal[0];
        rep(i, 1, m) {
            field[goal[i].fi][goal[i].se] = 0;
            pll g = goal[i];
            if (now.fi != g.fi) {
                while (near('U', g)) {
                    if (now.fi - 1 >= 0) {
                        if (field[now.fi - 1][now.se] < 0) {
                            ans.pb({'A', 'U'});
                            field[now.fi - 1][now.se] = 0;
                        }
                    }
                    slide(now.fi, now.se, 'U');
                }
                while (near('D', g)) {
                    if (now.fi + 1 < n) {
                        if (field[now.fi + 1][now.se] < 0) {
                            ans.pb({'A', 'D'});
                            field[now.fi + 1][now.se] = 0;
                        }
                    }
                    slide(now.fi, now.se, 'D');
                }
                while (now.fi != g.fi) {
                    if (now.fi > g.fi) {
                        move('U', i, use);
                    } else {
                        move('D', i, use);
                    }
                }
            }
            if (now.se != g.se) {
                while (near('L', g)) {
                    if (now.se - 1 >= 0) {
                        if (field[now.fi][now.se - 1] < 0) {
                            ans.pb({'A', 'L'});
                            field[now.fi][now.se - 1] = 0;
                        }
                    }
                    slide(now.fi, now.se, 'L');
                }
                while (near('R', g)) {
                    if (now.se + 1 < n) {
                        if (field[now.fi][now.se + 1] < 0) {
                            ans.pb({'A', 'R'});
                            field[now.fi][now.se + 1] = 0;
                        }
                    }
                    slide(now.fi, now.se, 'R');
                }
                while (now.se != g.se) {
                    if (now.se < g.se) {
                        move('R', i, use);
                    } else {
                        move('L', i, use);
                    }
                }
            }
        }
    }

    void second(){
        ll bit_ = 0;
        while(clock() - start < 1.6 * CLOCKS_PER_SEC){
            ll tmp = ans.size();
            ans.clear();
            vector<bool> use(m, false);
            rep(m){ // bit全探索の順部
                if(bit_ & (1 << i)){
                    use[i] = true;
                }
            }
            first(use);
            if(ans.size() > tmp){
                final_ans = ans;
                tmp = ans.size();
            }
            if(ans.size() > tmp){
                final_ans = ans;
                tmp = ans.size();
            }
            bit_++;
        }
    }

    void solve() {
        input();
        first({});
        second();
        rep(ans.size()){
            cout << ans[i].fi << spa << ans[i].se << endl;
        }
    }
};

int main() {
    start = clock();
    s sol;
    sol.solve();
}
