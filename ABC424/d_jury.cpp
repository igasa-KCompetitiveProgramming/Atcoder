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

vector<int> di = {0, 1, 0, 1};
vector<int> dj = {0, 0, 1, 1};

int main(){

}

void saiki(int timer, int i, int j, vector<string> s){
    if(timer == 0) return;
    if(s[i][j] == '.') return;
    s[i][j] = '.';
    if(j + 1 > s[0].size() && i + 1 > s.size()) return;
    
}

void solve_jury(int h, int w, vector<string> &s){
    int ans = 0;
    while(true){
        rep(s.size()){
            bool g = true;
            rep(j,s[0].size()){
                bool f = true;
                rep(k,4){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= h || nj >= w){
                        f = false;
                        continue;
                    }
                    if(s[ni][nj] == '.') f = false;
                }
                if(!f) continue;
                g = false;
                break;
            }
            if(g) break;
        }
        ans++;
        saiki(ans,0,0,s);
    }
}

void solve(int h, int w, vector<string> &s){
    int ans = 0;
    rep(h){
        rep(j,w){
            bool f = true;
            rep(k,4){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= h || nj >= w){
                    f = false;
                    continue;
                }
                if(s[ni][nj] == '.') f = false;
            }
            if(!f) continue;
            s[i + 1][j + 1] = '.';
            ans++;
        }
    }
    cout << ans << endl;
}