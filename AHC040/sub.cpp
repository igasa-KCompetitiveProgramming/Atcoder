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
            if (isInline(l, r, get<1>(*it), get<2>(*it))) return get<3>(*it);
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
            rectangleInfo[i] = {w, h + aboveHeight + 1};
            heightInfo.insert({h + aboveHeight + 1, 0, w + 1, i});
        }else{
            //cout << i << spa << j << endl;
            aboveHeight = findAboveHeight(rectangleInfo[j].first + 1, rectangleInfo[j].first + w + 1);
            //cout << "# finish above height" << endl;
            if(aboveHeight == -1){
                rectangleInfo[i] = {w + rectangleInfo[j].first + 1, h};
                heightInfo.insert({h, rectangleInfo[j].first + 1, rectangleInfo[j].first + w + 1, i});
            }else{
                rectangleInfo[i] = {w + rectangleInfo[j].first + 1, h + rectangleInfo[aboveHeight].second + 1};
                heightInfo.insert({h + rectangleInfo[aboveHeight].second + 1, rectangleInfo[j].first + 1, rectangleInfo[j].first + w + 1, i});
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
            if (wideLength > idealLength) {
                route.push_back({i, 0, 'U', -1});
                leftSideRectangle.push_back(i);
                wideLength = wh[i][0];
                sumH = wh[i][1];
                avrNum = 1;
                ll aboveHeight = findAboveHeight(0, wh[i][0]);
                rectangleInfo[i] = {wh[i][0], wh[i][1] + aboveHeight};
                heightInfo.insert({wh[i][1] + aboveHeight, 0, wh[i][0], i});
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

    void improveAnswer(ll count){
        rectangleInfo.clear();
        heightInfo.clear();
        rectangleInfo.resize(n, {0, 0});
        
        ll maxSumResult = maxH + maxW;
        vector<ll> lateMaxHW = {maxH, maxW};
        maxH = 0; maxW = 0;

        vector<ll> newLeftSideRectangle;
        newLeftSideRectangle.push_back(0);
        ll minRand = 1; ll sumHeight = wh[0][1];
        rep(leftSideRectangle.size()){
            //minRandからleftSideRectangle[i]までの乱数を生成
            ll randNum = rand() % (leftSideRectangle[i] - minRand) + minRand;
            newLeftSideRectangle.push_back(randNum);
            sumHeight += wh[randNum][1];
            minRand = randNum + 1;
            if(sumHeight > lateMaxHW[0]){
                break;
            }
        }

        vector<tuple<ll, ll, char, ll>> route;
        route.push_back({0, 0, 'U', -1});
        vector<ll> wideLengths;
        vector<ll> sumHeights, avrNums;
        vector<ll> selectLeftSideRectangle;
        wideLengths.pb(wh[0][0]);
        sumHeights.pb(wh[0][1]); avrNums.pb(1);
        rectangleInfo[0] = {wh[0][0], wh[0][1]};
        heightInfo.insert({wh[0][1], 0, wh[0][0], 0});
        selectLeftSideRectangle.push_back(0);

        ll leftSideRectangleIndex = 1;

        //cout << "# ";
        //O(newLeftSideRectangle);


        rep(i,1,n){
            if(newLeftSideRectangle[leftSideRectangleIndex] == i){
                route.push_back({i, 0, 'U', -1});
                selectLeftSideRectangle.push_back(i);
                leftSideRectangleIndex++;
                wideLengths.pb(wh[i][0]);
                sumHeights.pb(wh[i][1]); avrNums.pb(1);
                ll aboveHeight = findAboveHeight(0, wh[i][0]);
                rectangleInfo[i] = {wh[i][0], wh[i][1] + aboveHeight};
                heightInfo.insert({wh[i][1] + aboveHeight, 0, wh[i][0], i});
                continue;
            }

            ll minDifference = inf;
            ll minIndex = -1;
            bool isTurn = false;

            //cout << "# ";

            rep(j,selectLeftSideRectangle.size()){
                if(wideLengths[j] + wh[i][0] > lateMaxHW[0]) continue;
                if(wideLengths[j] > idealLength) continue;
                if(j != 0) if(wideLengths[j] + wh[i][0] > wideLengths[j-1]) continue;
                ll avr = sumHeights[j] / avrNums[j];
                minIndex = j;
                isTurn = rand() % 2;
                break;
            }
            
            //cout << "# " << i << spa << minIndex << spa << selectLeftSideRectangle.size() << endl;

            if(minIndex == -1){
                route.push_back({i, 0, 'U', -1});
                leftSideRectangleIndex++;
                selectLeftSideRectangle.push_back(i);

                wideLengths.pb(wh[i][0]);
                sumHeights.pb(wh[i][1]); avrNums.pb(1);
                ll aboveHeight = findAboveHeight(0, wh[i][0]);
                rectangleInfo[i] = {wh[i][0], wh[i][1] + aboveHeight};
                heightInfo.insert({wh[i][1] + aboveHeight, 0, wh[i][0], i});
                continue;
            }

            pushbackRoute(route, i, selectLeftSideRectangle[minIndex], isTurn, sumHeights[minIndex], avrNums[minIndex], wh[i][isTurn], wh[i][!isTurn], wideLengths[minIndex]);
            
            //cout << "# finish pushbackRoute" << endl;
            
            maxH = max(maxH, rectangleInfo[i].second);
            maxW = max(maxW, rectangleInfo[i].first);
            selectLeftSideRectangle[minIndex] = i;
        }

        ll sumResult = 0;
        sumResult = maxH + maxW;
        //cout << "# " << sumResult << spa << maxSumResult << endl;
        if(sumResult < maxSumResult){
            improveCount++;
            //cout << "# " << improveCount << endl;
            //cout << "# " << sumResult << spa << maxSumResult << endl;
            maxSumResult = sumResult;
            ans = route;
        }else{
            maxH = lateMaxHW[0];
            maxW = lateMaxHW[1];
        }
        
    }

public:
    RectanglePlacement(ll n, vector<vector<ll>> dimensions) : n(n), wh(dimensions) {
        resultHW.resize(n, vector<ll>(2));
        rectangleInfo.resize(n, {0, 0});
        idealLength = 0;
        for (const auto &dim : wh) {
            idealLength += dim[0] * dim[1];
        }
        idealLength = sqrt(idealLength);
    }

    void compute() {
        makeFirstRoute();
    }

    void inproving(ll count){
        improveAnswer(count);
    }

    void printResult(ll t) {
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
    int timer = clock();
    LL(n,t,sgm);
    vector<vector<ll>> dimensions(n, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> dimensions[i][0] >> dimensions[i][1];
    }

    RectanglePlacement rp(n, dimensions);
    rp.compute();
    ll improveCount = 0;
    while((clock() - timer) / (long double)CLOCKS_PER_SEC < 1.9){
        improveCount++;
        rp.inproving(improveCount);
    }
    //cout << "# ";
    //O(improveCount);
    rp.printResult(t);

    return 0;
}
