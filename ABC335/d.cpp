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
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    a[0][0] = 1;
    rep(i,n/2){
        rep(j,4){
            rep(k,n-i*2){
                if(j==0){
                    if(k==0&&i==0){
                        a[i][k] = 1;
                    }else{
                        a[i][k+i] = a[i][k+i-1] + 1;
                    }
                }else if(j==1){
                    if(k!=0){
                        a[k+i][n-i-1] = a[k+i-1][n-i-1] + 1;
                    }
                }else if(j==2){
                    if(k!=0){
                        a[n-i-1][n-k-i-1] = a[n-i-1][n-k-i] + 1;
                    }
                }else if(j==3){
                    if(k!=0&&k!=n-1-i*2){
                        a[n-k-i-1][i] = a[n-k-i][i] + 1;
                    }
                }
            }
        }

        
    }
    rep(i,n){
            rep(j,n){
                if(i==j&&i==n/2){
                    cout << 'T' << " ";
                }else{
                cout << a[i][j] << " ";
                }
            }
            cout << endl;
        }
}