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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> query(q, vector<int>(2));
    rep(i,q){
        cin >> query[i][0] >> query[i][1];
    }

    int checkPoint = 0;
    rep(i,q){
        if(query[i][0] == 1){
            checkPoint += query[i][1];
            checkPoint %= n;
        }else{
            if(query[i][1] - checkPoint <= 0){
                //cout << query[i][1] << "-" << checkPoint << "+" << n << endl;
                cout << s[query[i][1] - checkPoint + n - 1] << endl;
            }else{
                //cout << query[i][1] - checkPoint - 1 << endl;
                cout << s[query[i][1] - checkPoint - 1] << endl;
            }
        }
    }
}