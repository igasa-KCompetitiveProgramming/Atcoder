#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

//！？！？
#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

//int INF = 2147483647; // おおよそ2*10^9
ll inf = 1LL<<60; //おおよそ10^18
//ull UINF == おおよそ1.8*10^19

string s = "UDLRS";
vector<pint> dir = {{-1,0},{1,0},{0,-1},{0,1},{0,0}};
map<char,int> dir_map = {{'U',0},{'D',1},{'L',2},{'R',3},{'S',4}};

vector<vector<char>> directControlCopy;

class SOLVE{
  public:
    int N, M, K;
    vector<pint> firstPos;
    vector<vector<bool>> verticalField;
    vector<vector<bool>> horizontalField;

    void input(){
        cin >> N >> M >> K;
        firstPos.resize(M);
        verticalField.resize(N, vector<bool>(N-1, false));
        horizontalField.resize(N-1, vector<bool>(N, false));
        rep(M) cin >> firstPos[i].fi >> firstPos[i].se;
        string temp;
        rep(N){
            cin >> temp;
            rep(j, N-1){
                if(temp[j] == '1') verticalField[i][j] = true;
            }
        }
        rep(N-1){
            cin >> temp;
            rep(j, N){
                if(temp[j] == '1') horizontalField[i][j] = true;
            }
        }
    }

    bool wallCheck(pint a, int d){
        if(d == 0) return horizontalField[a.fi-1][a.se];
        if(d == 1) return horizontalField[a.fi][a.se];
        if(d == 2) return verticalField[a.fi][a.se-1];
        if(d == 3) return verticalField[a.fi][a.se];
        return false;
    }

    string dijkstra(vector<vector<bool>>& field, pint start){
        priority_queue<tuple<int, int , pint>, vector<tuple<int, int, pint>>, greater<tuple<int, int, pint>>> pq;
        vector<vector<int>> keiro(N, vector<int>(N, -1));
        pq.push({0, -2, start});
        //keiro[start.fi][start.se] = -2;
        pint goal = {-1, -1};
        while(!pq.empty()){
            auto [dist, direction, pos] = pq.top(); pq.pop();
            //cout << endl << pos.fi << spa << pos.se << spa << dist << endl;
            if(keiro[pos.fi][pos.se] != -1) continue;
            keiro[pos.fi][pos.se] = direction;
            if(field[pos.fi][pos.se] == false){
                goal = pos;
                break;
            }
            //cout << "here" << endl;
            rep(4){
                pint next = {pos.fi + dir[i].fi, pos.se + dir[i].se};
                if(next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                if(keiro[next.fi][next.se] != -1) continue;
                if(wallCheck(pos, i)) continue;
                //cout << next.fi << spa << next.se << endl;
                pq.push({dist + 1, i, next});
            }
        }
        string res = "";
        while(goal != start){
            int d = keiro[goal.fi][goal.se];
            res += s[d];
            goal = {goal.fi - dir[d].fi, goal.se - dir[d].se};
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int bfs(vector<vector<bool>>& field, pint start){
        priority_queue<pair<int,pint>, vector<pair<int,pint>>, greater<pair<int,pint>>> pq;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        pq.push({0, start});
        while(!pq.empty()){
            auto [dist, pos] = pq.top(); pq.pop();
            if(visited[pos.fi][pos.se]) continue;
            visited[pos.fi][pos.se] = true;
            if(field[pos.fi][pos.se] == false) return dist;
            int cnt = -1;
            for(auto [dx, dy] : dir){
                cnt++;
                pint next = {pos.fi + dx, pos.se + dy};
                if(next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                if(visited[next.fi][next.se]) continue;
                if(wallCheck(pos, cnt)) continue;
                pq.push({dist + 1, next});
            }
        }
        return -1;
    }

    int nearest_position(vector<vector<bool>>& field, vector<pint> &pos){
        ll min_dist = inf;
        int min_index = -1;
        rep(pos.size()){
            int dist = bfs(field, pos[i]);
            if(dist == -1) continue;
            if(dist < min_dist){
                min_dist = dist;
                min_index = i;
            }
            //cout << dist << spa << min_dist << spa << min_index << endl << endl;
        }
        return min_index;
    }

    void output(){
        rep(j,K){
            rep(i,M){
                if(j < s.size()) cout << s[j] << spa;
                else cout << 'S' << spa;
            }
            cout << endl;
        }
    }

    void generateDirectControl(vector<vector<char>>& directControl) {
        // 各ロボットの初期動作を'S'に設定
        rep(i, 4) {
            rep(j, M) {
                directControl[i][j] = s[i];
                //cout << directControl[i][j] << spa;
            }
            //cout << endl;
        }
        rep(i, 4, K){
            rep(j, M) {
                int dir_index = rand() % 4;
                directControl[i][j] = s[dir_index];
                //cout << directControl[i][j] << spa;
            }
            //cout << endl;
        }
    }

    vector<int> solve(){
        int maxOut = 110;
        vector<vector<bool>> cleanField(N, vector<bool>(N, false));
        vector<int> answer, answerCopy;
        int cleanCount = 0;
        rep(K){
            if(cleanField[firstPos[i].fi][firstPos[i].se]) continue;
            cleanField[firstPos[i].fi][firstPos[i].se] = true;
            cleanCount++;
        }
        vector<pint> nowPos = firstPos;
        vector<bool> used(M, false);
        answer = vector<int>();
        vector<vector<char>> directControl(M, vector<char>(M, 'S'));
        generateDirectControl(directControl);
        directControlCopy = directControl;
        while (cleanCount < N*N) {
            if (cleanCount <= maxOut) {
                int maxClean = 0;
                int bestIndex = -1;
                rep(M){
                    map<pint, int> mp;
                    rep(j, nowPos.size()){
                        pint next = {nowPos[j].fi + dir[dir_map[directControl[i][j]]].fi,
                                    nowPos[j].se + dir[dir_map[directControl[i][j]]].se};
                        if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                        if (wallCheck(nowPos[j], dir_map[directControl[i][j]])) continue;
                        if(cleanField[next.fi][next.se] == false) mp[next]++;
                    }
                    if(mp.size() > maxClean){
                        maxClean = mp.size();
                        bestIndex = i;
                    }
                }
                if(bestIndex == -1) maxOut = 0; // 強制的に後半戦へ
                answer.pb(bestIndex);
                rep(j, nowPos.size()){
                    pint next = {nowPos[j].fi + dir[dir_map[directControl[bestIndex][j]]].fi,
                                nowPos[j].se + dir[dir_map[directControl[bestIndex][j]]].se};
                    if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                    if (wallCheck(nowPos[j], dir_map[directControl[bestIndex][j]])) continue;
                    nowPos[j] = next;
                    if (!cleanField[next.fi][next.se]) {
                        cleanField[next.fi][next.se] = true;
                        cleanCount++;
                    }
                }
            } else {
                // 従来の最近点Dijkstra探索
                int next_index = nearest_position(cleanField, nowPos);
                string ans = dijkstra(cleanField, nowPos[next_index]);
                rep(ans.size()) {
                    answer.pb(dir_map[ans[i]]);
                    rep(j, nowPos.size()) {
                        pint next = {nowPos[j].fi + dir[dir_map[ans[i]]].fi,
                                    nowPos[j].se + dir[dir_map[ans[i]]].se};
                        if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                        if (wallCheck(nowPos[j], dir_map[ans[i]])) continue;
                        nowPos[j] = next;
                        if (!cleanField[next.fi][next.se]) {
                            cleanField[next.fi][next.se] = true;
                            cleanCount++;
                        }
                    }
                }
            }
        }
        return answer;
    }

    vector<int> solve2() {
        vector<vector<bool>> cleanField(N, vector<bool>(N, false));
        vector<int> answer, answerCopy;
        int cleanCount = 0;

        rep(K) {
            if (cleanField[firstPos[i].fi][firstPos[i].se]) continue;
            cleanField[firstPos[i].fi][firstPos[i].se] = true;
            cleanCount++;
        }

        vector<pint> nowPos = firstPos;
        vector<bool> used(M, false);
        answer = vector<int>();

        while (cleanCount < N * N) {
            int next_index = nearest_position(cleanField, nowPos);
            used[next_index] = true;

            string ans = dijkstra(cleanField, nowPos[next_index]);
            rep(ans.size()) {
                answer.pb(dir_map[ans[i]]);

                rep(j, nowPos.size()) {
                    // int dir_index = 0;
                    pint next = {
                        nowPos[j].fi + dir[dir_map[ans[i]]].fi,
                        nowPos[j].se + dir[dir_map[ans[i]]].se
                    };

                    if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                    if (wallCheck(nowPos[j], dir_map[ans[i]])) continue;

                    nowPos[j] = next;

                    if (cleanField[next.fi][next.se] == false) {
                        cleanField[next.fi][next.se] = true;
                        cleanCount++;
                    }
                }
            }
        }

        return answer;
    }

    vector<int> solve3(){
        int maxOut = 110;
        vector<vector<bool>> cleanField(N, vector<bool>(N, false));
        vector<int> answer, answerCopy;
        int cleanCount = 0;
        rep(K){
            if(cleanField[firstPos[i].fi][firstPos[i].se]) continue;
            cleanField[firstPos[i].fi][firstPos[i].se] = true;
            cleanCount++;
        }
        vector<pint> nowPos = firstPos;
        vector<bool> used(M, false);
        answer = vector<int>();
        while (cleanCount < N*N) {
            if (cleanCount <= maxOut) {
                // 序盤: 一手で最大カバー
                int best_gain = -1;
                vector<int> best_action(M, 4); // 初期はS
                // 各ロボットについて候補動作を選ぶ
                rep(mask, 5) { // 単純化例: 全ロボット同じ動き
                    vector<pint> nextPos = nowPos;
                    int gain = 0;
                    rep(i, M) {
                        pint next = {nowPos[i].fi + dir[mask].fi,
                                    nowPos[i].se + dir[mask].se};
                        if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                        if (wallCheck(nowPos[i], mask)) continue;
                        nextPos[i] = next;
                        if (!cleanField[next.fi][next.se]) gain++;
                    }
                    if (gain > best_gain) {
                        best_gain = gain;
                        rep(i, M) best_action[i] = mask;
                    }
                }
                if(best_gain == -1) maxOut = 0; // 強制的に後半戦へ
                // 実行
                answer.pb(best_action[0]); // 出力はボタン番号だが、仮にdir_map相当を利用
                rep(i, M) {
                    pint next = {nowPos[i].fi + dir[best_action[i]].fi,
                                nowPos[i].se + dir[best_action[i]].se};
                    if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                    if (wallCheck(nowPos[i], best_action[i])) continue;
                    nowPos[i] = next;
                    if (!cleanField[next.fi][next.se]) {
                        cleanField[next.fi][next.se] = true;
                        cleanCount++;
                    }
                }
            } else {
                // 従来の最近点Dijkstra探索
                int next_index = nearest_position(cleanField, nowPos);
                string ans = dijkstra(cleanField, nowPos[next_index]);
                rep(ans.size()) {
                    answer.pb(dir_map[ans[i]]);
                    rep(j, nowPos.size()) {
                        pint next = {nowPos[j].fi + dir[dir_map[ans[i]]].fi,
                                    nowPos[j].se + dir[dir_map[ans[i]]].se};
                        if (next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= N) continue;
                        if (wallCheck(nowPos[j], dir_map[ans[i]])) continue;
                        nowPos[j] = next;
                        if (!cleanField[next.fi][next.se]) {
                            cleanField[next.fi][next.se] = true;
                            cleanCount++;
                        }
                    }
                }
            }
        }
        return answer;
    }
};

int main(){
    SOLVE solve;
    solve.input();
    //solve.output();
    vector<int> answer = solve.solve();
    vector<int> answer2 = solve.solve2();
    vector<int> answer3 = solve.solve3();
    if(answer3.size() < answer.size()) answer = answer3;
    //cout << answer.size() << spa << answer2.size() << endl;
    if(answer.size() < answer2.size()){
        rep(directControlCopy.size()){
            rep(j,directControlCopy[i].size()){
                cout << directControlCopy[i][j] << spa;
            }
            cout << endl;
        }
        rep(answer.size()) cout << answer[i] << endl;
    }else{
        solve.output();
        rep(answer2.size()) cout << answer2[i] << endl;
    }
}