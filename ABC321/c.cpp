#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    vector<vector<int>> a(9, vector<int>(9));
    vector<bool> check(9,false);
    bool ans = true;
    rep(i,9){
        rep(j,9){
            cin >> a[i][j];
        }
    }

    rep(i,9){
        rep(j,9){
            check[a[i][j]-1] = true;
        }
        if(all_of(check.begin(), check.end(), [](bool x){return x;})){
            rep(i,9){
                check[i] = false;
            }
        }else{
            ans = false;
            break;
        }

        rep(j,9){
            check[a[j][i]-1] = true;
        }
        if(all_of(check.begin(), check.end(), [](bool x){return x;})){
            rep(i,9){
                check[i] = false;
            }
        }else{
            ans = false;
            break;
        }
    }

    rep(i,3){
        rep(j,3){
            rep(k,3){
                rep(l,3){
                    check[a[i*3+k][j*3+l]-1] = true;
                }
            }
            if(all_of(check.begin(), check.end(), [](bool x){return x;})){
                rep(i,9){
                    check[i] = false;
                }
            }else{
                ans = false;
                break;
            }
        }
        if(ans == false) break;
    }

    YesNo(ans);
}