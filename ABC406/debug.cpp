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


int solve(ll n, vector<ll> a){
    ll l = 0,range = 0;
    ll ans = 0;
    ll up = -1,down = -1;
    bool flag = false;
    for(int i = 1; i < n - 1; i++){
        if(a[i - 1] < a[i] && a[i] > a[i + 1]){
            if(up == -1){
                up = i;
                if(down != -1){
                    range = down - l;
                }
            }else{
                if(flag){
                    ans += range;
                    flag = false;
                }
                if(up < down){
                    range = down - up;
                    up = i;
                    flag = true;
                }else{
                    range = -1;
                    l = down;
                    down = -1;
                }
            }
        }else if(a[i - 1] > a[i] && a[i] < a[i + 1]){
            if(down == -1){
                down = i;
                if(up != -1){
                    range = up - l;
                }
            }else{
                if(flag){
                    ans += range;
                    flag = false;
                }
                if(down < up){
                    range = up - down;
                    down = i;
                    flag = true;
                }else{
                    range = -1;
                    l = up;
                    up = -1;
                }
            }
        }
        if(up != -1 && down != -1){
            ans += range;
            flag = false;
        }
    }
    if(flag){
        ans += range;
        flag = false;
    }
    return ans;
}

int solve_jury(ll n, vector<ll> a){
    ll ans = 0;
    rep(n){
        rep(j,n){
            if(i >= j) continue;
            pint p = {0,0};
            for(int k = i + 1; k < j; k++){
                if(a[k-1] > a[k] && a[k] < a[k+1]){
                    p.fi++;
                }
                if(a[k-1] < a[k] && a[k] > a[k+1]){
                    p.se++;
                }
            }
            if(p.fi == 1 && p.se == 1){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    LL(n);
    vector<ll> a(n);
    rep(n) a[i] = i;
    while(next_permutation(a.begin(), a.end())){
        if(solve(n, a) != solve_jury(n, a)){
            rep(n) cout << a[i] << spa;
            cout << endl << endl;
            cout << solve(n, a) << endl;
            cout << solve_jury(n, a) << endl;
            return 0;
        }
    }
}