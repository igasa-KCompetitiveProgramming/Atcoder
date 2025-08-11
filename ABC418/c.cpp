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
int main(){
    LL(n,q);
    vector<ll> a(n), b(q);
    rep(n) cin >> a[i];
    rep(q) cin >> b[i];
    sort(a.begin(), a.end());

    vector<ll> ruiseki(n + 1);
    ruiseki[0] = 0;
    rep(n) ruiseki[i + 1] = ruiseki[i] + a[i];
    cout << endl;
    rep(q){
        if(b[i] == 1){
            cout << 1 << endl;
            continue;
        }
        int left = -1;
        int right = n; // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            int mid = left + (right - left) / 2;
            if(a[mid] >= b[i]){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        //cout << left << spa << right << endl;
        if(right == n) cout << -1 << endl;
        else if(left == -1){
            cout << n * (b[i] - 1) + 1 << endl;
        }else{
            cout << ruiseki[right] + (n - right) * (b[i] - 1) + 1 << endl;
        }
    }
}