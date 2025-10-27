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
const vector<int> dj = {0,0,-1,1};
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
                if(field[next.fi][next.se] == 'T' || field[next.fi][next.se] == 'S') continue;
                if(visited[next.fi][next.se]) continue;
                pq.push({cost + 1, next});
                if(next == target) return true;
            }
        }
        return false;
    }

    void solve(){
        vector<pint> test;
        for(int j = size - 2; j >= 1; j -= 2){
            for(int i = 1; i < size; i++){
                if(field[i][j] == 'T' || field[i][j] == 'S') continue;
                field[i][j] = 'S';
                if(!dijk()) field[i][j] = '.';
            }
        }
        int in;
        if(target.fi >= size/2){
            in = size - 1;
        }else{
            in = 0;
        }
        rep(j,size){
            if(field[in][j] == 'S') field[in][j] = '.';
        }
        if(target.fi >= size/2) in = target.fi - 1;
        else in = target.fi + 1;
        for(int j = 0; j < size; j++){
            if(field[in][j] == 'T' || field[in][j] == 'S') continue;
            field[in][j] = 'S';
            if(!dijk()) field[in][j] = '.';
        }
        rep(size){
            rep(j,size){
                if(field[i][j] == 'S') test.pb({i,j});
            }
        }
        cout << test.size() << spa;
        rep(test.size()){
            cout << test[i].fi << spa << test[i].se << spa;
        }
        cout << endl;
        cout << -1;
        //cout << dijk();
        /*
        rep(size){
            rep(j,size){
                if(pint{i,j} == target) cout << "G";
                else cout << field[i][j];
            }
            cout << endl;
        }
        */
    }
};

int main(){
    auto start = chrono::system_clock::now();
    SOLVE solve;
    solve.input();
    solve.solve();
    return 0;
}