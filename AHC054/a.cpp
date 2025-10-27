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

const vector<int> di = {-1,1,0,0};
const vector<int> dj = {0,0,-1,0};
const vector<pint> dn ={
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};

int counter = 0;

struct bs{
    vector<vector<char>> Bfield;
    int score = 0;
};

class SOLVE{
public:
    int size;
    pint target;
    vector<vector<char>> field;

    void input(){
        cin >> size >> target.fi >> target.se;
        field.resize(size, vector<char>(size));
        rep(size){
            rep(j,size){
                cin >> field[i][j];
            }
        }
    }

    pint positionCheck(){

    }

    void solve(){
        /*
        while(true){
            pint now = positionCheck();
            if(now == {-1,-1}) continue;

        }
        */
    }

    void checker(pint now, vector<vector<bool>>& stage){
        rep(4){
            pint next = now;
            while(true){
                next.fi += dn[i].fi; next.se += dn[i].se;
                if(next.fi < 0 || next.fi >= size || next.se < 0 || next.se >= size) break;
                if(field[next.fi][next.se] == 'T') break;
                if(stage[next.fi][next.se]) break;
                stage[next.fi][next.se] = true;
            }
        }
    }

    int truescorecheck(vector<vector<char>>& nowfield){
        pint start = {0, size/2};
        int timer = 0;
        vector<vector<bool>> stage(size, vector<bool>(size, false));
        stage[start.fi][start.se] = true;
        if(stage[target.fi][target.se]) return timer;
        counter = 0;
        return saiki(start, nowfield, stage, -1);
    }

    int saiki(pint now, vector<vector<char>>& nowfield, vector<vector<bool>>& stage, int dir){
        if(now != pint{0, size/2}) checker(now, stage);
        if(stage[target.fi][target.se]) return counter;
        stage[now.fi][now.se] = true;
        rep(4){
            int ni = now.fi + dn[i].fi;
            int nj = now.se + dn[i].se;
            if(ni < 0 || ni >= size || nj < 0 || nj >= size) continue;
            if(stage[ni][nj]) continue;
            if(nowfield[ni][nj] == 'T') continue;
            counter++;
            saiki(pint{ni,nj}, nowfield, stage, i);
            if(stage[target.fi][target.se]) return counter;
        }
        return counter++;
    }

    bool dijk(){
        pint now = {0, size/2};
        vector<vector<bool>> visited(size, vector<bool>(size,false));
        priority_queue<pair<int,pint>, vector<pair<int,pint>>, greater<pair<int,pint>>> pq;
        pq.push({0, now});
        while(!pq.empty()){
            auto [cost, pos] = pq.top(); pq.pop();
            if(visited[pos.fi][pos.se]) continue;
            visited[pos.fi][pos.se] = true;
            if(pos == target) return true;
            rep(4){
                pint next = pos;
                next.fi += dn[i].fi; next.se += dn[i].se;
                if(next.fi < 0 || next.fi >= size || next.se < 0 || next.se >= size) continue;
                if(field[next.fi][next.se] == 'T') continue;
                if(visited[next.fi][next.se]) continue;
                pq.push({cost + 1, next});
                if(next == target) return true;
            }
        }
        return false;
    }

    void solve_bfs(chrono::system_clock::time_point start){
        vector<vector<bs>> bfs(1,vector<bs>(1));
        bfs[0][0].Bfield.resize(size, vector<char>(size));
        rep(size){
            rep(j,size){
                bfs[0][0].Bfield[i][j] = field[i][j];
            }
        }
        while(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() < 1800){
            vector<vector<char>> bffield(size, vector<char>(size));
            rep(size){
                rep(j,size){
                    bffield[i][j] = bfs[0][0].Bfield[i][j];
                }
            }
            rep(size){
                rep(j,size){
                    if(bffield[i][j] == 'T') continue;
                    if(target == pint{i,j}) continue;
                    bffield[i][j] = 'T';
                    if(dijk()){
                        bfs[1].push_back(bs{bffield, truescorecheck(bffield)});
                    }
                    bffield[i][j] = '.';
                }
            }
            break;
        }
        cout << bfs.size() << endl;
        rep(bfs.size()){
            cout << i << spa << bfs[i].size() << endl << spa << endl;
            rep(j,bfs[i].size()){
                cout << bfs[i][j].score << endl;
                rep(k,size){
                    rep(l,size){
                        cout << bfs[i][j].Bfield[k][l];
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        cout << "here" << endl;
    }
};

int main(){
    auto start = chrono::system_clock::now();
    SOLVE solve;
    solve.input();
    solve.solve_bfs(start);
    return 0;
}