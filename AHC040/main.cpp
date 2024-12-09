#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define v(a,i,b) vector<ll> a(i,b)
#define vv(a,i,j,b) vector<vector<ll>> a(i, vector<ll>(j,b))
#define vp(a,i,b,c) vector<pll>> a(i,{b,c})
#define vvp(a,i,j,b,c) vector<vector<pll>> a(i, vector<>>(j,{b,c}))

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
map<string,ll> patternMap;

ll countPrint = 0;
ll t;
ll IdealLength = 0;

bool flag = false;

int timer;
class RectanglePlacement {
private:
    vector<vector<ll>> wh; // Rectangle dimensions
    vector<vector<ll>> resultHW;
    vector<tuple<ll, ll, char, ll>> ans; // Final result
    vector<pll> rectangleInfo; // Info about each rectangle
    set<tuple<ll, ll, ll, ll>> heightInfo; // Tracks heights
    ll n, idealLength;
    ll maxH = 0; ll maxW = 0;

    ll improveCount = 0;

    vector<ll> leftSideRectangle;

    bool isInline(ll l, ll r, ll lx, ll rx) {
        return !(l > rx || r < lx);
    }

    ll findAboveHeight(ll l, ll r) {
        //cout << "# start above height" << endl;
        auto it = heightInfo.end();
        while (true) {
            if (it == heightInfo.begin()) break;
            it--;
            if (isInline(l+1, r, get<1>(*it), get<2>(*it))) return get<3>(*it);
        }
        return -1;
    }

    void pushbackRoute(vector<tuple<ll, ll, char, ll>> &route, ll i, ll j, bool isTurn, ll &sumH, ll &avrNum, ll w, ll h, ll &length) {
        route.push_back({i, isTurn, 'U', j});
        sumH += h;
        avrNum++;
        length += w;
        ll aboveHeight = 0;

        if(j == -1){
            aboveHeight = findAboveHeight(0, w);
            rectangleInfo[i] = {w, h + rectangleInfo[aboveHeight].se};
            heightInfo.insert({h + rectangleInfo[aboveHeight].se, 0, w, i});
        }else{
            //cout << i << spa << j << endl;
            aboveHeight = findAboveHeight(rectangleInfo[j].first + 1, rectangleInfo[j].first + w);
            //cout << "# finish above height" << endl;
            if(aboveHeight == -1){
                rectangleInfo[i] = {w + rectangleInfo[j].first, h};
                heightInfo.insert({h, rectangleInfo[j].first+1, rectangleInfo[j].first + w, i});
            }else{
                rectangleInfo[i] = {w + rectangleInfo[j].first, h + rectangleInfo[aboveHeight].second};
                heightInfo.insert({h + rectangleInfo[aboveHeight].second, rectangleInfo[j].first+1, rectangleInfo[j].first + w, i});
            }
        }
        maxW = max(maxW, rectangleInfo[i].first);
        maxH = max(maxH, rectangleInfo[i].second);
    }

    void makeFirstRoute() {
        vector<tuple<ll, ll, char, ll>> route;
        route.push_back({0, 0, 'U', -1});
        ll wideLength = wh[0][0];
        ll sumH = wh[0][1], avrNum = 1;
        rectangleInfo[0] = {wh[0][0], wh[0][1]};
        heightInfo.insert({wh[0][1], 0, wh[0][0], 0});

        for (ll i = 1; i < n; ++i) {
            ll avr = sumH / avrNum;
            if (wideLength >= idealLength) {
                route.push_back({i, 0, 'U', -1});
                leftSideRectangle.push_back(i);
                wideLength = wh[i][0];
                sumH = wh[i][1];
                avrNum = 1;
                ll aboveHeight = findAboveHeight(0, wh[i][0]);
                
                rectangleInfo[i] = {wh[i][0], wh[i][1] + rectangleInfo[aboveHeight].se};
                heightInfo.insert({wh[i][1] + rectangleInfo[aboveHeight].se, 0, wh[i][0], i});
                continue;
            }
            if (abs(avr - wh[i][0]) < abs(avr - wh[i][1])) {
                pushbackRoute(route, i, i-1, false, sumH, avrNum, wh[i][0], wh[i][1], wideLength);
            } else {
                pushbackRoute(route, i, i-1, true, sumH, avrNum, wh[i][1], wh[i][0], wideLength);
            }
        }
        ans = route;
    }

    void improveAnswer(){
        ll maxSumResult = maxH + maxW;
        vector<ll> lateMaxHW = {maxH, maxW};
        maxH = 0; maxW = 0;
        rectangleInfo.clear();
        heightInfo.clear();
        rectangleInfo.resize(n, {0, 0});
        ll fullWideLengthIndex = 0;

        vector<ll> newLeftSideRectangle;
        newLeftSideRectangle.push_back(0);
        ll minRand = 1; ll sumHeight = wh[0][1];
        string pattern;
        while((clock() - timer) / (long double)CLOCKS_PER_SEC < 2.8){
            pattern.clear();
            newLeftSideRectangle.clear(); newLeftSideRectangle.push_back(0);
            minRand = 1; sumHeight = wh[0][1];
            rep(leftSideRectangle.size()){
                //minRandからleftSideRectangle[i]までの乱数を生成
                ll randNum = rand() % (leftSideRectangle[i] - minRand - 1) + minRand + 1;
                if(randNum < 10) pattern += "0" + to_string(randNum);
                else pattern += to_string(randNum);
                newLeftSideRectangle.push_back(randNum);
                sumHeight += wh[randNum][1];
                minRand = leftSideRectangle[i];
                if(sumHeight > lateMaxHW[0]){
                    break;
                }
            }
            //cout << pattern << spa;
            if(patternMap[pattern] == -1) continue;
            else{
                patternMap[pattern] = -1;
                break;
            }
        }
        //cout << "here" << endl;

        vector<tuple<ll, ll, char, ll>> route;
        route.push_back({0, 0, 'U', -1});
        vector<ll> wideLengths;
        vector<ll> sumHeights, avrNums;
        vector<ll> selectLeftSideRectangle;
        bool doTurn = false;
        if(wh[0][0] > wh[0][1]) doTurn = true;
        if(turn < t/2) doTurn = !doTurn;
        wideLengths.pb(wh[0][doTurn]);
        sumHeights.pb(wh[0][!doTurn]); avrNums.pb(1);
        rectangleInfo[0] = {wh[0][doTurn], wh[0][!doTurn]};
        heightInfo.insert({wh[0][!doTurn], 0, wh[0][doTurn], 0});
        selectLeftSideRectangle.push_back(0);

        ll leftSideRectangleIndex = 1;

        //cout << "# ";
        //O(newLeftSideRectangle);


        rep(i,1,n){
            if(max(maxH, maxW) > (long double)idealLength * 1.3) return;
            if(newLeftSideRectangle[leftSideRectangleIndex] == i){
                //if((ll)((long double)wideLengths[wideLengths.size() - 1] / 1.5) < min(wh[i][0],wh[i][1])){
                  //  newLeftSideRectangle[leftSideRectangleIndex]++;
                //}else{
                    route.push_back({i, 0, 'U', -1});
                    selectLeftSideRectangle.push_back(i);
                    leftSideRectangleIndex++;
                    if(wh[i][0] > wh[i][1]) doTurn = true;
                    if(turn < n/2) doTurn = !doTurn;
                    wideLengths.pb(wh[i][doTurn]);
                    sumHeights.pb(wh[i][!doTurn]); avrNums.pb(1);
                    ll aboveHeight = findAboveHeight(0, wh[i][doTurn]);
                    rectangleInfo[i] = {wh[i][doTurn], wh[i][!doTurn] + rectangleInfo[aboveHeight].se};
                    heightInfo.insert({wh[i][!doTurn] + rectangleInfo[aboveHeight].se, 0, wh[i][doTurn], i});
                    continue;
            //    }
            }

            ll minDifference = inf;
            ll minIndex = -1;
            bool isTurn = false;

            //cout << "# ";

            rep(j,selectLeftSideRectangle.size()){
                if(wideLengths[j] >= lateMaxHW[0]) continue;
                if(wideLengths[j] >= idealLength) continue;
                if(j != 0) if(wideLengths[j] + wh[i][0] > wideLengths[j-1]) continue;
                ll avr = sumHeights[j] / avrNums[j];
                rep(k,2){
                    if(abs(avr - wh[i][k]) < minDifference){
                        minDifference = abs(avr - wh[i][k]);
                        minIndex = j;
                        isTurn = k;
                    }
                }
            }
            
            //cout << "# " << i << spa << minIndex << spa << selectLeftSideRectangle.size() << endl;

            if(minIndex == -1){
                route.push_back({i, 0, 'U', -1});
                leftSideRectangleIndex++;
                selectLeftSideRectangle.push_back(i);

                wideLengths.pb(wh[i][0]);
                sumHeights.pb(wh[i][1]); avrNums.pb(1);
                ll aboveHeight = findAboveHeight(0, wh[i][0]);
                rectangleInfo[i] = {wh[i][0], wh[i][1] + rectangleInfo[aboveHeight].se};
                heightInfo.insert({wh[i][1] + rectangleInfo[aboveHeight].se, 0, wh[i][0], i});
                maxH = max(maxH, rectangleInfo[i].second);
                maxW = max(maxW, rectangleInfo[i].first);
                continue;
            }

            if(wh[i][0] < wh[i][1]) isTurn = true;
            else isTurn = false;

            pushbackRoute(route, i, selectLeftSideRectangle[minIndex], isTurn, sumHeights[minIndex], avrNums[minIndex], wh[i][isTurn], wh[i][!isTurn], wideLengths[minIndex]);
            
            //cout << "# finish pushbackRoute" << endl;
            
            maxH = max(maxH, rectangleInfo[i].second);
            maxW = max(maxW, rectangleInfo[i].first);
            selectLeftSideRectangle[minIndex] = i;
        }

        ll sumResult = maxH + maxW;
        //cout << maxSumResult << spa << sumResult << spa << maxH << spa << maxW << endl;
        if(sumResult < maxSumResult){
            //improveCount++;
            maxSumResult = sumResult;
            ans = route;
            if(turn > 1) printResult(1);
        }else{
            maxH = lateMaxHW[0];
            maxW = lateMaxHW[1];
            //if(turn > t/4){
              //  ans = route;
                //maxH = lateMaxHW[0];
                //maxW = lateMaxHW[1];
                //printResult(1);
            //}
        }
    }

public:
    ll turn;
    RectanglePlacement(ll n, ll t, vector<vector<ll>> dimensions) : n(n), wh(dimensions) {
        turn = t;
        resultHW.resize(n, vector<ll>(2));
        rectangleInfo.resize(n);
        idealLength = 0;
        for (const auto &dim : wh) {
            idealLength += dim[0] * dim[1];
        }
        idealLength = sqrt(idealLength);
        IdealLength = idealLength;
        idealLength *= (long double)1 + 0.2 * (((long double)n - (long double)30)/(long double)100);
        //cout << idealLength << endl;
    }

    void compute() {
        makeFirstRoute();
    }

    void inproving(){
        //if(flag) idealLength = IdealLength;
        //else idealLength = IdealLength * (long double)1 + 0.2 * (((long double)n - (long double)30)/(long double)100);
        improveAnswer();
    }

    void printResult(ll t) {
        turn--;
        //cout << "# " << maxW << spa << maxH << spa << maxW + maxH << endl;
        /*rep(rectangleInfo.size()) {
            cout << "# " << rectangleInfo[i].first << " " << rectangleInfo[i].second << endl;
        }*/
        rep(t){
            cout << n << endl;
            for (const auto &[i, j, c, p] : ans) {
                cout << i << " " << j << " " << c << " " << p << endl;
            }
        }
    }
};

int main() {
    timer = clock();
    LL(n,cint,sgm);
    t = cint;
    vector<vector<ll>> dimensions(n, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> dimensions[i][0] >> dimensions[i][1];
    }

    RectanglePlacement rp(n, t, dimensions);
    rp.compute();
    rp.printResult(1);
    while((clock() - timer) / (long double)CLOCKS_PER_SEC < 2.8){
        rp.inproving();
    }

    if(rp.turn > 0) rp.printResult(rp.turn);

    return 0;
}
