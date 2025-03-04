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

//vectorのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//dequeのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::deque<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::deque<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//pairのcin,cout
template<typename T,typename U>
std::ostream &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
std::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
//vector<vector<T>>のcout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) {
for (const auto &row : v) {for (auto it = row.begin(); it != row.end(); ++it) { os << *it; if (std::next(it) != row.end()) { os << " "; } } os << "\n";} return os;}

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

const int RAIL_HORIZONTAL = 1;
const int RAIL_VERTICAL = 2;
const int RAIL_LEFT_DOWN = 3;
const int RAIL_LEFT_UP = 4;
const int RAIL_RIGHT_UP = 5;
const int RAIL_RIGHT_DOWN = 6;

const vector<int> dx = {-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
const vector<int> dy = {0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};

const vector<int> dx2 = {-1,0,0,0,1};
const vector<int> dy2 = {0,-1,0,1,0};

vector<bool> usedStation;
vector<bool> usedFirstStation;
int FirstStation;

vector<string> ansSt;
int ansMoney = 0;

class solve{
    public:
    
    int n,m,money,turn;
    vector<pint> start;
    vector<pint> goal;
    vector<pint> distanceSG;
    vector<vector<vector<int>>> home;
    vector<vector<vector<int>>> work;
    vector<vector<int>> rail;

    vector<string> ans;
    vector<pair<bool,bool>> connected;
    vector<bool> used;
    vector<pint> station;
    int income = 0;
    int turnCount = 0;
    bool clossedCheck = false;

    int calcConnectTurn(int D, int M, int I){
        int ret = 0;
        rep(D){
            M -= 100;
            if(M < 0){
                while(M < 0){
                    M += I;
                    ret++;
                }
            }
            M += I;
        }
        return ret;
    }

    bool findRailEuclidean(pint p){
        int nx = p.fi;
        int ny = p.se;
        rep(13){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= n) continue;
            for(auto h : home[x][y]){
                if(connected[h].fi && connected[h].se) continue;
                if(connected[h].se) return true;
            }
            for(auto w : work[x][y]){
                if(connected[w].fi && connected[w].se) continue;
                if(connected[w].fi) return true;
            }
        }
        return false;
    }

    pint findNextStation(){
        pint res = {-1,-1};
        rep(n){
            rep(j,n){
                if(rail[i][j] != 0 && rail[i][j] != -1){
                    if(findRailEuclidean({i,j})){
                        res = {i,j};
                        //cout << res.fi << spa << res.se << endl;
                        return res;
                    }
                }
            }
        }
        return res;
    }

    void updateIncome(){
        int tmp = 0;
        rep(m){
            if(connected[i].fi && connected[i].se){
                tmp += distance(start[i],goal[i]);
            }
        }
        income = tmp;
    }

    void checkConnected(pint center){
        int nx = center.fi;
        int ny = center.se;
        rep(13){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= n) continue;
            for(auto h : home[x][y]){
                connected[h].fi = true;
            }
            for(auto w : work[x][y]){
                connected[w].se = true;
            }
        }
    }

    int distance(pint a, pint b){
        return abs(a.fi - b.fi) + abs(a.se - b.se);
    }

    void input(){
        cin >> n >> m >> money >> turn;
        start.resize(m);
        goal.resize(m);
        home.resize(n+1,vector<vector<int>>(n+1,vector<int>(0)));
        work.resize(n+1,vector<vector<int>>(n+1,vector<int>(0)));
        rail.resize(n+1,vector<int>(n,-1));
        used.resize(m,false);
        usedFirstStation.resize(m,false);
        distanceSG.resize(m);
        rep(m){
            cin >> start[i].fi >> start[i].se >> goal[i].fi >> goal[i].se;
            home[start[i].fi][start[i].se].pb(i);
            work[goal[i].fi][goal[i].se].pb(i);
            distanceSG[i] = {distance(start[i],goal[i]),m - i};
        }
        sort(distanceSG.rbegin(),distanceSG.rend());
        connected.resize(m,pair<bool,bool>(false,false));
        ans.resize(800,"-1");
    }

    void placeStation(int h, int w){
        rail[h][w] = 0;
        turn--;
        money -= 5000;
        ans[turnCount] = "0 " + to_string(h) + " " + to_string(w);
        turnCount++;
    }

    void placeRail(int direction, int h, int w){ //directionは1:左右 2:上下 3:左から下 4:左から上 5:上から右 6:下から右
        if(rail[h][w] != -1){
            clossedCheck = true;
            return;
        }
        rail[h][w] = direction;
        turn--;
        ans[turnCount] = to_string(direction) + " " + to_string(h) + " " + to_string(w);
        turnCount++;
    }

    void connectStation(int r0, int c0, int r1, int c1, int param){
        rail[r0][c0] = rail[r1][c1] = 0;
        if(param == 0){
            if (r0 < r1) {
                for (int r = r0 + 1; r < r1; ++r) {
                    placeRail(RAIL_VERTICAL, r, c0);
                }
                if (c0 < c1) {
                    placeRail(RAIL_RIGHT_UP, r1, c0);
                } else if (c0 > c1) {
                    placeRail(RAIL_LEFT_UP, r1, c0);
                }
            } else if (r0 > r1) {
                for (int r = r0 - 1; r > r1; --r) {
                    placeRail(RAIL_VERTICAL, r, c0);
                }
                if (c0 < c1) {
                    placeRail(RAIL_RIGHT_DOWN, r1, c0);
                } else if (c0 > c1) {
                    placeRail(RAIL_LEFT_DOWN, r1, c0);
                }
            }
            // c0 -> c1
            if (c0 < c1) {
                for (int c = c0 + 1; c < c1; ++c) {
                    placeRail(RAIL_HORIZONTAL, r1, c);
                }
            } else if (c0 > c1) {
                for (int c = c0 - 1; c > c1; --c) {
                    placeRail(RAIL_HORIZONTAL, r1, c);
                }
            } 
        }else if(param == 1){
            if (c0 < c1) {
                for (int c = c0 + 1; c < c1; ++c) {
                    placeRail(RAIL_HORIZONTAL, r0, c);
                }
                if (r0 < r1) {
                    placeRail(RAIL_LEFT_DOWN, r0, c1);
                } else if (r0 > r1) {
                    placeRail(RAIL_LEFT_UP, r0, c1);
                }
            } else if (c0 > c1) {
                for (int c = c0 - 1; c > c1; --c) {
                    placeRail(RAIL_HORIZONTAL, r0, c);
                }
                if (r0 < r1) {
                    placeRail(RAIL_RIGHT_DOWN, r0, c1);
                } else if (r0 > r1) {
                    placeRail(RAIL_RIGHT_UP, r0, c1);
                }
            }
            // r0 -> r1
            if (r0 < r1) {
                for (int r = r0 + 1; r < r1; ++r) {
                    placeRail(RAIL_VERTICAL, r, c1);
                }
            } else if (r0 > r1) {
                for (int r = r0 - 1; r > r1; --r) {
                    placeRail(RAIL_VERTICAL, r, c1);
                }
            }
        }
    }

    void selectFirstStation(int param1, int param2, int param3, int param4){
        int idx = -1;
        int maxDist = money - 10000;
        maxDist = maxDist / 100;

        rep(m){
            if(usedFirstStation[m - distanceSG[i].se]) continue;
            if(distanceSG[i].fi <= maxDist){
                idx = m - distanceSG[i].se;
                break;
            }
        }
        FirstStation = idx;

        pint S = {start[idx].fi + param1,start[idx].se + param2};
        pint G = {goal[idx].fi + param3,goal[idx].se + param4};
        if(S.fi < 0 || S.fi >= n || S.se < 0 || S.se >= n) return;
        if(G.fi < 0 || G.fi >= n || G.se < 0 || G.se >= n) return;
        if(distance(S,G) > maxDist) return;
        placeStation(G.fi ,G.se);
        placeStation(S.fi ,S.se);
        station.pb(G);
        station.pb(S);
        connectStation(S.fi,S.se,G.fi,G.se,0);
        money -= (distance(S,G) - 1) * 100;

        checkConnected(S);
        checkConnected(G);
        
        updateIncome();

        if(ansMoney < money + income * (800 - turnCount)){
            ansMoney = money + income * (800 - turnCount);
            ansSt = ans;
        }
    }

    void selectSecondStation(int param1, int param2){
        int idx = -1;
        int minDist = 0;
        pint nextStation = {-1,-1};
        rep(m){
            if(usedStation[i]) continue;
            if(connected[i].fi && connected[i].se) continue;
            if(connected[i].fi || connected[i].se){
                if(minDist < distance(start[i],goal[i])){
                    minDist = distance(start[i],goal[i]);
                    idx = i;
                    if(connected[i].fi) nextStation = goal[i];
                    else nextStation = start[i];
                }
            }
        }
        if(idx == -1) return;
        usedStation[idx] = true;
        if(nextStation == pint(-1,-1)){
            return;
        }

        nextStation = {nextStation.fi + param1,nextStation.se + param2};
        if(nextStation.fi < 0 || nextStation.fi >= n || nextStation.se < 0 || nextStation.se >= n) return;

        int tmp = turnCount;
        int tmpDistance;
        pint toConnectedStation;

        if(distance(nextStation,station[0]) < distance(nextStation,station[1])) toConnectedStation = station[0];
        else toConnectedStation = station[1];

        tmpDistance = distance(nextStation,toConnectedStation);
        if(income == 0) return;
        if(5000 > money){
            turnCount += (5000 - money) / income;
            money += income * (turnCount - tmp + 1);
        }
        if(turnCount + tmpDistance + (tmpDistance * 100) / income > 800){
            return;
        }
        placeStation(nextStation.fi,nextStation.se);
        station.pb(nextStation);

        tmp = turnCount;
        turnCount += calcConnectTurn(tmpDistance,money,income);

        money += income * (turnCount - tmp + 1);
        money += (income - 100) * (distance(nextStation,toConnectedStation) - 2) - 100;

        tmp = turnCount;
        int tmpMoney = 0;
        clossedCheck = false;
        bool flag = false;

        rep(i,2){
            rep(j,2){
                turnCount = 2;
                rep(i,2,n){
                    ans[i] = "-1";
                }
                rep(rail.size()){
                    rep(j,rail[i].size()){
                        if(rail[i][j] != 0) rail[i][j] = -1;
                    }
                }
                connectStation(station[0].fi,station[0].se,station[1].fi,station[1].se,i);
                turnCount = tmp;
                connectStation(nextStation.fi,nextStation.se,toConnectedStation.fi,toConnectedStation.se,j);
                if(!clossedCheck){
                    flag = true;
                    break;
                }
                clossedCheck = false;
            }
            if(flag) break;
        }

        checkConnected(nextStation);
        updateIncome();

        money += income;
        if(ansMoney < money + income * (800 - turnCount)){
            ansMoney = money + income * (800 - turnCount);
            ansSt = ans;
        }
        
        for(int i = turnCount; turnCount < 700; i++){
            if(money > 5000){
                nextStation = findNextStation();
                if(nextStation == pint(-1,-1)) break;
                else placeStation(nextStation.fi,nextStation.se);
                station.pb(nextStation);

                checkConnected(nextStation);
                updateIncome();
            }else{
                turnCount++;
            }
            money += income;
            if(ansMoney < money + income * (800 - turnCount)){
                ansMoney = money + income * (800 - turnCount);
                ansSt = ans;
            }
        }

        



        while(true){
            minDist = 0;
            nextStation = {-1,-1};
            rep(m){
                if(usedStation[i]) continue;
                if(connected[i].fi && connected[i].se) continue;
                if(connected[i].fi || connected[i].se){
                    if(minDist < distance(start[i],goal[i])){
                        minDist = distance(start[i],goal[i]);
                        idx = i;
                        if(connected[i].fi) nextStation = goal[i];
                        else nextStation = start[i];
                    }
                }
            }

            //cout << "#1 " << turnCount << spa << money << endl;

            if(idx == -1 || idx >= m) return;
            if(turnCount >= 800) return;
            usedStation[idx] = true;
            if(money < 5000){
                tmp = turnCount;
                turnCount += 5000 / income;
                money += income * (turnCount - tmp + 1); 
            }
            if(nextStation == pint(-1,-1)){
                return;
            }
            if(turnCount >= 800) return;
            placeStation(nextStation.fi,nextStation.se);
            
            int selectStation = -1;
            minDist = inf;
            vector<pint> stationDist;
            rep(i,station.size()){
                if(distance(station[i],nextStation) < minDist){
                    minDist = distance(station[i],nextStation);
                    selectStation = i;
                }
            }

            rep(i,station.size()){
                stationDist.pb({distance(station[i],nextStation),i});
            }
            sort(stationDist.begin(),stationDist.end());
            
            //cout << "#1.5 " << turnCount << spa << money << endl;

            tmp = turnCount;
            tmpMoney = money;
            rep(i,stationDist.size()){
                turnCount = tmp;
                money = tmpMoney;
                //cout << "#i " << i << spa << tmp << spa << turnCount << spa << stationDist[i].fi << endl;
                selectStation = stationDist[i].se;
                
                turnCount += calcConnectTurn(stationDist[i].fi,money,income);
                int resser = turnCount;
                money += income * (turnCount - tmp);
                money += (income - 100) * (distance(station[selectStation],nextStation) - 2) - 100;

                if(turnCount + distance(station[selectStation],nextStation) >= 800){
                    money += 5000;
                    return;
                }

                clossedCheck = false;
                vector<vector<int>> railTmp = rail; 
                connectStation(station[selectStation].fi,station[selectStation].se,nextStation.fi,nextStation.se,0);
                if(clossedCheck){
                    clossedCheck = false;
                    turnCount = resser;
                    rail = railTmp;
                    connectStation(station[selectStation].fi,station[selectStation].se,nextStation.fi,nextStation.se,1);
                }
                if(!clossedCheck) break;
                else{
                    rail = railTmp;
                    for(int j = tmp; j < tmp + stationDist[i].fi; j++){
                        if(j >= 800) break;
                        ans[j] = "-1";
                    }
                }
            }

            //cout << "#2 " << turnCount << spa << money << spa << income << endl;  

            if(clossedCheck){
                turnCount = tmp;
                rep(i,turnCount,800){
                    ans[i] = "-1";
                }
                return;
            }

            checkConnected(nextStation);
            updateIncome();

            //cout << "#3 income " << income << endl;
            money += income;
            if(ansMoney < money + income * (800 - turnCount)){
                ansMoney = money + income * (800 - turnCount);
                ansSt = ans;
            }

            for(int i = turnCount; turnCount < 700; i++){
                //cout << "#4 " << spa << turnCount << spa << money << endl;
                if(money > 5000){
                    nextStation = findNextStation();
                    if(nextStation == pint(-1,-1)) break;
                    else placeStation(nextStation.fi,nextStation.se);
                    station.pb(nextStation);
                    checkConnected(nextStation);
                    updateIncome();
                }else{
                    turnCount++;
                }
                money += income;
                if(ansMoney < money + income * (800 - turnCount)){
                    ansMoney = money + income * (800 - turnCount);
                    ansSt = ans;
                }
            }

            if(turnCount >= 700) return;
        }
    }
};


int main(){
    solve s;
    s.input();
    solve c = s;
    solve c2;
    usedStation.resize(s.m,false);
    //ansSt = s.ans;

    auto timer = clock();

    vector<int> di(6);
    di[0] = pow(dx2.size(),5);
    rep(i,5){
        di[i+1] = di[i] / dx2.size();
    }

    int i = 0;
    
    while(clock() - timer < 2.9 * CLOCKS_PER_SEC){
        int j = i / di[0];
        int k = (i - j * di[0]) / di[1];
        int l = (i - j * di[0] - k * di[1]) / di[2];
        int m = (i - j * di[0] - k * di[1] - l * di[2]) / di[3];
        int n = (i - j * di[0] - k * di[1] - l * di[2] - m * di[3]) / di[4];
        int o = (i - j * di[0] - k * di[1] - l * di[2] - m * di[3] - n * di[4]) / di[5];
        //cout << clock() - timer << endl;
        if(n == 0 && o == 0){
            s = c;
            s.selectFirstStation(dx2[j],dy2[k],dx2[l],dy2[m]);
            c2 = s;
        }
        s = c2;
        s.selectSecondStation(n,o);
        s.money += s.income * (800 - s.turnCount);
        if(ansMoney < s.money){
            ansMoney = s.money;
            ansSt = s.ans;
        }
        
        i++;
        if(i == dx2.size() * di[0]){
            usedFirstStation[FirstStation] = true;
            i = 0;
        }
    }
    
    

   //s.selectFirstStation(0,0,0,0);
   //s.selectSecondStation(0,0);
   //ansSt = s.ans;
   //ansMoney = s.money + s.income * (800 - s.turnCount);

   //cout << "# " << ansMoney << endl;
    rep(i,800){
        cout << ansSt[i] << endl;
    }
    return 0;
}