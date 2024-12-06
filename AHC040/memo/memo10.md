# 最強のコード、ついに超えられる

以下コード

```
ll countPrint = 0;
ll t;
ll avr = 0;

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
            //if(max(maxH, maxW) > avr + max(lateMaxHW[0], lateMaxHW[1])){
              //  return;
            //}
            if(newLeftSideRectangle[leftSideRectangleIndex] == i){
                route.push_back({i, 0, 'U', -1});
                selectLeftSideRectangle.push_back(i);
                leftSideRectangleIndex++;
                wideLengths.pb(wh[i][0]);
                sumHeights.pb(wh[i][1]); avrNums.pb(1);
                ll aboveHeight = findAboveHeight(0, wh[i][0]);
                rectangleInfo[i] = {wh[i][0], wh[i][1] + rectangleInfo[aboveHeight].se};
                heightInfo.insert({wh[i][1] + rectangleInfo[aboveHeight].se, 0, wh[i][0], i});
                continue;
            }

            ll minDifference = inf;
            ll minIndex = -1;
            bool isTurn = false;

            //cout << "# ";

            rrep(j,selectLeftSideRectangle.size()){
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
            if(turn > 0) printResult(1);
        }else{
            maxH = lateMaxHW[0];
            maxW = lateMaxHW[1];
            if(t - turn < t / 2){
                route = ans;
                maxH = lateMaxHW[0];
                maxW = lateMaxHW[1];
                printResult(1);
            }
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
    }

    void compute() {
        makeFirstRoute();
    }

    void inproving(){
        improveAnswer();
    }

    void printResult(ll t) {
        turn--;
        //cout << "# " << maxW << spa << maxH << spa << maxW + maxH << endl;
        /*rep(rectangleInfo.size()) {
            cout << "# " << rectangleInfo[i].first << " " << rectangleInfo[i].second << endl;
        }*/
        rep(t){
            countPrint++;
            cout << n << endl;
            for (const auto &[i, j, c, p] : ans) {
                cout << i << " " << j << " " << c << " " << p << endl;
            }
        }
    }
};

int main() {
    int timer = clock();
    LL(n,cint,sgm);
    t = cint;
    vector<vector<ll>> dimensions(n, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> dimensions[i][0] >> dimensions[i][1];
        avr += dimensions[i][0] + dimensions[i][1];
    }
    avr /= n*2;

    RectanglePlacement rp(n, t, dimensions);
    rp.compute();
    ll half = t/2;
    rp.printResult(1);
    while((clock() - timer) / (long double)CLOCKS_PER_SEC < 2.7){
        rp.inproving();
    }

    if(rp.turn > 0) rp.printResult(rp.turn);

    return 0;
}
```