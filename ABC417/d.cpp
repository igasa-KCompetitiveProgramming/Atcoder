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
    LL(n);
    vector<ll> p(n), a(n), b(n);
    rep(n) cin >> p[i] >> a[i] >> b[i];
    LL(q);
    vector<ll> y(q);
    rep(q) cin >> y[i];
    vector<vector<vector<pll>>> dp(n + 10, vector<vector<pll>>(1010));
    vector<vector<ll>> answer(n + 10, vector<ll>(1010, -1));
    rep(1010) dp[0][i].pb({0, i});
    rep(n){
        rep(j, 1010){
            rep(k, dp[i][j].size()){
                pll prev = dp[i][j][k];
                if (j > p[i]) {
                    dp[i + 1][max(0LL, j - b[i])].pb(prev);
                }else{
                    dp[i + 1][min(1009LL, j + a[i])].pb(prev);
                }
            }
            pll prev = {i, j};
            if (j > p[i]) {
                dp[i + 1][max(0LL, j - b[i])].pb(prev);
            }else{
                dp[i + 1][min(1009LL, j + a[i])].pb(prev);
            }
        }
    }
    for(int i = n; i >= 0; i--){
        rep(j, 1010){
            rep(k, dp[i][j].size()){
                pll prev = dp[i][j][k];
                if(i == n){
                    answer[prev.fi][prev.se] = j;
                }
                else if(answer[prev.fi][prev.se] == -1) answer[prev.fi][prev.se] = answer[i + 1][j];
            }
        }
    }
    vector<ll> ruiseki(n + 1, 0);
    rep(n){
        ruiseki[i + 1] = ruiseki[i] + b[i];
    }
    //rep(n) cout << ruiseki[i] << spa;
    //cout << endl;
    rep(q){
        ll x = y[i];
        if(x <= 500) cout << answer[0][x] << endl;
        else if(x - ruiseki[n] > 500) cout << x - ruiseki[n] << endl;
        else{
            int left = -1;
            int right = n; // rightは各自設定
            while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
                int mid = left + (right - left) / 2;
                //if(i == 0) cout << x - ruiseki[mid] << spa << left << spa << right << spa << ruiseki[mid] << endl;
                if(x - ruiseki[mid] >= 1000){ //配列[mid]より比較対象が小さい場合
                    left = mid;
                }else{
                    right = mid;
                }
                if(right < left) break;
            }
            //cout << x << endl;
            //cout << left << spa << ruiseki[left] << spa << right << spa << ruiseki[right] << endl;
            cout << answer[right][x - ruiseki[right]] << endl;
        }
    }
}