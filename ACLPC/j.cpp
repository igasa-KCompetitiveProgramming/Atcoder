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

    T find_rightest(int l, int r, T x){ // 区間(l,r)のうち、xを満たす最左の位置を返す
        return find_rightest_sub(l, r, x, 1, 0, size);
    }

    T find_rightest_sub(int a, int b, T x, int k, int l, int r){ // find_leftestのサブルーチン
        //cout << x << " " << k << " " << l << " " << r << spa << data[k] << endl;
        if(data[k] < x || r <= a || b <= l) return a - 1;
        if(k >= size){
            return k - (size - 1);
        }else{
            T res = find_rightest_sub(a, b, x, k*2, l, (l+r)/2);
            if(res != a-1){
                return res;
            }
            return find_rightest_sub(a, b, x, k*2+1, (l+r)/2, r);
        }
    }
}; // 初期化はSegmentTree<T> seg(n, [](T a, T b){return a+b;}, 0);のようにする

int main(){
    LL(n,q);
    vector<ll> a(n);
    SegmentTree<ll> seg(n, [](ll a, ll b){return max(a,b);}, 0);
    rep(n){
        cin >> a[i];
        seg.set(i, a[i]);
    }
    int cnt = 1;
    
    rep(q){
        LL(type);
        if(type == 1){
            LL(x, v);
            x--;
            seg.set(x, v);
        }else if(type == 2){
            LL(l, r);
            l--; r--;
            O(seg.query(l, r+1));
        }else{
            LL(x, v);
            x--;
            int ans = seg.find_rightest(x, n, v);
            if(ans == x-1) O(n+1);
            else O(ans);
        }
    }
}