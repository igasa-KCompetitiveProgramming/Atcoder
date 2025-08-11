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

ll final_ans = 0;
ll r;
ll maximum = 0;

string erase_zero(string& s){
    string res = "";
    bool flag = false;
    for(int i = 0; i < s.size(); i++){
        if(!flag && s[i] == '0') continue;
        flag = true;
        res += s[i];
    }
    return res;
}

ll my_stoi(string& s){
    string temp = erase_zero(s);
    ll result = 0;
    for(int i = 0; i < temp.size(); i++){
        result *= 10;
        result += temp[i] - '0';
    }
    return result;
}

bool n_sinka(ll n, ll r){
    string res = "";
    ll m = n;
    ll perm = r;
    while(n > 0){
        ll tmp = n % perm;
        n /= perm;
        res += to_string(tmp);
    }
    string rev_res = res;
    reverse(rev_res.begin(), rev_res.end());
    if(res == rev_res) return true;
    else return false;
}

bool check(string& s){
    ll num = my_stoi(s);
    if(num > maximum) return false;
    s = to_string(num);
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    if(s != rev_s) return false;
    if(n_sinka(num, r)){
        final_ans += num;
        return true;
    }
    return false;
}

string kaibunka_even(string s, int n){
    string res = s;
    string ans = s;
    reverse(res.begin(), res.end());
    ans += to_string(n);
    ans += res;
    return ans;
}

string kaibunka_odd(string s){
    string res = s;
    string ans = s;
    reverse(res.begin(), res.end());
    ans += res;
    return ans;
}

void saik(int n, string& s){
    if(n == 0){
        string res = kaibunka_odd(s);
        check(res);
        return;
    }else if(n == 1){
        for(int i = 0; i < 10; i++){
            string res = kaibunka_even(s, i);
            check(res);
        }   
    }else{
        for(int i = 0; i < 10; i++){
            if(s.size() == 0 && i == 0) continue; // 先頭に0はつけない
            s += to_string(i);
            saik(n - 2, s);
            s.pop_back();
        }
    }
}

int main(){
    auto start = chrono::system_clock::now();
    LL(a,n);
    maximum = n;
    r = a;
    rep(i,1,13){
        string s = "";
        saik(i, s);
    }
    cout << final_ans << endl;
}