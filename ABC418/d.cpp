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

ll Pow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll act1(string &s){
    ll ans = 0;
    ll cnt = 0;
    rep(s.size()){
        
    }
}

ll act(vector<pll> &t){
    ll ans = 0;
    ll res = 0;
    ll cnt = 0;
    ll now = 0;
    rep(t.size()){
        cout << now << " " << res << " " << cnt << spa << t[i].fi << spa << t[i].se << endl;
        now += t[i].se;
        if(res == 0 && cnt == 0 && t[i].fi == 1){
            res = t[i].se;
            continue;
        }else if(t[i].fi == 0){
            cnt += t[i].se;
            ll tmp = cnt / 2;
            cnt %= 2;
            if(res == 0 && tmp != 0) res = Pow(2, tmp - 1);
            else if(tmp != 0) res *= Pow(2, tmp);
        }else if(t[i].fi == 1){
            if(cnt % 2 == 0) res *= Pow(2, t[i].se);
        }
    }
    return res;
}

int main(){
    LL(n);
    string s;
    cin >> s;
    vector<pll> t;
    pint prev = {-1, -1};
    rep(n){
        if(prev.fi == -1){
            prev.fi = s[i] - '0';
            prev.se = 1;
        }else if(prev.fi == s[i] - '0'){
            prev.se++;
        }else{
            t.pb({prev.fi, prev.se});
            prev.fi = s[i] - '0';
            prev.se = 1;
        }
    }
    t.pb(prev);
    rep(t.size()) cout << t[i].fi << " " << t[i].se << endl;
    ll res = act(t);

    cout << res << endl;
}