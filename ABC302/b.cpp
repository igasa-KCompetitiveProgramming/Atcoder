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
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<pint> checkList;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 's') checkList.push_back(make_pair(i,j));
        }
    }
    vector<int> dx = {1,0,-1,1,-1,1,0,-1};
    vector<int> dy = {1,1,1,0,0,-1,-1,-1};
    string check = "nuke";
    vector<pint> ans(5);
    rep(i,checkList.size()){
        ans[0] = checkList[i];
        rep(j,8){
            rep1(k,4){
                if(checkList[i].first+dx[j]*k < 0 || checkList[i].first+dx[j]*k >= h || checkList[i].second+dy[j]*k < 0 || checkList[i].second+dy[j]*k >= w){
                    ans.clear();
                    break;
                }
                if(s[checkList[i].first+dx[j]*k][checkList[i].second+dy[j]*k] != check[k-1]){
                    ans.clear();
                    break;
                }else ans.push_back(make_pair(checkList[i].first+dx[j]*k,checkList[i].second+dy[j]*k));
                if(k == 4){
                    cout << checkList[i].first+1 << " " << checkList[i].second+1 << endl;
                    rep(l,4){
                        cout << ans[l].first+1 << " " << ans[l].second+1 << endl;
                    }
                    return 0;
                }
            }
        }
    }
}