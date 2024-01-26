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
    int n;
    cin >> n;
    vector<vector<char>> b(n,vector<char>(n));
    vector<vector<char>> ans(n,vector<char>(n));
    rep(i,n){
        rep(j,n){
            cin >> b[i][j];
        }
    } 
    
    int dx[4] = {0,0,n-1,0};
    int dy[4] = {0,n-1,0,0};
    
    rep(i,4){
        rep(j,n-1){
            dy[0] = j;
            dx[1] = j;
            dy[2] = n-j-1;
            dx[3] = n-j-1;
            if(i == 0){
                ans[dx[i]][dy[i]+1] = b[dx[i]][dy[i]];
            }else if(i == 1){
                ans[dx[i]+1][dy[i]] = b[dx[i]][dy[i]];
            }else if(i == 2){
                ans[dx[i]][dy[i]-1] = b[dx[i]][dy[i]];
            }else{
                ans[dx[i]-1][dy[i]] = b[dx[i]][dy[i]];
            }
        }
    }

    rep(i,n-2){
        rep(j,n-2){
            ans[i+1][j+1] = b[i+1][j+1];
        }
    }

    rep(i,n){
        rep(j,n){
            cout << ans[i][j];
        }
        cout << endl;
    }
}