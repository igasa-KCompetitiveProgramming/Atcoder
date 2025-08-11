#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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

int Beam_Width = 8;
vector<pint> answer;

const vector<pair<int, int>> d = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

class SOLVE{
  public:
    ld n, m;
    vector<vector<ld>> field;

    ld max_score = 0;

    void input(){
        cin >> n >> m;
        field.resize(n, vector<ld>(n));
        rep(n){
            rep(j,n){
                char c;
                cin >> c;
                if(c == '#') field[i][j] = -1;
            }
        }
        ld permu = 1 / (n * n - m);
        rep(n){
            rep(j,n){
                if(field[i][j] != -1) field[i][j] = permu;
            }
        }
    }

    pint find_next_position(vector<vector<ld>> &field, int i, int j, int di, int dj){
        while(true){
            int ni = i + di;
            int nj = j + dj;
            if(ni < 0 || ni >= n || nj < 0 || nj >= n) return {i, j};
            if(field[ni][nj] == -1) return {i, j};
            i = ni; j = nj;
        }
    }

    void calc_next_perm(vector<vector<ld>> &field, vector<pint> &answer, ld &score, ld& next_perm){
        vector<vector<ld>> next_field(n, vector<ld>(n, 0));
        rep(n){
            rep(j,n){
                if(field[i][j] == -1) continue;
                rep(k, 4){
                    pint next_pos = find_next_position(field, i, j, d[k].fi, d[k].se);
                    int ni = next_pos.fi;
                    int nj = next_pos.se;
                    next_field[ni][nj] += field[i][j] / 4;
                }
            }
        }
        set<pair<ld,pint>> minimum_perm;
        rep(i, n){
            rep(j, n){
                if(field[i][j] == -1) next_field[i][j] = -1;
                if(next_field[i][j] == -1) continue;
                minimum_perm.insert({next_field[i][j], {i, j}});
            }
        }
        field = next_field;
        auto [minimum_permi, pos] = *minimum_perm.begin();
        next_perm -= minimum_permi;
        score += next_perm;
        next_field[pos.fi][pos.se] = -1;
        field = next_field;
        answer.pb(pos);
    }

    void burn(vector<vector<ld>> &field, vector<pint> &answer, ld &score, ld& next_perm, pint pos){
        vector<vector<ld>> next_field(n, vector<ld>(n, 0));
        rep(n){
            rep(j,n){
                if(field[i][j] == -1) continue;
                rep(k, 4){
                    pint next_pos = find_next_position(field, i, j, d[k].fi, d[k].se);
                    int ni = next_pos.fi;
                    int nj = next_pos.se;
                    next_field[ni][nj] += field[i][j] / 4;
                }
            }
        }
        rep(i, n){
            rep(j, n){
                if(field[i][j] == -1) next_field[i][j] = -1;
                if(next_field[i][j] == -1) continue;
            }
        }
        field = next_field;
        ld minimum_permi = next_field[pos.fi][pos.se];
        next_perm -= minimum_permi;
        score += next_perm;
        next_field[pos.fi][pos.se] = -1;
        field = next_field;
        answer.pb(pos);
    }
};

// beam = tuple<ld, vector<vector<ld>>, vector<pint>> = perm, field, answer

int main(){
    SOLVE s;
    cout << fixed << setprecision(4);
    auto start = chrono::system_clock::now();
    s.input();
    vector<vector<ld>> field_map = s.field;
    ld perm = 1;
    rep(s.n * s.n - s.m){
        s.calc_next_perm(field_map, answer, s.max_score, perm);
    }
    /*
    cout << s.max_score << endl;
    rep(answer.size()){
        cout << answer[i].fi << " " << answer[i].se << endl;
    }
    cout << endl;
    */
    while(chrono::system_clock::now() - start < chrono::milliseconds(1800)){
        ld perm = 1;
        ld score = 0;
        int i = rand() % (answer.size());
        int j = rand() % (answer.size());
        if(i == j) continue;
        if(i > j) swap(i, j);
        if(j >= answer.size()) continue;
        vector<pint> tmp;
        field_map = s.field;
        rep(k, s.n * s.n - s.m){
            if(chrono::system_clock::now() - start >= chrono::milliseconds(1800)) break;
            if(k == i) s.burn(field_map, tmp, score, perm, answer[j]);
            else s.calc_next_perm(field_map, tmp, score, perm);
        }
        if(chrono::system_clock::now() - start >= chrono::milliseconds(1800)) break;
        if(score > s.max_score){
            s.max_score = score;
            answer = tmp;
        }
    }
    rep(answer.size()){
        cout << answer[i].fi << " " << answer[i].se << endl;
    }
}