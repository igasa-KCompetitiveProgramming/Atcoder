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

class solv{
public:
    ll n,m,l;
    vector<string> s;
    vector<ll> p;

    void input(){
        cin >> n >> m >> l;
        s.resize(n);
        p.resize(n);
        rep(n) cin >> s[i] >> p[i];
    }

    void solve(){
        vector<vector<ll>> ans(m, vector<ll> (m, 0));
        pll maxScore = {-1, -1};
        rep(n){
            if(maxScore.fi < p[i]){
                maxScore.fi = p[i];
                maxScore.se = i;
            }
        }
        rep(s[maxScore.se].size()){
            cout << s[maxScore.se][i] << " ";
            rep(j, m){
                if(i == s[maxScore.se].size() - 1){
                    if(j == 0) cout << 45 << spa;
                    else cout << 5 << spa;
                }else if(j == i + 1) cout << 45 << spa;
                else cout << 5 << spa;
            }
            cout << endl;
        }
        rep(m - s[maxScore.se].size()){
            cout << 'a' << spa << 100 << spa;
            rep(j, m - 1){
                cout << 0 << spa;
            }
            cout << endl;
        }
    }

    void burn(){
        
    }
};

int main(){
    solv s;
    s.input();
    s.solve();
    //s.solve2();
}