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

int main(){
    vector<string> s(48);
    rep(48){
        rep(j,48){
            s[i] += '-';
        }
    }
    pll now = {0, -1};
    ll dir = 0; // 0:右, 1:下, 2:左, 3:上
    char c = 'A';
    ll count = 48 * 48; // 48x48のマスに文字を置く
    while(true){
        //cout << now.fi << spa << now.se << spa << count << endl;
        int nx = now.fi + dy[dir];
        int ny = now.se + dx[dir];
        if(nx < 0 || nx >= 48 || ny < 0 || ny >= 48){
            dir = (dir + 1) % 4; // 方向転換
            continue;
        }
        //cout << s[nx][ny] << endl;
        if(s[nx][ny] == '-'){
            s[nx][ny] = c; // 文字を置く
            now = {nx, ny}; // 現在位置を更新
            c = char(c + 1);
            if(c > 'Z') {
                c = 'A'; // A-Zを繰り返す
            }
            count--;
            if(count == 0) {
                break; // 全てのマスに文字を置いたら終了
            }
        } else {
            dir = (dir + 1) % 4; // 方向転換
        }
    }
    rep(48){
        cout << s[i] << endl; // 結果を出力
    }
    rep(48){
        cout << s[i][i];
    }
}