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
    string s;
    s = "wbwbwwbwbwbw";
    string tmp = s;
    int a,b;
    cin >> a >> b;
    rep(i,30){
        s += tmp;
    }
    vector<int> ans(2);
    rep(i,30){
        ans[0] = 0;
        ans[1] = 0;
        rep(j,a+b){
            if(s[i+j] == 'w'){
                ans[0]++;
            }else{
                ans[1]++;
            }
        }
        if(ans[0] == a && ans[1] == b){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}