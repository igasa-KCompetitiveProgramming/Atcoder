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

bool second(ll n, vector<ll> &a){
    long double r = (long double)a[1] / (long double)a[0];
    vector<ll> ans;
    ans.pb(a[0]);
    rep(i, 1, n){
        long double tmp = a[i - 1];
        tmp *= r;
        ans.pb(round(tmp));
    }
    rep(n){
        if(a[i] != ans[i]){
            return false;
        }
    }
    return true;
}

bool first(ll n, vector<ll> &a){
    if(second(n, a)){
        return true;
    }
    reverse(a.begin(), a.end());
    if(second(n, a)){
        return true;
    }
    return false;
}

int main(){
    LL(t);
    rep(timer, t){
        LL(n);
        vector<ll> a(n);
        rep(n) cin >> a[i];
        bool check = true;
        rep(n - 1){
            if(a[i] != a[i + 1]){
                check = false;
                break;
            }
        }
        if(check){
            cout << "Yes" << endl;
            continue;
        }
        vector<pll> sorted(n);
        rep(n) sorted[i] = {abs(a[i]), i};
        sort(sorted.begin(), sorted.end());
        rep(n){
            if(a[sorted[i].se] < 0) sorted[i].fi *= -1;
        }
        rep(n) a[i] = sorted[i].fi;
        bool code1;
        bool code2;
        bool check1 = true;
        bool check2 = true;
        if(a[0] > 0) code1 = code2 = true;
        else code1 = code2 = false;
        rep(n){
            if(!code1 && a[i] > 0) check1 = false;
            if(code1 && a[i] < 0) check1 = false;
            if(code2 && a[i] > 0) code2 = false;
            else if(!code2 && a[i] < 0) code2 = true;
            else check2 = false;
        }
        if(!check1 && !check2){
            cout << "No" << endl;
            continue;
        }else{
            rep(n) a[i] = abs(a[i]);
            if(first(n, a)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}