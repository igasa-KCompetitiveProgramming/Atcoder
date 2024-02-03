#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<vector<char>> s(h,vector<char>(w,'.'));
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    int check = -1;
    pint p = make_pair(0,0);
    rep(i,n){
        if(s[p.first][p.second] == '.'){
            check++;
            if(check == 4){
                check = 0;
            }else if(check == -1){
                check = 3;
            }
            s[p.first][p.second] = '#';
            p.first += dy[check];
            p.second += dx[check];
        }else{
            check--;
            if(check == -1){
                check = 3;
            }else if(check == 4){
                check = 0;
            }
            s[p.first][p.second] = '.';
            p.first += dy[check];
            p.second += dx[check];
        }
        if(p.first == h){
            p.first = 0;
        }else if(p.first == -1){
                p.first = h-1;
        }
        if(p.second == w){
            p.second = 0;
        }else if(p.second == -1){
            p.second = w-1;
        }
    }
    rep(i,h){
        rep(j,w){
            cout << s[i][j];
        }
        cout << endl;
    }
}