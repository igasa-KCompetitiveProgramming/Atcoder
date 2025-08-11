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
bool flag = true;

const vector<pair<int, int>> d = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

class SOLVE{
  public:
    ld n, m;
    vector<vector<ld>> field;
    vector<vector<tuple<ld, vector<vector<ld>>, vector<pint>>>> beam;

    void input(){
        cin >> n >> m;
        beam.resize(n * n - m + 1, vector<tuple<ld, vector<vector<ld>>, vector<pint>>>(Beam_Width, make_tuple(-1.0L, vector<vector<ld>>(1, vector<ld>(1)), vector<pint>())));
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

        std::get<0>(beam[0][0]) = 1;
        std::get<1>(beam[0][0]) = field;
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

    void calc_next_perm(vector<vector<ld>> &field, pint beam_index, vector<tuple<ld, int, pint>> &find_minimum_perm, vector<vector<ld>> &beam_field){
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
                //cout << next_field[i][j] << spa;
                if(next_field[i][j] == -1) continue;
                minimum_perm.insert({next_field[i][j], {i, j}});
            }
            //cout << endl;
        }
        //cout << endl;
        beam_field = next_field;
        int counter = 0;
        for(auto &p : minimum_perm){
            ld value = p.fi;
            pint pos = p.se;
            if(!flag){
                if(pos.fi == 0 || pos.fi == n - 1 || pos.se == 0 || pos.se == n - 1){
                    continue;
                }
            }
            next_field[pos.fi][pos.se] = -1;
            pint bi = beam_index;
            value = get<0>(beam[bi.fi][bi.se]) - value;
            find_minimum_perm.pb({value, bi.se, pos});
            next_field[pos.fi][pos.se] = value;
            counter++;
            if(counter >= Beam_Width) break;
        }
        //cout << endl;
    }
};

// beam = tuple<ld, vector<vector<ld>>, vector<pint>> = perm, field, answer

int main(){
    SOLVE s;
    cout << fixed << setprecision(10);
    s.input();
    rep(s.n * s.n - s.m){
        if(i + 200 == s.n * s.n - s.m) flag = true;
        //cout << "i : " << i << endl;
        vector<tuple<ld, int, pint>> find_minimum_perm; // fi = beam_index, se = position
        vector<vector<vector<ld>>> beam_field(Beam_Width, vector<vector<ld>>(s.n, vector<ld>(s.n, 0)));
        rep(j, s.beam[i].size()){
            if(std::get<0>(s.beam[i][j]) <= 0) continue;
            s.calc_next_perm(std::get<1>(s.beam[i][j]), {i , j}, find_minimum_perm, beam_field[j]);
            sort(find_minimum_perm.rbegin(), find_minimum_perm.rend());
        }
        rep(j, find_minimum_perm.size()){
            if(j >= Beam_Width) break;
            //cout << get<0>(find_minimum_perm[j]) << spa << get<1>(find_minimum_perm[j]) << spa << get<2>(find_minimum_perm[j]).fi << spa << get<2>(find_minimum_perm[j]).se << endl;
            pint pos = get<2>(find_minimum_perm[j]);
            s.beam[i + 1][j] = make_tuple(
                get<0>(find_minimum_perm[j]),
                beam_field[get<1>(find_minimum_perm[j])],
                std::get<2>(s.beam[i][get<1>(find_minimum_perm[j])])
            );
            get<1>(s.beam[i + 1][j])[pos.fi][pos.se] = -1;
            get<2>(s.beam[i + 1][j]).pb(pos);
        }
    }
    vector<pint> answer = get<2>(s.beam[s.n * s.n - s.m][0]);
    rep(answer.size()){
        cout << answer[i].fi << " " << answer[i].se << endl;
    }
}