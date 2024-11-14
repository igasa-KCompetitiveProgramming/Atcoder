#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    vector<string> s(8);
    rep(i,8){
        cin >> s[i];
    }
    vector<vector<bool>> ans(8,vector<bool>(8,false));
    rep(i,8){
        bool flag = false;
        rep(j,8){
            if(s[i][j] == '#') flag = true;
        }
        if(flag){
            rep(j,8){
                ans[i][j] = true;
            }
        }
    }
    rep(i,8){
        bool flag = false;
        rep(j,8){
            if(s[j][i] == '#') flag = true;
        }
        if(flag){
            rep(j,8){
                ans[j][i] = true;
            }
        }
    }
    int cnt = 0;
    rep(i,8){
        rep(j,8){
            if(!ans[i][j]){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}