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
    string s;
    for(int i = 0; i < 10; i++){
        string t;
        cin >> t;
        s += t;
    }
    string ans;
    rep(s.size()){
        if(s[i] == 'W') continue;
        else ans += s[i];
    }
    cout << ans.size() << endl;
    rep(ans.size() - 3){
        if(ans[i] == 'X' && ans[i + 3] != 'X') ans[i + 3] = 'E';
    }
    s = ans;
    cout << s.size() << endl;
    ans.clear();
    rep(s.size()){
        if(s[i] == 'Y' && i + 1 < s.size() && s[i + 1] == 'Z') {
            ans += 'E';
            i++;
        } else {
            ans += s[i];
        }
    }
    cout << ans.size() << endl;
    cout << ans.substr(226, 5) << endl; // 227文字目から5文字を出力
}

//W を全て削除する。
//X の 3 つ先の文字が X でない場合は、その(先の方の)文字を E に変える。
//YZ という文字の並びを全て E に変える。
// 227文字目から5文字を答える