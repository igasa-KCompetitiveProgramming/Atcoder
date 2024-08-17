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
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    int h,w,x,y;
    cin >> h >> w >> y >> x;
    vector<string> c(h);
    rep(i,h){
        cin >> c[i];
    }
    x--;
    y--;
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s[i]=='L'){
            if(x-1>=0){
                if(c[y][x-1]=='#'){
                    continue;
                }
                x--;
            }
        }else if(s[i]=='R'){
            if(x+1<w){
                if(c[y][x+1]=='#'){
                    continue;
                }
                x++;
            }
        }else if(s[i]=='D'){
            if(y+1<h){
                if(c[y+1][x]=='#'){
                    continue;
                }
                y++;
            }
        }else if(s[i]=='U'){
            if(y-1>=0){
                if(c[y-1][x]=='#'){
                    continue;
                }
                y--;
            }
        }
    }
    cout << y+1 << " " << x+1 << endl;
}