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
    LL(t);
    rep(t){
        LL(h,w);
        string s;
        cin >> s;
        ll ans = h * w;
        pll cnt = {1,1};
        pll max_cnt = {h-1,w-1};

        int max_idx = s.size();

        rep(j,s.size()){
            if(s[j] == 'D') max_cnt.fi--;
            else if(s[j] == 'R') max_cnt.se--;
        }
        rep(j,max_idx){
            if(s[j] == 'D'){
                cnt.fi++;
                ans -= w - cnt.se;
            }else if(s[j] == 'R'){
                cnt.se++;
                ans -= h - cnt.fi;
            }else if(s[j] == '?'){
                if(max_cnt.fi != 0){
                    cnt.fi++;
                    max_cnt.fi--;
                }else{
                    ans -= h - cnt.fi;
                }
                if(max_cnt.se != 0){
                    cnt.se++;
                    max_cnt.se--;
                }else{
                    ans -= w - cnt.se;
                }
            }
        }
        cout << ans << endl;
    }
}