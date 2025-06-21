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
const string d = "DRUL";

beamSearch B;

class SOLVE{
  public:
    ll n;
    vector<vector<pll>> field;
    vector<char> answer;
    vector<pll> goal;

    void input(){
        cin >> n;
        field.resize(n, vector<pll>(n, {-1, -1}));
        rep(i, n) {
            rep(j, n) {
                LL(w);
                field[i][j].fi = w; // 重さ
            }
        }
        rep(i, n) {
            rep(j, n) {
                LL(d);
                field[i][j].se = d; // 耐久度
            }
        }
    }

    void findPath(pll start, pll goal){
        pll now = start;
        while(true){
            if(now == goal) break;
            ll x = now.fi, y = now.se;
            if(x > goal.fi) {
                answer.pb('U');
                now.fi--;
            } else if(x < goal.fi) {
                answer.pb('D');
                now.fi++;
            } else if(y > goal.se) {
                answer.pb('L');
                now.se--;
            } else if(y < goal.se) {
                answer.pb('R');
                now.se++;
            }
        }
    }

    void twoBoxesHas(int beamIndex){
        pll now = {0, 0};
        priority_queue<pair<int, pint>, vector<pair<int, pint>>> pq;
        vector<pll> goal;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                pq.push({i + j, {i, j}});
            }
        }
        while(!pq.empty()){
            auto [d, pos] = pq.top();
            pq.pop();
            goal.pb(pos);
        }
        multiset<pair<ll, pint>> durabilitySet;
        rep(i, n){
            rep(j, n){
                if(field[i][j].fi != -1){
                    durabilitySet.insert({field[i][j].se, {i, j}});
                }
            }
        }
        while(!pq.empty()){
            auto [d, goal] = pq.top();
            pq.pop();
            if(field[goal.first][goal.second].fi == -1) continue;
            ll durability = -1; pint pos = {-1, -1};
            // iteratorの保管
            while(true){
                if(durabilitySet.empty()) break;
                auto[tmp, res] = *durabilitySet.rbegin();
                if(durabilitySet.upper_bound({field[goal.first][goal.second].fi * (goal.fi + goal.se) * 2, {goal.first, goal.second}}) != durabilitySet.end()) {
                    auto[tmp3, res3] = *durabilitySet.upper_bound({(ll)((double)(field[goal.first][goal.second].fi) * (goal.fi + goal.se) * 2), {goal.first, goal.second}});
                    tmp = tmp3;
                    res = res3;
                }
                //cout << endl << tmp << spa << res.fi << spa << res.se << endl;
                durability = tmp;
                pos = res;
                if(pos == goal) break;
                if(field[pos.first][pos.second].fi == -1) durabilitySet.erase(durabilitySet.find({durability, pos}));
                else break;
                durability = -1; pos = {-1, -1};
            }
            //cout << durability << spa << goal.fi << spa << goal.se << spa << (goal.fi + goal.se) * field[goal.fi][goal.se].fi << spa << field[goal.fi][goal.se].fi << spa << field[goal.fi][goal.se].se << endl;
            if(durability <= field[goal.first][goal.second].fi * (goal.fi + goal.se) || pos == goal){
                findPath(now, goal);
                now = goal;
                durability = field[goal.first][goal.second].se;
            }else{
                findPath(now, pos);
                now = pos;
                durabilitySet.erase(durabilitySet.find({durability, pos}));
                answer.pb('1');
                findPath(now, goal);
                now = goal;
                field[pos.first][pos.second].fi = -1; // 持っていた箱を消す
                //cout << durability - field[goal.first][goal.second].fi * (goal.fi + goal.se) << spa << field[goal.first][goal.second].se << endl;
                durability = min(durability - field[goal.first][goal.second].fi * (goal.fi + goal.se), field[goal.first][goal.second].se);
            }
            field[goal.first][goal.second].fi = -1; // 目的地の箱を消す
            answer.pb('1'); 

            int cnt = 0;
            while(true){
                pint next = {-1, -1};
                ll minDistance = inf;
                rep(j, now.fi){
                    rep(k, now.se){
                        if(j == now.fi && k == now.se) continue;
                        if(j == 0 && k == 0) continue;
                        if(field[j][k].fi == -1) continue;
                        if(durability - field[j][k].fi * (j + k) <= 0) continue;
                        ll distance = abs(durability - 2*(field[j][k].fi * (j + k)));
                        if(distance < minDistance){
                            minDistance = distance;
                            next = {j, k};
                        }
                    }
                }
                if(next == make_pair(-1, -1)) break; // 次の箱がない場合
                findPath(now, next);
                answer.pb('1');
                now = next;
                durability = min(durability - field[now.fi][now.se].fi * (now.fi + now.se), field[now.fi][now.se].se);
                field[next.fi][next.se].fi = -1; // 次の箱を消す
                cnt++;
            }

            findPath(now, {0, 0});
            now = {0, 0};
            if(beamIndex != -1) {
                
            }
        }
    }

    void answerOutput(){
        rep(i, answer.size()){
            cout << answer[i] << endl;
        }
    }
};

class beamSearch{
  public:
    int beamWidth;
    vector<pair<int, SOLVE>> beam;

    void setup(int width, SOLVE& solve){
        beamWidth = width;
        beam.resize(beamWidth);
        rep(i, beamWidth){
            beam[i].fi = 0; // beamのインデックス
            beam[i].se = solve;
        }
    }

    void solve(){
        beam.resize(beamWidth);
        
    }
};

int main(){
    
    SOLVE solve;
    solve.input();
    B.setup(10, solve);
    solve.twoBoxesHas(-1);
    solve.answerOutput();
}