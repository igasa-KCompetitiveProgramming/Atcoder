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
    vector<int> a(8);
    rep(i,8){
        cin >> a[i];
    }
    rep(i,8){
        if(a[i]%25!=0){
            cout << "No" << endl;
            return 0;
        }
        if(i!=7){
            if(a[i]>a[i+1]){
                cout << "No" << endl;
                return 0;
            }
        }
        if(a[i]>675||a[i]<100){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}