#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define v(a,i,b) vector<ll> a(i,b)
#define vv(a,i,j) vector<vector<ll>> a(i, vector<ll>(j))
#define vp(a,i,b,c) vector<pll>> a(i,{b,c})
#define vvp(a,i,j) vector<vector<pll>> a(i, vector<>>(j))

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

ll h = 100000,w = 100000;

map<ll,vector<ll>> sbsc;
map<ll,vector<ll>> iwsc;

ll score(ll ax, ll ay, ll bx, ll by){
    ll ret = 0;
    for(auto x:sbsc){
        if(x.fi < ax && x.fi > bx){
            continue;
        }
        ll ans = 0;
        int left = -1;
        int right = x.se.size(); // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            int mid = left + (right - left) / 2;
            if(x.se[mid] >= ax){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }

        ans = left;

        left = -1;
        right = x.se.size(); // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            int mid = left + (right - left) / 2;
            if(x.se[mid] >= bx){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }

        ret += left - ans;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    pll maxP = {0,0};
    pll minP = {INF,INF};
    v(ax,n,0);v(ay,n,0);
    v(bx,n,0);v(by,n,0);
    v(sbX,h,0);v(sbY,w,0);
    v(iwX,h,0);v(iwY,w,0);
    rep(n){
        cin >> ax[i] >> ay[i];
        sbX[ax[i]]++;sbY[ay[i]]++;
        maxP.fi = max(maxP.fi, ax[i]);
        maxP.se = max(maxP.se, ay[i]);
        minP.fi = min(minP.fi, ax[i]);
        minP.se = min(minP.se, ay[i]);
        sbsc[ax[i]].pb(ay[i]);
    }
    rep(n){
        cin >> bx[i] >> by[i];
        iwX[bx[i]]++;iwY[by[i]]++;
        iwsc[bx[i]].pb(by[i]);
    }


    //O(sbX);
    //O(sbY);

    int param = 1000;
    rep(i,minP.se,maxP.se,param){
        ll sbcnt = 0,iwcnt = 0;
        rep(j,minP.se,minP.se+param){
            sbcnt += sbY[j];
            iwcnt += iwY[j];
        }
        if(sbcnt < iwcnt){
            minP.se = i;
        }else{
            break;
        }
    }

    rep(i,minP.fi,maxP.fi,param){
        ll sbcnt = 0,iwcnt = 0;
        rep(j,minP.fi,minP.fi+param){
            sbcnt += sbX[j];
            iwcnt += iwX[j];
        }
        if(sbcnt < iwcnt){
            minP.fi = i;
        }else{
            break;
        }
    }

    rrep(i,maxP.se,minP.se,param){
        ll sbcnt = 0,iwcnt = 0;
        rep(j,minP.se,minP.se+param){
            sbcnt += sbY[j];
            iwcnt += iwY[j];
        }
        if(sbcnt < iwcnt){
            maxP.se = i;
        }else{
            break;
        }
    }

    rrep(i,maxP.fi,minP.fi,param){
        ll sbcnt = 0,iwcnt = 0;
        rep(j,minP.fi,minP.fi+param){
            sbcnt += sbX[j];
            iwcnt += iwX[j];
        }
        if(sbcnt < iwcnt){
            maxP.fi = i;
        }else{
            break;
        }
    }

    cout << 4 << endl;
    cout << minP.fi << spa << minP.se << endl;
    cout << maxP.fi << spa << minP.se << endl;
    cout << maxP.fi << spa << maxP.se << endl;
    cout << minP.fi << spa << maxP.se << endl;
}