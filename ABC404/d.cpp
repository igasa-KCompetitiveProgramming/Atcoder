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
ll inf = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    LL(n,m);
    vector<ll> c(n);
    rep(n) cin >> c[i];
    vector<vector<ll>> animal(n);
    rep(m){
        LL(k);
        rep(j,k){
            LL(a);
            animal[a-1].push_back(i);
        }
    }
    ll cnt = 1;
    rep(2 * n){
        cnt *= 2;
    }
    ll ans = inf;
    rep(cnt){
        vector<bool> used(2 * n, false);
        ll tmp = i;
        ll res = 0;
        while(tmp > 0){
            if(tmp % 2 == 1){
                used[res] = true;
            }
            tmp /= 2;
            res++;
        }
        vector<ll> counter(m,0);
        ll anstmp = 0;
        rep(2 * n){
            //cout << used[i] << spa;
            if(used[i]){
                ll now = i % n;
                anstmp += c[now];
                for(auto x : animal[now]){
                    counter[x]++;
                }
            }
        }
        //cout << endl;
        rep(m){
            if(counter[i] < 2){
                break;
            }
            if(i == m - 1){
                ans = min(ans, anstmp);
            }
        }
    }
    cout << ans << endl;
}