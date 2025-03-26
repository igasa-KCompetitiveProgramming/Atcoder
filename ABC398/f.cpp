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

std::vector<int> manacher(const std::string& S) {
    std::vector<char> C;
    for (char a : S) {
        C.push_back(a);
        C.push_back(0);  // ダミー文字の挿入
    }
    C.pop_back();  // 最後の0を削除

    int L = C.size();
    std::vector<int> R(L, 0);  // 回文長を保持する配列

    int i = 0, j = 0;
    while (i < L) {
        // 奇数長の回文の拡張
        while (j <= i && i + j < L && C[i - j] == C[i + j]) {
            j++;
        }
        R[i] = j;

        // 偶数長の回文の拡張
        int k = 1;
        while (j - R[i - k] > k && i + k < L) {
            R[i + k] = R[i - k];
            k++;
        }
        i += k;
        j -= k;
    }

    // 実際の回文長を調整
    for (int i = 0; i < L; ++i) {
        if (i % 2 == R[i] % 2) {
            R[i]--;
        }
    }

    return R;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> result = manacher(s);

    int cnt = 0;
    // 結果の表示（デバッグ用）
    int i = 0;
    int idx = -1;
    bool flag = false;
    for (int r : result) {
        if(i % 2 == 1){
            //cout << s[idx] << spa << idx << spa << r/2 << spa << r << endl;
            if(idx + r/2 + 1 == s.size()){
                cnt = idx - r/2;
                flag = true;
                break;
            }
        }else{
            idx++;
            //cout << s[idx] << spa << idx << spa << r/2 << endl;
            if(idx + r/2 == s.size() - 1){
                cnt = idx - 1 - r/2;
                break;
            }
        }
        i++;
    }
    //cout << cnt << endl;
    cout << s;
    for(int i = cnt; i >= 0; i--){
        cout << s[i];
    }

    return 0;
}