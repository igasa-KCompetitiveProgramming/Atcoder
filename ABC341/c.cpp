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
    int h,w,n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    int ans = 0;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    rep(i,h){
        rep(j,w){
            vector<int> pos = {i,j};
            bool flag = true;
            if(s[pos[0]][pos[1]]=='#'){
                continue;
            }
            rep(k,n){
                if(t[k]=='R'){
                    pos[0] += dx[0];
                    pos[1] += dy[0];
                }else if(t[k]=='D'){
                    pos[0] += dx[1];
                    pos[1] += dy[1];    
                }else if(t[k]=='L'){
                    pos[0] += dx[2];
                    pos[1] += dy[2];
                }else if(t[k]=='U'){
                    pos[0] += dx[3];
                    pos[1] += dy[3];
                }
                if(pos[0]<0 || pos[0]>=h || pos[1]<0 || pos[1]>=w || s[pos[0]][pos[1]]=='#'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
    }
    cout << ans << endl;
}