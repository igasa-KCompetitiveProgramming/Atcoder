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
    int n,m;
    cin >> n >> m;
    vector<int> p(n),c(n);
    vector<vector<bool>> f(n,vector<bool>(m));
    rep(i,n){
        cin >> p[i] >> c[i];
        rep(j,c[i]){
            int tmp;
            cin >> tmp;
            f[i][tmp-1] = true;
        }
    }

    bool checkHavingFunction = true;
    bool checkHavingAddFunction = false;
    bool ans = false;

    rep(i,n){
        rep(j,n){
            bool checkHavingFunction = true;
            bool checkHavingAddFunction = false;
            if(p[i]<=p[j]){
                rep(k,m){
                    if(f[i][k] == true && f[j][k] == false){
                        checkHavingAddFunction = true;
                    }else if(f[i][k] == true && f[j][k] == true){
                        continue;
                    }else if(f[i][k] == false && f[j][k] == true){
                        checkHavingFunction = false;
                    }
                }
                if(checkHavingFunction == true && checkHavingAddFunction == true){
                    ans = true;
                }else if(checkHavingFunction == true && checkHavingAddFunction == false){
                    if(p[i] < p[j]){
                        ans = true;
                    }
                }
            }
        }
    }

    YesNo(ans);
}