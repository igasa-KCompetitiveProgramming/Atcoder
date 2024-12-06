# 多少のバグは存在するもののスコア計算のできるコードが作成完了！！！！！

## これから実装が必要な部分

- 焼く(Uの順番決め)
  - BFSみたいなことしないですか？
  - 全段と比較して作ってしまう空白の大きさでごちゃごちゃするやつ
- 正直1周O(10^3)とかでできそうなコードなので10^4~5回せれるのはばかつよい
  - 1秒回そう！！！！！！

```
class RectanglePlacement {
private:
    vector<vector<ll>> wh; // Rectangle dimensions
    vector<vector<ll>> resultHW;
    vector<tuple<ll, ll, char, ll>> ans; // Final result
    vector<pll> rectangleInfo; // Info about each rectangle
    set<tuple<ll, ll, ll, ll>> heightInfo; // Tracks heights
    ll n, idealLength;
    ll maxH = 0; ll maxW = 0;

    bool isInline(ll l, ll r, ll lx, ll rx) {
        return !(l > rx || r < lx);
    }

    ll findAboveHeight(ll l, ll r) {
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
            aboveHeight = findAboveHeight(rectangleInfo[j].first + 1, rectangleInfo[j].first + w + 1);
            if(aboveHeight == -1){
                rectangleInfo[i] = {w + rectangleInfo[j].first + 1, h};
                heightInfo.insert({h, rectangleInfo[j].first + 1, rectangleInfo[j].first + w + 1, i});
            }else{
                rectangleInfo[i] = {w + rectangleInfo[j].first + 1, h + rectangleInfo[aboveHeight].second + 1};
                heightInfo.insert({h + rectangleInfo[aboveHeight].second + 1, rectangleInfo[j].first + 1, rectangleInfo[j].first + w + 1, i});
            }
            cout << "# " << rectangleInfo[i].first << " " << rectangleInfo[i].second << endl;
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

public:
    RectanglePlacement(ll n, vector<vector<ll>> dimensions) : n(n), wh(dimensions) {
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

    void printResult(ll t) {
        cout << "# " << maxW << spa << maxH << spa << maxW + maxH << endl;
        rep(rectangleInfo.size()) {
            cout << "# " << rectangleInfo[i].first << " " << rectangleInfo[i].second << endl;
        }
        rep(t){
            cout << ans.size() << endl;
            for (const auto &[i, j, c, p] : ans) {
                cout << i << " " << j << " " << c << " " << p << endl;
            }
        }
    }
};

int main() {
    LL(n,t,sgm);
    vector<vector<ll>> dimensions(n, vector<ll>(2));
    for (ll i = 0; i < n; ++i) {
        cin >> dimensions[i][0] >> dimensions[i][1];
    }

    RectanglePlacement rp(n, dimensions);
    rp.compute();
    rp.printResult(t);

    return 0;
}
```