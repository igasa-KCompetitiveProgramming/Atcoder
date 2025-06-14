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

int solve(ll n, ll h, ll m, vector<ll>& a, vector<ll>& b);

int main(){
    rep(100){
        ll n = 5;
        vector<ll> a(n), b(n);
        rep(n) {
            a[i] = rand() % 100 + 1; // 1から100のランダムな値
            b[i] = rand() % 100 + 1; // 1から100のランダムな値
        }
        if(solve(n, 100, 100, a, b) == 1){ // hとmは適当に設定
            cout << n << spa << 100 << spa << 100 << endl;
            rep(n) {
                cout << a[i] << spa << b[i] << endl;
            }
            break;
        }
    }
}

int solve(ll n, ll h, ll m, vector<ll>& a, vector<ll>& b) {
    int left = -1;
    int right = n + 1; // rightは各自設定
    while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
        int mid = left + (right - left) / 2;
        bool flag = false;
        ll Asum = 0;
        rep(i, mid){
            Asum += a[i];
        }
        //cout << "mid: " << mid << spa << "Asum: " << Asum << endl;
        if(Asum <= h) flag = true;
        else{
            vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
            dp[0][0] = 0; // 初期化
            rep(i, mid){
                for(int j = m; j >= 0; j--){
                    if(dp[i][j] == -1) continue;
                    if(j + b[i] <= m){
                        dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j] + a[i]);
                    }
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                }
            }
            //cout << "mid: " << mid << spa << "dp[mid][m]: " << dp[mid][m] << endl;
            if(Asum - dp[mid][m] <= h){ // dp[mid][m]は配列[mid]までの要素で、m時間以内にできる最大の値
                flag = true; // 配列[mid]まででh時間を超える場合
            }
        }
        if(!flag){ //配列[mid]より比較対象が小さい場合
            right = mid;
        }else{
            left = mid;
        }
        if(right < left) break;
    }
    ll ans = left;
    left = -1;
    right = n + 1; // rightは各自設定
    while(right - left > 1){
        int mid = left + (right - left) / 2;
        bool flag = false;
        ll Bsum = 0;
        rep(i, mid){
            Bsum += b[i];
        }
        //cout << "mid: " << mid << spa << "Bsum: " << Bsum << endl;
        if(Bsum <= m) flag = true;
        else{
            vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, -1));
            dp[0][0] = 0; // 初期化
            rep(i, mid){
                for(int j = h; j >= 0; j--){
                    if(dp[i][j] == -1) continue;
                    if(j + a[i] <= h){
                        dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + b[i]);
                    }
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                }
            }
            //cout << "mid: " << mid << spa << "dp[mid][h]: " << dp[mid][h] << endl;
            if(Bsum - dp[mid][h] <= m){ // dp[mid][h]は配列[mid]までの要素で、h時間以内にできる最大の値
                flag = true; // 配列[mid]まででm時間を超える場合
            }
        }
        if(!flag){ //配列[mid]より比較対象が小さい場合
            right = mid;
        }else{
            left = mid;
        }
        if(right < left) break;
    }
    ll ans2 = left;
    if(ans < ans2){
        return 1;
    }
    return 2;
}