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
    LL(t);
    rep(t){
        LL(n);
        vector<int> a(2*n);
        rep(2*n) cin >> a[i];
        rep(2*n) a[i]--;
        map<pint,int> mp;
        vector<pair<pint,pint>> b(n, {{-1,-1},{-1,-1}});
        vector<vector<int>> g(4, vector<int>(n, -1));
        vector<bool> flag(n, true);
        vector<bool> cons(n, false);
        rep(2*n){
            int l = i - 1;
            int r = i + 1;
            if(l >= 0){
                if(flag[a[i]]){
                    b[a[i]].fi.fi = a[l];
                    g[0][a[i]] = l;
                }else{
                    b[a[i]].se.fi = a[l];
                    g[2][a[i]] = l;
                }
            }
            if(r < 2*n){
                if(flag[a[i]]){
                    b[a[i]].fi.se = a[r];
                    g[1][a[i]] = r;
                }else{
                    b[a[i]].se.se = a[r];
                    g[3][a[i]] = r;
                }
            }
            flag[a[i]] = false;
        }
        rep(2*n - 1){
            if(a[i] == a[i+1]){
                cons[a[i]] = true;
            }
        }
        rep(n){
            ll w = b[i].fi.fi;
            ll x = b[i].fi.se;
            ll y = b[i].se.fi;
            ll z = b[i].se.se;
            //cout << i << spa << w << spa << x << spa << y << spa << z << endl;
            if(w == y){
                if(g[0][i] == g[2][i]) continue;
                if(w == -1) continue;
                if(cons[w] || cons[i]) continue;
                int mini = min(w, i);
                int maxi = max(w, i);
                mp[{mini,maxi}]++;
            }
            if(w == z){
                if(g[0][i] == g[3][i]) continue;
                if(w == -1) continue;
                if(cons[w] || cons[i]) continue;
                int mini = min(w, i);
                int maxi = max(w, i);
                mp[{mini,maxi}]++;
            }
            if(x == y){
                if(g[1][i] == g[2][i]) continue;
                if(x == -1) continue;
                if(cons[x] || cons[i]) continue;
                int mini = min(x, i);
                int maxi = max(x, i);
                mp[{mini,maxi}]++;
            }
            if(x == z){
                if(g[1][i] == g[3][i]) continue;
                if(x == -1) continue;
                if(cons[x] || cons[i]) continue;
                int mini = min(x, i);
                int maxi = max(x, i);
                mp[{mini,maxi}]++;
            }
        }
        cout << mp.size() << endl;
    }
}