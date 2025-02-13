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

void move(char d, int p, vector<string>& c) {
    int n = c.size();
    string t(n, '.');
    if (d == 'L') {
        rep(i, n - 1) t[i] = c[p][i + 1];
        c[p] = t;
    } else if (d == 'R') {
        rep(i, n - 1) t[i + 1] = c[p][i];
        c[p] = t;
    } else if (d == 'U') {
        rep(i, n - 1) t[i] = c[i + 1][p];
        rep(i, n) c[i][p] = t[i];
    } else if (d == 'D') {
        rep(i, n - 1) t[i + 1] = c[i][p];
        rep(i, n) c[i][p] = t[i];
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> c(n);
    rep(i, n) cin >> c[i];

    vector<pair<char, int>> operations;  // 操作を保存
    vector<pair<int,int>> demons;

    rep(i, n) rep(j, n) {
        if (c[i][j] == 'x') {
            demons.emplace_back(i, j);
        }
    }

    auto timer = clock();

    while(clock() - timer < 1.6 * CLOCKS_PER_SEC && !demons.empty()) { 
        int i = demons[0].first;
        int j = demons[0].second;

        bool can_move_up = true, can_move_down = true;
        bool can_move_left = true, can_move_right = true;

        // 上方向チェック
        for (int k = 0; k < i; k++) {
            if (c[k][j] == 'o') can_move_up = false;
        }
        // 下方向チェック
        for (int k = i + 1; k < n; k++) {
            if (c[k][j] == 'o') can_move_down = false;
        }
        // 左方向チェック
        for (int k = 0; k < j; k++) {
            if (c[i][k] == 'o') can_move_left = false;
        }
        // 右方向チェック
        for (int k = j + 1; k < n; k++) {
            if (c[i][k] == 'o') can_move_right = false;
        }

        // 各方向の移動回数を計算
        int up_count = can_move_up ? i : n; // 上に移動できる場合の回数
        int down_count = can_move_down ? (n - i - 1) : n; // 下に移動できる場合の回数
        int left_count = can_move_left ? j : n; // 左に移動できる場合の回数
        int right_count = can_move_right ? (n - j - 1) : n; // 右に移動できる場合の回数

        up_count++;
        down_count++;
        left_count++;
        right_count++;

        // 移動回数が少ない順に優先して消去
        if (up_count <= down_count && up_count <= left_count && up_count <= right_count && can_move_up) {
            rep(k,15){
                if(c[k][j] == 'o') break;
                if(c[k][j] == 'x') up_count = k + 1;
            }
            rep(k, up_count) operations.emplace_back('U', j);
            rep(k, up_count) operations.emplace_back('D', j);
            rep(k, up_count) move('U', j, c);
            rep(k, up_count) move('D', j, c);
        } else if (down_count <= up_count && down_count <= left_count && down_count <= right_count && can_move_down) {
            rep(k,15){
                if(c[n-k-1][j] == 'o') break;
                if(c[n-k-1][j] == 'x') down_count = k + 1;
            }
            rep(k, down_count) operations.emplace_back('D', j);
            rep(k, down_count) operations.emplace_back('U', j);
            rep(k, down_count) move('D', j, c);
            rep(k, down_count) move('U', j, c);
        } else if (left_count <= right_count && left_count <= up_count && left_count <= down_count && can_move_left) {
            rep(k,15){
                if(c[i][k] == 'o') break;
                if(c[i][k] == 'x') left_count = k + 1;
            }
            rep(k, left_count) operations.emplace_back('L', i);
            rep(k, left_count) operations.emplace_back('R', i);
            rep(k, left_count) move('L', i, c);
            rep(k, left_count) move('R', i, c);
        } else if (can_move_right) {
            rep(k,15){
                if(c[i][n-k-1] == 'o') break;
                if(c[i][n-k-1] == 'x') right_count = k + 1;
            }
            rep(k, right_count) operations.emplace_back('R', i);
            rep(k, right_count) operations.emplace_back('L', i);
            rep(k, right_count) move('R', i, c);
            rep(k, right_count) move('L', i, c);
        }
        
        demons.clear();
        rep(i, n){
            rep(j, n) {
                if (c[i][j] == 'x') {
                    demons.emplace_back(i, j);
                }
            }
        }
    }

    // 操作を出力
    for (auto [d, p] : operations) {
        cout << d << " " << p << "\n";
    }

    return 0;
}
