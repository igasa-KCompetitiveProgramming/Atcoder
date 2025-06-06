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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>(2));
    vector<bool> ans(n);
    int check = n;
    rep(i,n){
        ans[i] = true;
    }
    rep(i,m){
        cin >> a[i][0] >> a[i][1];
    }
    rep(i,m){
        if(ans[a[i][1]-1]){
            check--;
        }
        ans[a[i][1]-1] = false;
    }
    if(check == 1){
        rep(i,n){
            if(ans[i]){
                cout << i+1 << endl;
                break;
            }
        }
    }
    else{
        cout << -1 << endl;
    }
}