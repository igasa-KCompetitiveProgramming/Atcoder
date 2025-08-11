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

void test(int j, vector<bool>& possible, string& s, ll n){
    bitset<18> b(j + 1);
    rep(n){
        if(b[i]) continue;
        int pos = pow(2, i) - 1;
        pos += b.to_ulong();
        if(pos >= s.size()) continue;
        if(s[pos] == '0') possible[pos] = true;
    }
}

int main(){
    LL(t);
    while(t--){
        LL(n);
        string s;
        cin >> s;
        vector<bool> possible(pow(2, n) - 1, false);
        rep(n){
            if(s[pow(2, i) - 1] == '0') possible[pow(2, i) - 1] = true;
        }
        rep(s.size()){
            if(possible[i] == false) continue;
            test(i, possible, s, n);
            //cout << endl;
            //cout << i << endl;
            //rep(j, possible.size()) cout << (possible[j] ? '1' : '0');
            //cout << endl;
        }
        if(possible[possible.size() - 1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}