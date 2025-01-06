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
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> x(m),y(m);
    vector<char> c(m);
    rep(m) cin >> y[i] >> x[i] >> c[i];
    map<ll,ll> bMap,wMap;
    rep(m){
        if(c[i] == 'B'){
            bMap[x[i]] = -1;
            //wMap[x[i]] = inf;
        }else{
            wMap[x[i]] = inf;
            //bMap[x[i]] = -1;
        }
    }
    rep(m){
        if(c[i] == 'B'){
            bMap[x[i]] = max(bMap[x[i]],y[i]);
        }else{
            wMap[x[i]] = min(wMap[x[i]],y[i]);
        }
    }

    vector<ll> b,w;
    for(auto i : bMap){
        b.pb(i.fi);
    }
    for(auto i : wMap){
        w.pb(i.fi);
    }
    bool ans = true;
    if(b.size() == 0 || w.size() == 0){
        cout << "Yes" << endl;
        return 0;
    }

    /*

    for(auto i : b){
        cout << i << spa;
    }
    cout << endl;
    for(auto i : w){
        cout << i << spa;
    }
    cout << endl;

    */
    rep(m){
        if(c[i] == 'B'){
            int left = -1;
            int right = w.size()-1; // rightは各自設定
            while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
                int mid = left + (right - left) / 2;
                if(w[mid] >= x[i]){ //配列[mid]より比較対象が小さい場合
                    right = mid;
                }else{
                    left = mid;
                }
                if(right < left) break;
            }
            //cout << left << spa << right << endl;
            //if(left != -1) cout << wMap[left] << endl;
            if(left == -1) continue;
            ll minH = inf;
            if(left != -1) minH = min(minH,wMap[left]);
            if(right != w.size()) minH = min(minH,wMap[right]);
            if(wMap[left] <= y[i]){
                ans = false;
            }
            if(minH >= y[i]){
                ans = false;
            }
        }else{
            //cout << x[i] <<spa;
            int left = -1;
            int right = b.size()-1; // rightは各自設定
            while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
                int mid = left + (right - left) / 2;
                if(b[mid] >= x[i]){ //配列[mid]より比較対象が小さい場合
                    right = mid;
                }else{
                    left = mid;
                }
                if(right < left) break;
            }
            //cout << left << spa << right << endl;
            ll maxH = -1;
            if(left != -1) maxH = max(maxH,bMap[left]);
            if(right != b.size()) maxH = max(maxH,bMap[right]);
            if(right == (ll)b.size()) continue;
            //cout << maxH << spa << bMap[right] << spa << y[i] << endl;
            if(bMap[right] <= y[i]){
                ans = false;
            }
            if(maxH <= y[i]){
                ans = false;
            }
        }
        //if(!ans) cout << i << endl;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}