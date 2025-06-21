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

string final_ans = "";

void answer(string tmp, vector<vector<string>> &word){
    cout << tmp << endl;
    rep(i, tmp.size()){
        if(tmp[i] == '-'){
            int pcNum = -1;
            pint pos = {-1, -1};
            string res = "";
            rep(j,3){
                while(true){
                    i++;
                    if(tmp[i] == ','){
                        break;
                    }else{
                        res += tmp[i];
                    }
                }
                if(j == 0) pcNum = stoi(res);
                else if(j == 1) pos.fi = stoi(res);
                else if(j == 2) pos.se = stoi(res);
                res = "";
            }
            string next = "";
            for(int j = pos.fi; j <= pos.se; j++){
                next += word[pcNum][j];
            }
            answer(next, word);
        }else{
            final_ans += tmp[i];
        }
    }
}

int main(){
    LL(n,q);
    vector<vector<string>> word(n);
    vector<vector<string>> pc(n);
    vector<int> len(n, 0);
    pair<ll, pll> server = {-1, {-1, -1}};
    ll counter = 0;
    rep(q){
        LL(type);
        if(type == 1){
            LL(x);
            x--;
            pc[x].clear();
            if(server.fi != -1){
                string tmp = "";
                tmp += '-' + to_string(server.fi) + ',' + to_string(server.se.fi) + ',' + to_string(server.se.se) + ',';
                pc[x].pb(tmp);
                len[x] = word[x].size();
                word[x].pb(pc[x].back());
            }
        }else if(type == 2){
            LL(x);
            x--;
            string tmp;
            cin >> tmp;
            pc[x].pb(tmp);
            word[x].pb(tmp);
        }else{
            LL(x);
            x--;
            server.fi = x;
            server.se.fi = len[x];
            server.se.se = len[x] + pc[x].size() - 1;
        }
    }
    string ans = "";
    if(server.fi == -1){
        return 0;
    }else{
        for(int j = server.se.fi; j <= server.se.se; j++){
            ans += word[server.fi][j];
        }
    }

    rep(n){
        rep(j,word[i].size()){
            cout << word[i][j] << spa;
        }
        cout << endl;
    }

    cout << endl;
    
    answer(ans, word);
    cout << final_ans << endl;
}