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

int cheker(vector<bool>& flag, ll x, ll& ans){
    int cnt = 0;
    for(int j = -1; j <= 1; j++){
        if(j == 0) continue; // 自分自身はカウントしない
        if(x + j < 0 || x + j >= flag.size()) continue;
        if(flag[x + j]) cnt++;
    }
    return cnt;
}

int main(){
    LL(n,q);
    vector<ll> a(q);
    rep(q) cin >> a[i];
    vector<bool> flag(n, false);
    ll ans = 0;
    rep(q){
        ll x = a[i] - 1;
        if(flag[x]){
            int cnt = cheker(flag, x, ans);
            if(cnt == 0) ans--;
            else if(cnt == 2) ans++;
            flag[x] = false;

        }else{
            int cnt = cheker(flag, x, ans);
            if(cnt == 0) ans++;
            else if(cnt == 2) ans--;
            flag[x] = true;

        }
        cout << ans << endl;
    }
}