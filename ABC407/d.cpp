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

int main(){
    LL(h,w);
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(h) rep(j,w) cin >> a[i][j];

    vector<bitset<60>> domino;
    domino.pb(0);
    int bit = 0;
    rep(h){
        rep(j,w){
            int cnt = domino.size();
            rep(k,cnt){
                if(j + 1 < w && (domino[k][bit] == 0 && domino[k][bit + 1] == 0)){
                    bitset<60> tmp = domino[k];
                    tmp[bit] = 1;
                    tmp[bit + 1] = 1;
                    domino.pb(tmp);
                }
                if(i + 1 < h && (domino[k][bit] == 0 && domino[k][bit + w] == 0)){
                    bitset<60> tmp = domino[k];
                    tmp[bit] = 1;
                    tmp[bit + w] = 1;
                    domino.pb(tmp);
                }
            }
            bit++;
        }
    }
    unsigned long long ans = 0;
    rep(domino.size()){
        bitset<60> tmp = 0;
        rep(j,h) rep(k,w){
            if(domino[i][j * w + k] == 0){
                tmp ^= a[j][k];
            }
        }
        ans = max(ans, tmp.to_ullong());
    }
    cout << ans << endl;
}