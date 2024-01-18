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
    ll n;
    cin >> n;
    vector<string> a(n);
    rep(i,n){
        cin >> a[i];
    }

    vector<vector<ll>> b(n, vector<ll>(n));
    rep(i,n){
        rep(j,n){
            b[i][j] = a[i][j] - '0';
        }
    }

    vector<vector<vector<ll>>> ans(n, vector<vector<ll>>(n, vector<ll>(8)));
    vector<ll> dx = {-1,0,1,-1,1,-1,0,1};
    vector<ll> dy = {1,1,1,0,0,-1,-1,-1};
    rep(i,n){
        rep(j,n){
            rep(k,8){
                rep(l,n){
                    int nx = i + dx[k]*l;
                    int ny = j + dy[k]*l;
                    if(nx < 0){
                        nx += n;
                    }
                    if(nx >= n){
                        nx -= n;
                    }
                    if(ny < 0){
                        ny += n;
                    }
                    if(ny >= n){
                        ny -= n;
                    }
                    ans[i][j][k] += pow(10,l)*b[nx][ny];
                }
            }
        }
    }

    ll maximum = 0;
    rep(i,n){
        rep(j,n){
            rep(k,8){
                maximum = max(maximum,ans[i][j][k]);
            }
        }
    }
    cout << maximum << endl;
}