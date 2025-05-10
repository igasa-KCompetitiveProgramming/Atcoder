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

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

const ll mod = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    LL(d);
    ll ans = 0;
    int N_m = s[0] - '0';
    vector<vector<vector<ll>>> dp(s.size() + 10, vector<vector<ll>>(2, vector<ll>(d + 10, 0)));

    dp[0][0][0] = 1;

    // dpの遷移
    rep(i,s.size()){
        rep(j,d){
            // dp[i][1] -> dp[i+1][1]の遷移
            rep(k,10){
                dp[i + 1][1][(j + k) % d] += dp[i][1][j];
                dp[i + 1][1][(j + k) % d] %= mod;
            }

            // dp[i][0] -> dp[i+1][1]の遷移
            rep(k,s[i] - '0'){
                dp[i + 1][1][(j + k) % d] += dp[i][0][j];
                dp[i + 1][1][(j + k) % d] %= mod;
            }

            // dp[i][0] -> dp[i+1][0]の遷移
            dp[i + 1][0][(j + s[i] - '0') % d] += dp[i][0][j];
            dp[i + 1][0][(j + s[i] - '0') % d] %= mod;
        }
    }

    /*
    rep(dp.size()){
        rep(j,dp[0].size() + 1){
            cout << dp[i][1][j] << " ";
        }
        cout << endl;
    }
    */

    cout << (dp[s.size()][0][0] + dp[s.size()][1][0] - 1 + mod) % mod << endl;
}