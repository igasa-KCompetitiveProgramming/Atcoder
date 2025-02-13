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


vector<vector<string>> t;

char check(string s){
    ll cnt = 0;
    rep(s.size()){
        if(s[i] == '1') cnt++;
    }
    if(cnt > 1) return '1';
    else return '0';
}

void setup(ll k, vector<vector<string>>& t){
    ll tmp = t[k].size();
    if(tmp == 1){
        return;
    }
    rep(tmp/3){
        ll res = i * 3;
        string s;
        rep(j, 3){
            s += check(t[k][res+j]);
        }
        t[k+1].pb(s);
    }
    setup(k+1, t);
}

int main(){
    LL(n);
    string s;
    cin >> s;
    t.resize(n);
    ll N = s.size();
    rep(N/3){
        ll tmp = i * 3;
        string res = s.substr(tmp, 3);
        t[0].pb(res);
    }
    setup(0, t);
    char tmp = check(t[n-1][0]);

    vector<vector<ll>> ans(n);
    ans[0].resize(t[0].size());
    rep(i, t[0].size()){
        rep(j,3){
            if(t[0][i][j] == tmp){
                ans[0][i]++;
            }
        }
        ans[0][i] = max(ans[0][i]-1,0ll);
    }

    rep(i, 1, n){
        ans[i].resize(t[i].size());
        rep(j, (ans[i-1].size())/3){
            vector<int> vtmp(3);
            rep(k, 3){
                vtmp[k] = ans[i-1][j*3+k];
            }
            sort(vtmp.begin(), vtmp.end());
            rep(k,2){
                ans[i][j] += vtmp[k];
            }
        }
    }
    cout << ans[n-1][0] << endl;
}