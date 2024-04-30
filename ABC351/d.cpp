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
    vector<int> dx{1,0,-1,0};
    vector<int> dy{0,1,0,-1};
    int ans=1;
    vector<vector<bool>> cantMove(h,vector<bool>(w,false));
    vector<pint> cantMoveList;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                rep(k,4){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if(s[nx][ny] == '#') continue;
                    cantMove[nx][ny] = true;
                    cantMoveList.push_back({nx,ny});
                }
            }
        }
    }
    vector<vector<bool>> visited(h,vector<bool>(w,false));
    set<pint> cantMoveSet;
    rep(i,h){
        rep(j,w){
            cantMoveSet.clear();
            if(visited[i][j]) continue;
            if(s[i][j] == '#') continue;
            if(cantMove[i][j]) continue;
            queue<pint> q;
            q.push({i,j});
            visited[i][j] = true;
            int tmp = 1;
            while(!q.empty()){
                if(cantMove[q.front().first][q.front().second]){
                    q.pop();
                    continue;
                }
                pint now = q.front();
                q.pop();
                rep(k,4){
                    int nx = now.first + dx[k];
                    int ny = now.second + dy[k];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if(visited[nx][ny]) continue;
                    if(cantMove[nx][ny]){
                        cantMoveSet.insert({nx,ny});
                        continue;
                    }
                    tmp++;
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
            tmp += cantMoveSet.size();
            ans = max(ans,tmp);
        }
    }
    cout << ans << endl;
}