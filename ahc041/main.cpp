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

//vectorのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//dequeのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::deque<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::deque<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//pairのcin,cout
template<typename T,typename U>
std::ostream &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
std::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
//vector<vector<T>>のcout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) {
for (const auto &row : v) {for (auto it = row.begin(); it != row.end(); ++it) { os << *it; if (std::next(it) != row.end()) { os << " "; } } os << "\n";} return os;}

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

ll n,m,h;
vector<pll> a;  
vector<ll> x,y;
vector<ll> u,v;
vector<vector<ll>> g;

void input(){
    cin >> n >> m >> h;
    a.resize(n);
    x.resize(n);
    y.resize(n);
    u.resize(m);
    v.resize(m);
    rep(n) cin >> a[i].fi;
    rep(n) a[i].se = i;
    rep(m) cin >> u[i] >> v[i];
    rep(n) cin >> x[i] >> y[i];
    g.resize(n);
    rep(m){
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
}

int main(){
    int timer = clock();
    input();
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>> pq;

    sort(a.begin(),a.end());

    map<ll,ll> mp;
    rep(n){
        mp[a[i].se] = i + 1;
    }

    ll maxScore = 0;
    vector<ll> maxAns(n,-1);

    //(clock() - timer) / (long double)CLOCKS_PER_SEC < 2.8

    int j = 0;

    while((clock() - timer) / (long double)CLOCKS_PER_SEC < 1.8){
        for(int l = 0;l < 8;l++){
            for(int k = 0;k < 8;k++){
                ll score = 0;
                vector<ll> ans(n,-1);
                vector<bool> used(n,false);
                rep(n){
                    ll now = a[i].se;
                    ll val = a[i].fi;
                    if(used[now]) continue;
                    if(ans[now] != -1) continue;
                    pq.push({1,val,now});
                    ans[now] = -1;
                    score += val;
                    while(!pq.empty()){
                        auto [high,nowVal,pos] = pq.top(); pq.pop();
                        if(used[pos]) continue;
                        used[pos] = true;
                        for(auto to : g[pos]){
                            if(used[to]) continue;
                            if(ans[to] != -1) continue; 
                            if(i < j && (high < l && mp[to] > k*100)) continue;
                            ans[to] = pos;
                            score += a[mp[to]].fi * (high + 1);
                            if(high < 10){
                                pq.push({high+1,val,to});
                            }else{
                                continue;
                            }
                        }
                    }
                }
                if(score > maxScore){
                    maxScore = score;
                    maxAns = ans;
                }
            }
        }
        j++;
    }
    
    //cout << maxScore << endl << endl;

    O(maxAns);
}