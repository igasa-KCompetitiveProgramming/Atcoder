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
vector<int> dh = {1,-1,0,0};
vector<int> dw = {0,0,1,-1};

int main(){
    LL(h,w);
    vector<vector<bool>> field(h,vector<bool>(w, false));
    vector<string> s(h);
    queue<pint> q;
    rep(h){
        cin >> s[i];
        rep(j,w){
            if(s[i][j] == '.') field[i][j] = false;
            else{
                field[i][j] = true;
                q.push({i,j});
            }
        }
    }
    while(true){
        if(q.empty()) break;
        int tmp = q.size();
        rep(t, tmp){
            auto[i,j] = q.front(); q.pop();
            field[i][j] = true;
            q.push({i,j});
        }
        rep(t, tmp){
            auto[i,j] = q.front(); q.pop();
            //cout << i << spa << j << endl;
            rep(k,4){
                int cnt = 0;
                int ni = i + dh[k];
                int nj = j + dw[k];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if(field[ni][nj]) continue;
                //cout << spa << ni << spa << nj << endl;
                rep(l,4){
                    int ti = ni + dh[l];
                    int tj = nj + dw[l];
                    if(ti < 0 || ti >= h || tj < 0 || tj >= w) continue;
                    //cout << spa << spa << ti << spa << tj << spa << field[ti][tj] << endl;
                    if(field[ti][tj]) cnt++;
                }
                //cout << cnt << endl;
                if(cnt == 1) q.push({ni, nj});
            }
        }
    }
    ll answer = 0;
    rep(i,h){
        rep(j,w){
            //cout << field[i][j];
            if(field[i][j]) answer++;
        }
        //cout << endl;
    }
    cout << answer << endl;
}