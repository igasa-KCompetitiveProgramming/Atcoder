#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
#include <iostream>
using namespace std;

namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

using pint = pair<int,int>;
using pBint = pair<long long, long long>;

#define rrep1(a)          for(int i = (int)(a-1); i >= (int)0 ; i--)
#define rrep2(i, a)       for(int i = (int)(a-1); i >= (int)0; i--)
#define rrep3(i, a, b)    for(int i = (int)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(int i = (int)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(int i = 0; i < (int)(a); i++)
#define rep2(i, a)       for(int i = 0; i < (int)(a); i++)
#define rep3(i, a, b)    for(int i = (a); i < (int)(b); i++)
#define rep4(i, a, b, c) for(int i = (a); i < (int)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) Bint __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

//int INF = 2147483647; // おおよそ2*10^9
Bint inf = 1LL<<60; //おおよそ10^18
//uBint UINF == おおよそ1.8*10^19

int main(){
    LL(t,m);
    vector<Bint> ruiseki(5000, 1);
    rep(5000){
        ruiseki[i + 1] = ruiseki[i] * (i + 1);
    }
    rep(timer, t){
        int n;
        cin >> n;
        vector<int> c(n);
        int sum = 0;
        rep(n){
            cin >> c[i];
            sum += c[i];
        }
        Bint ans = ruiseki[sum];
        rep(n){
            ans /= ruiseki[c[i]];
        }
        cout << ans % m << endl;
    }
}