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
    int h,w;
    cin >> h >> w;
    vector<int> x;
    vector<int> y;
    int ans=0;
    vector<vector<char>> s(h,vector<char>(w));
    int dx[9] = {0,0,0,1,1,1,-1,-1,-1};
    int dy[9] = {0,1,-1,0,1,-1,0,1,-1};
    rep(i,h){
        rep(j,w){
        cin >> s[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                x.push_back(i);
                y.push_back(j);
                while(!x.empty()){
                    s[x[0]][y[0]] = '.'; 
                    rep(j,9){
                        int nx = x[0]+dx[j];
                        int ny = y[0]+dy[j];
                        if(nx < 0 || nx > h-1 || ny < 0 || ny > w-1){
                            continue;
                        }
                        if(s[nx][ny] == '#'){
                            s[nx][ny] = '.';
                            x.push_back(nx);
                            y.push_back(ny);
                        }
                    }
                    x.erase(x.begin());
                    y.erase(y.begin());
                }
                ans++;
            }
        }
    }
    cout << ans;
}