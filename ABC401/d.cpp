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
int main(){
    LL(n,k);
    string s;
    cin >> s;
    rep(n){
        if(s[i] == 'o'){
            k--;
            if(i != 0) s[i-1] = '.';
            if(i != n-1) s[i+1] = '.';
        }
    }
    string ans = s;
    int cnt = 0;
    int tmp = -1;
    rep(n){
        if(s[i] == '?'){
            if(tmp != -1) continue;
            tmp = i;
        }else{
            if(tmp != -1){
                if((i - tmp) % 2 == 1){
                    for(int j = tmp; j < i; j++){
                        if((j - tmp) % 2 == 0){
                            ans[j] = 'o';
                        }else{
                            ans[j] = '.';
                        }
                    }
                }

                cnt += (i - tmp + 1)/2;
                tmp = -1;
            }
        }
    }

    if(tmp != -1){
        if((n - tmp) % 2 == 1){
            for(int j = tmp; j < n; j++){
                if((j - tmp) % 2 == 0){
                    ans[j] = 'o';
                }else{
                    ans[j] = '.';
                }
            }
        }

        cnt += (n - tmp + 1)/2;
        tmp = -1;
    }

    //cout << s << endl;
    //cout << ans << endl;

    if(k == 0){
        rep(n){
            if(s[i] == '?') cout << '.';
            else cout << s[i];
        }
    }else if(k - cnt < 0){
        cout << s;
    }else{
        cout << ans;
    }
}