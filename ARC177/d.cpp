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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int n,h;
    cin >> n >> h;
    vector<pint> x(n);
    rep(i,n){
        cin >> x[i].second;
        x[i].first = i;
    }
    //secondの値でfirstをsort
    sort(x.begin(),x.end(),compare_by_b);
    vector<vector<pint>> y(n);
    int cnt = 0;
    rep(i,n-1){
        if(x[i+1].second - x[i].second <= h){
            y[cnt].push_back(x[i]);
            y[cnt].push_back(x[i+1]);
            while(true){
                i++;
                if(i == n-1){
                    cnt++;
                    break;
                }
                if(x[i+1].second - x[i].second <= h){
                    y[cnt].push_back(x[i+1]);
                }else{
                    cnt++;
                    break;
                }
            }
        }
    }
    vector<int> ans(n);
    rep(i,n){
        if(y[i].size() == 0){
            y.erase(y.begin()+i);
        }
    }
    rep(i,y.size()){
        vector<vector<int>> z(y[i].size()+3);
        rep(j,y[i].size()){
            if(y[i][j].first == 0){
                
            }
        }
    }

}