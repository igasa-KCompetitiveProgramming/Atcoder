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

const vector<ll> di = {0, 1, 0, -1};
const vector<ll> dj = {1, 0, -1, 0};

bool check(vector<string> &f, pint h, pint w){
    rep(f.size()){
        if(h.fi >= i || h.se <= i) continue;
        rep(j, f[i].size()){
            if(w.fi >= j || w.se <= j) continue;
            if(f[i][j] == '#') return false;
        }
    }
    return true;
}

bool www(vector<string> &f, pint a, pint b, ll ni, ll nj, int h, int w){
    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
        if(a.fi >= ni || a.se <= ni) return true;
        if(b.fi >= nj || b.se <= nj) return true;
        if(f[ni][nj] == '#') return false;
    }
    return true;
}

int main(){
    LL(h,w);
    vector<string> s(h);
    pint firs;
    pint maxh = {-1, h}; pint maxw = {-1, w};
    rep(h){
        cin >> s[i];
        rep(j, s[i].size()){
            if(s[i][j] == 'T') firs = {i, j};
        }
    }
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<tuple<int, pint, pint, pint>> p;
    p.push({0, firs, maxh, maxw});
    while(!p.empty()){
        auto[ans, now, a, b] = p.top(); p.pop();
        auto[ti, tj] = now;
        if(check(s, a, b)){
            cout << ans << endl;
            return 0;
        }
        //cout << ti << spa << tj << endl;
        if(ti >= 0 && ti < h && tj >= 0 && tj < w){
            //cout << "here" << endl;
            if(used[ti][tj]) continue;
            used[ti][tj] = true;
        }
        rep(4){
            int ni = ti + di[i];
            int nj = tj + dj[i];
            if(www(s, a, b, ni, nj, h, w)) continue;
            a.fi = max(a.fi, a.fi + now.fi - firs.fi);
            a.se = min(a.se, a.se + now.fi - firs.fi);
            b.fi = max(b.fi, b.fi + now.se - firs.se);
            b.se = min(b.se, b.se + now.se - firs.se);
            p.push({ans + 1, {ni, nj}, a, b});
        }
    }
    cout << -1 << endl;
}