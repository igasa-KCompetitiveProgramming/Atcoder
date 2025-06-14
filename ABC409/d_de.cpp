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
string solve(ll n, string s){
    string ans = "";
    bool flag = true;
    bool found = false;
    char cnt = 0;
    rep(n - 1){
        if(found){
            cout << s[i];
            ans += s[i];
            continue;
        }
        if(flag){
            if(s[i] - s[i + 1] > 0){
                flag = false;
                cnt = s[i];
                continue;
            }else{
                cout << s[i];
                ans += s[i];
            }
        }else{
            if(cnt < s[i]){
                found = true;
                cout << cnt << s[i];
                ans += cnt;
                ans += s[i];
            }else{
                cout << s[i];
                ans += s[i];
            }
        }
    }
    //cout << flag << spa << found << endl;
    if(!flag && !found){
        if(s[n - 1] > cnt){
            cout << cnt << s[n - 1];
            ans += cnt;
            ans += s[n - 1];
        }else{
            cout << s[n - 1] << cnt;
            ans += s[n - 1];
            ans += cnt;
        }
    }else{
        cout << s[n - 1];
        ans += s[n - 1];
    }
    cout << endl;
    return ans;
}

string cyclingShift(string s, int i, int j){
    // iからjまでの文字列を1回だけ左にシフト
    string shifted;
    char tmp;
    rep(k,s.size()){
        if(k == i){
            tmp = s[k];
        }else if(k == j){
            shifted += s[k];
            shifted += tmp;
        }else{
            shifted += s[k];
        }
    }
    if(j == s.size()) shifted += tmp; // jが文字列の最後ならば、tmpを追加
    return shifted;
}

string solve_jury(ll n, string s){
    string ans = s;
    rep(n - 1){
        for(int j = i + 1; j <= n; j++){
            string shifted = cyclingShift(s, i, j);
            if(shifted < ans){
                ans = shifted;
            }
        }
    }
    return ans;
}

int main(){
    LL(t);
    rep(t){
        ll n = 4;
        string s;
        rep(n){
            char c;
            c = 'a';
            c = (char)('a' + rand() % 26);
            s += c;
        }
        cout << "Input: " << s << endl;
        string ans = solve(n, s);
        string jury_ans = solve_jury(n, s);
        if(ans != jury_ans){
            cout << "WA" << endl;
            cout << s << endl;
            cout << ans << endl;
            cout << jury_ans << endl;
            break;
        }
    }
}