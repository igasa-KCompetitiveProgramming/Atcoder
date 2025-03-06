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

template <typename T>
class SegmentTree {
  public:
    function<T(T, T)> op; // T op(T a, T b)とほぼ同じ
    T e; // 単位元
    int size;
    vector<T> data;

    SegmentTree(T n, function<T(T,T)> op, T e) : op(op), e(e){ // セグ木の初期化
        size = 1;
        while(size < n) size <<= 1;
        data = vector<T>(2*size, e);
    }

    void set(int i, T val){ // 値の更新
        i += size;
        data[i] = val;
        while(i > 1){
            i >>= 1;
            data[i] = op(data[i*2], data[i*2+1]);
        }
    }

    T query(int l, int r){ // 区間(l,r)のクエリ
        l += size; r += size;
        T l_val = e, r_val = e;
        while(l < r){
            if(l & 1) l_val = op(l_val, data[l++]);
            if(r & 1) r_val = op(data[--r], r_val);
            l >>= 1; r >>= 1;
        }
        return op(l_val, r_val);
    }

    T find_idx(int idx){
        return find_idx_sub(idx, 1, 0, size);
    }

    T find_idx_sub(int idx, int k, int l, int r){
        if(data[k] == 0) return -1;
        if(k >= size){
            return k - size;
        }else{
            if(idx <= data[k*2+1]){
                return find_idx_sub(idx, k*2+1, l, (l+r)/2);
            }else{
                return find_idx_sub(idx - data[k*2+1], k*2, (l+r)/2, r);
            }
        }
    }
}; // 初期化はSegmentTree<T> seg(n, [](T a, T b){return a+b;}, 0);のようにする

int main(){
    LL(n);
    vector<ll> a(n);
    rep(n) cin >> a[i];
    SegmentTree<ll> seg(n, [](ll a, ll b){return a+b;}, 0ll);
    rep(n) seg.set(i, 1);
    vector<ll> ans(n);
    rrep(n){
        int idx = seg.find_idx(a[i]);
        cout << idx << endl;
        ans[idx] = i;
        seg.set(idx, 0);
    }
    rrep(n) cout << ans[i] + 1 << spa;
}