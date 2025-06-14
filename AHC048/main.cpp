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

ll calcCount = 0;

struct Color {
    int r, g, b, index;

    int get(int dim) const {
        if (dim == 0) return r;
        if (dim == 1) return g;
        return b;
    }

    int distance2(const Color& other) const {
        int dr = r - other.r;
        int dg = g - other.g;
        int db = b - other.b;
        return dr * dr + dg * dg + db * db;
    }
};

struct KDNode {
    Color color;
    KDNode* left = nullptr;
    KDNode* right = nullptr;
    int axis;
};

KDNode* buildKDTree(std::vector<Color>& points, int depth = 0) {
    if (points.empty()) return nullptr;

    int axis = depth % 3;
    auto cmp = [axis](const Color& a, const Color& b) {
        return a.get(axis) < b.get(axis);
    };

    std::sort(points.begin(), points.end(), cmp);
    size_t mid = points.size() / 2;

    std::vector<Color> left_points(points.begin(), points.begin() + mid);
    std::vector<Color> right_points(points.begin() + mid + 1, points.end());

    KDNode* node = new KDNode{points[mid], nullptr, nullptr, axis};
    node->left = buildKDTree(left_points, depth + 1);
    node->right = buildKDTree(right_points, depth + 1);
    return node;
}

void nearestSearch(KDNode* node, const Color& target, Color& best, int& bestDist2) {
    if (!node) return;

    int d2 = target.distance2(node->color);
    if (d2 < bestDist2) {
        bestDist2 = d2;
        best = node->color;
    }

    int axis = node->axis;
    int delta = target.get(axis) - node->color.get(axis);
    KDNode* near = delta < 0 ? node->left : node->right;
    KDNode* far = delta < 0 ? node->right : node->left;

    nearestSearch(near, target, best, bestDist2);
    if (delta * delta < bestDist2) {
        nearestSearch(far, target, best, bestDist2);
    }
}

Color findNearest(KDNode* root, const Color& target) {
    Color best = root->color;
    int bestDist2 = target.distance2(best);
    nearestSearch(root, target, best, bestDist2);
    return best;
}

class SOLVE{
  public:
    ll paletSize,tubeSize,makeColorNum,maxTurn,cost;
    vector<tuple<ll, ll, ll>> palet;
    vector<tuple<ll, ll, ll>> target;
    int maximumTubeCapacity;
    KDNode* root;

    ll capa = 3000;
    vector<tuple<ll,ll,ll,vector<ll>>> canMakeColor;
    vector<vector<ll>> answer;
    vector<vector<ll>> finalAnswer;

    ll calcDist(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
        return (get<0>(a) - get<0>(b)) * (get<0>(a) - get<0>(b)) +
               (get<1>(a) - get<1>(b)) * (get<1>(a) - get<1>(b)) +
               (get<2>(a) - get<2>(b)) * (get<2>(a) - get<2>(b));
    }

    void input(int maximumTubeC){
        maximumTubeCapacity = maximumTubeC;
        cin >> paletSize >> tubeSize >> makeColorNum >> maxTurn >> cost;
        palet.resize(tubeSize);
        target.resize(makeColorNum);
        rep(i, tubeSize){
            double r_0, g_0, b_0;
            cin >> r_0 >> g_0 >> b_0;
            ll r = (ll)(r_0 * pow(10, 5));
            ll g = (ll)(g_0 * pow(10, 5));
            ll b = (ll)(b_0 * pow(10, 5));
            palet[i] = make_tuple(r, g, b);
        }
        rep(i, makeColorNum) {
            double r_0, g_0, b_0;
            cin >> r_0 >> g_0 >> b_0;
            ll r = (ll)(r_0 * pow(10, 5));
            ll g = (ll)(g_0 * pow(10, 5));
            ll b = (ll)(b_0 * pow(10, 5));
            target[i] = make_tuple(r, g, b);
        }
    }

    void makeBoard_equalWidth(){
        int width = maximumTubeCapacity;
        width--;
        rep(paletSize){
            int cnt = 0;
            rep(j, paletSize - 1){
                if(cnt == width){
                    cout << 1 << spa;
                    cnt = 0;
                }else{
                    cout << 0 << spa;
                    cnt++;
                }
            }
            cout << endl;
        }
        rep(paletSize - 1){
            rep(j, paletSize){
                cout << 1 << spa;
            }
            cout << endl;
        }
    }

    void dfs(int start, int depth, vector<ll>& selected, ll rSum, ll gSum, ll bSum) {
        if (selected.size() != 0) {
            // 全て同じ色なら除外
            bool allSame = true;
            for (int i = 1; i < selected.size(); i++) {
                if (selected[i] != selected[0]) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame || selected.size() == 1){
                ll rAvg = rSum / selected.size();
                ll gAvg = gSum / selected.size();
                ll bAvg = bSum / selected.size();
                canMakeColor.emplace_back(rAvg, gAvg, bAvg, selected);
            }
            if(selected.size() >= depth) {
                return;
            }
        }
        for (int i = start; i < tubeSize; i++){
            auto [r, g, b] = palet[i];
            selected.push_back(i);
            dfs(i, depth, selected, rSum + r, gSum + g, bSum + b);
            selected.pop_back();
        }
    }

    void makeCanMakeColor(){
        ll combinate = maximumTubeCapacity;

        vector<ll> selected;
        dfs(0, combinate, selected, 0.0, 0.0, 0.0);
    }

    void buildKDSearchTree(){
        vector<Color> colors;
        rep(i, canMakeColor.size()) {
            auto [r, g, b, indices] = canMakeColor[i];
            colors.push_back({ (int)r, (int)g, (int)b, (int)i });
        }
        root = buildKDTree(colors);
    }

    ll makeKDSerchTree(int debug){
        ll nowScore = 0;
        ll count1operate = 0;
        int tubeCounter = 0;

        vector<vector<pair<int,tuple<ll,ll,ll>>>> used(paletSize, vector<pair<int,tuple<ll,ll,ll>>>(paletSize, {0, {0, 0, 0}}));

        rep(i, makeColorNum) {
            if(i == 1000 - debug && debug != 0){
                capa = 100000;
            }
            if(1000 - i < tubeCounter && debug == 150){
                capa = 100000;
            }
            auto [r, g, b] = target[i];
            tuple<ll, ll, ll> targetCo = { r, g, b };
            Color targetColor = { (int)r, (int)g, (int)b, 0 };
            Color nearest = findNearest(root, targetColor);
            vector<ll> indices = get<3>(canMakeColor[nearest.index]);
            pll usedIndex = {-1, -1};
            ll minDist = inf;
            r = nearest.r;
            g = nearest.g;
            b = nearest.b;
            ll toTargetDist = calcDist(targetCo, {r, g, b});
            bool found = false;
            rep(j, used.size()){
                for(int k = 0; k < used[j].size(); k += maximumTubeCapacity){
                    calcCount++; // 0.75
                    auto [nr, ng, nb] = used[j][k].se;
                    if((nr == 0 && ng == 0 && nb == 0) || used[j][k].fi == 0) continue; // 未使用の色はスキップ
                    ll dist = calcDist({r, g, b}, used[j][k].se);
                    ll targetToDist = calcDist(targetCo, used[j][k].se);
                    if(toTargetDist > targetToDist) {
                        toTargetDist = targetToDist;
                        usedIndex = {j, k};
                        found = true;
                    }
                    if(found) continue;
                    if(dist < 3 * capa * capa){
                        if(dist < minDist){
                            minDist = dist;
                            usedIndex = {j, k};
                        }
                    }
                }
            }


            if(usedIndex.fi != -1 && usedIndex.se != -1) {
                auto [j, k] = usedIndex;
                pll paletIndex = {-1, -1};
                if(used[j][k].fi + 2 <= maximumTubeCapacity && capa != 100000) {
                    rep(j2,palet.size()){
                        rep(k2, palet.size()){
                            auto [nr, ng, nb] = palet[j2];
                            auto [ur, ug, ub] = used[j][k].se;
                            nr += get<0>(palet[k2]);
                            ng += get<1>(palet[k2]);
                            nb += get<2>(palet[k2]);
                            ur = (ur * used[j][k].fi + nr) / (used[j][k].fi + 2);
                            ug = (ug * used[j][k].fi + ng) / (used[j][k].fi + 2);
                            ub = (ub * used[j][k].fi + nb) / (used[j][k].fi + 2);
                            ll targetToDist = calcDist({ur, ug, ub}, targetCo);
                            if(toTargetDist > targetToDist) {
                                toTargetDist = targetToDist;
                                paletIndex = {j2, k2};
                            }
                        }
                    }
                }
                ll toTargetDist2 = toTargetDist;
                ll paletIndex2 = -1;
                if(used[j][k].fi <= maximumTubeCapacity) {
                    rep(l, palet.size()){
                        calcCount++; // 0.01
                        auto [nr, ng, nb] = palet[l];
                        auto [ur, ug, ub] = used[j][k].se;
                        ur = (ur * used[j][k].fi + nr) / (used[j][k].fi + 1);
                        ug = (ug * used[j][k].fi + ng) / (used[j][k].fi + 1);
                        ub = (ub * used[j][k].fi + nb) / (used[j][k].fi + 1);
                        ll targetToDist = calcDist({ur, ug, ub}, targetCo);
                        if(toTargetDist2 > targetToDist) {
                            toTargetDist2 = targetToDist;
                            paletIndex2 = l;
                        }
                    }
                }
                if(toTargetDist2 < toTargetDist) {
                    paletIndex = {-1, -1};
                }else if(toTargetDist2 > toTargetDist) {
                    paletIndex2 = -1;
                }
                if(paletIndex.fi != -1 && paletIndex.se != -1) {
                    answer.push_back({1, j, k, paletIndex.fi});
                    answer.push_back({1, j, k, paletIndex.se});
                    tubeCounter += 2;
                    count1operate += 2;
                    used[j][k].se = { 
                        (get<0>(used[j][k].se) * used[j][k].fi + get<0>(palet[paletIndex.fi]) + get<0>(palet[paletIndex.se])) / (used[j][k].fi + 2),
                        (get<1>(used[j][k].se) * used[j][k].fi + get<1>(palet[paletIndex.fi]) + get<1>(palet[paletIndex.se])) / (used[j][k].fi + 2),
                        (get<2>(used[j][k].se) * used[j][k].fi + get<2>(palet[paletIndex.fi]) + get<2>(palet[paletIndex.se])) / (used[j][k].fi + 2)
                    };
                    used[j][k].fi += 2;
                }

                if(paletIndex2 != -1 && paletIndex2 < palet.size()) {
                        answer.push_back({1, j, k, paletIndex2});
                        tubeCounter++;
                        count1operate++;
                        used[j][k].se = { 
                            (get<0>(used[j][k].se) * used[j][k].fi + get<0>(palet[paletIndex2])) / (used[j][k].fi + 1),
                            (get<1>(used[j][k].se) * used[j][k].fi + get<1>(palet[paletIndex2])) / (used[j][k].fi + 1),
                            (get<2>(used[j][k].se) * used[j][k].fi + get<2>(palet[paletIndex2])) / (used[j][k].fi + 1)
                        };
                        used[j][k].fi++;
                    }
                answer.push_back({2, j, k});
                tubeCounter--;
                used[j][k].fi--;
                ll tmpScore = calcDist(targetCo, used[j][k].se);
                nowScore += sqrt(tmpScore);
                continue;
            }
            pll point = {-1, -1};
            ll minimumUsedCount = inf;
            rep(j, used.size()){
                for(int k = 0; k < used[j].size(); k += maximumTubeCapacity){
                    calcCount++; // 0.5
                    if(k + maximumTubeCapacity > used[j].size()) {
                        continue;
                    }
                    if(used[j][k].fi < minimumUsedCount){
                        minimumUsedCount = used[j][k].fi;
                        point = {k, j};
                        if(used[j][k].fi == 0) {
                            break;
                        }
                    }
                }
            }
            rep(j, used[point.se][point.fi].fi) {
                answer.push_back({3, point.se, point.fi});
                tubeCounter--;
            }
            used[point.se][point.fi] = {0, {r, g, b}};
            for (ll index : indices) {
                answer.push_back({1, point.se, point.fi, index});
                tubeCounter++;
                count1operate++;
                used[point.se][point.fi].fi++;
            }
            answer.push_back({2, point.se, point.fi});
            tubeCounter--;
            used[point.se][point.fi].fi--;
            ll tmpScore = calcDist(targetCo, used[point.se][point.fi].se);
            nowScore += sqrt(tmpScore);
        }
        nowScore /= 10;
        nowScore += cost * (count1operate - makeColorNum);
        return nowScore;
    }

    void output(){
        rep(finalAnswer.size()){
            ll type = finalAnswer[i][0];
            if(type == 1) cout << type << spa << finalAnswer[i][1] << spa << finalAnswer[i][2] << spa << finalAnswer[i][3] << endl;
            else if(type == 2) cout << type << spa << finalAnswer[i][1] << spa << finalAnswer[i][2] << endl;
            else if(type == 3) cout << type << spa << finalAnswer[i][1] << spa << finalAnswer[i][2] << endl;
            else if(type == 4) cout << type << spa << finalAnswer[i][1] << spa << finalAnswer[i][2] << spa << finalAnswer[i][3] << spa << finalAnswer[i][4] << endl;
        }
    }
};

int main(){
    auto start = chrono::high_resolution_clock::now();
    SOLVE s,t;

    ll ans = inf;

    ll boardSize = 4;

    s.input(4);
    tuple<ll,ll,ll> bestColor = {-1,-1,-1};
    tuple<ll,ll,ll> lastIndex = {-1,-1,-1};

    for(int i = 2; i < 11; i++){
        calcCount = 0;
        s.maximumTubeCapacity = i;
        s.makeCanMakeColor();
        if(i == 2) continue;
        if(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() > 2600) {
            break;
        }
        s.buildKDSearchTree();
        ll res = inf;
        rep(j,100){
            if(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() > 2900) {
                    break;
                }
            rep(k,7){
                    // 2800msで終了
                    if(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() > 2900) {
                        break;
                    }
                    s.answer.clear();
                    s.capa = j * 50;
                    calcCount++;
                    res = s.makeKDSerchTree(k * 25);
                    if(s.answer.size() > s.maxTurn) {
                        res = inf;
                    }
                    if(res < ans) {
                        ans = res;
                        s.finalAnswer = s.answer;
                        boardSize = i;
                        bestColor = {i,j,k};
                    }
                    lastIndex = {i,j,k};
            }
        }
        if(i == get<0>(bestColor)) {
            s.answer.clear();
            s.capa = get<1>(bestColor) * 50;
            s.makeKDSerchTree(get<2>(bestColor) * 25);
            s.finalAnswer = s.answer;
        }
        if(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() > 2900) {
            break;
        }
        s.canMakeColor.clear();
    }
    s.maximumTubeCapacity = boardSize;
    s.makeBoard_equalWidth();
    s.output();
}