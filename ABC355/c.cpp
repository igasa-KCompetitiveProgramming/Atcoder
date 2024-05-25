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
    int n,t;
    cin >> n >> t;
    vector<int> a(t);
    vector<int> x(n),y(n),xy(2);
    vector<vector<int>> xyCheck(2);
    int tmp = 1;
    rep(i,n){
        xyCheck[0].push_back(tmp);
        tmp += n+1;
    }
    tmp = n;
    rep(i,n){
        xyCheck[1].push_back(tmp);
        tmp += n-1;
    }
    rep(i,t){
        cin >> a[i];
    }
    rep(i,t){



        x[(a[i]-1)/n]++;
        if(x[(a[i]-1)/n]==n){
            cout << i+1;
            return 0;
        }
        y[((a[i]-1)%n)]++;
        if(y[(a[i]%n)-1]==n){
            cout << i+1;
            return 0;
        }
        if(binary_search(xyCheck[0].begin(),xyCheck[0].end(),a[i])){
            xy[0]++;
            if(xy[0]==n){
                cout << i+1;
                return 0;
            }
        }
        if(binary_search(xyCheck[1].begin(),xyCheck[1].end(),a[i])){
            xy[1]++;
            if(xy[1]==n){
                cout << i+1;
                return 0;
            }
        }
    }
    cout << -1;
}