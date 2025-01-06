#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define v(a,i,b) vector<ll> a(i,b)
#define vv(a,i,j,b) vector<vector<ll>> a(i, vector<ll>(j,b))
#define vp(a,i,b,c) vector<pll>> a(i,{b,c})
#define vvp(a,i,j,b,c) vector<vector<pll>> a(i, vector<>>(j,{b,c}))

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

const vector<ll> dy = {1,-1,0,0};
const vector<ll> dx = {0,0,-1,1};

string s = "UDLR";

int main(){
    LL(n,m,x,y);
    vector<pll> p;
    vector<ll> c(m);
    vector<char> d(n);
    map<ll,set<ll>> setterX, setterY;
    rep(n){
        ll tmp,res;
        cin >> tmp >> res;
        p.push_back({tmp,res});
        setterX[res].insert(tmp);
        setterY[tmp].insert(res);
    }  
    


    rep(m) cin >> d[i] >> c[i];
    ll ans = 0;
    ll nx = x; ll ny = y;
    rep(m){
        rep(j,4){
            if(d[i] == s[j]){
                x = nx; y = ny;
                nx = x + dx[j] * c[i];
                ny = y + dy[j] * c[i];
                //cout << "i " << i << spa << nx << spa << ny << endl;
                //cout << "test" << setterX[1].size() << endl;
                if(j > 1){
                    //cout << ny << spa << min(x,nx) << spa << max(x,nx) << endl;
                    auto l = setterX[ny].lower_bound(min(x,nx));
                    auto r = setterX[ny].upper_bound(max(x,nx));
                    if(l == setterX[ny].end()) continue;
                    if(*l > *r) continue;
                    vector<ll> tmp;
                    for(auto it = l; it != r; it++){
                        tmp.push_back(*it);
                        ans++;
                    }
                    rep(tmp.size()){
                        setterX[ny].erase(tmp[i]);
                        setterY[tmp[i]].erase(ny);
                    }
                }else{
                    auto l = setterY[nx].lower_bound(min(y,ny));
                    auto r = setterY[nx].upper_bound(max(y,ny));
                    //cout << *l << spa << *r << endl;
                    if(l == setterY[nx].end()) continue;
                    if(*l > *r) continue;
                    vector<ll> tmp;
                    for(auto it = l; it != r; it++){
                        tmp.push_back(*it);
                        ans++;
                    }
                    rep(tmp.size()){
                        setterY[nx].erase(tmp[i]);
                        setterX[tmp[i]].erase(nx);
                    }
                }
            }
        }
    }
    cout << nx << spa << ny << spa << ans << endl;
}