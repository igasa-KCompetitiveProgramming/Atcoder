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

struct Point {
    double x, y, z;
};

struct Cube {
    Point p1, p2;
};

double calculate_overlap_volume(const Cube& cube1, const Cube& cube2) {
    // 各軸方向の重なりの範囲を計算
    double x_overlap = std::max(0.0, std::min(std::max(cube1.p1.x, cube1.p2.x), std::max(cube2.p1.x, cube2.p2.x)) - 
                                std::max(std::min(cube1.p1.x, cube1.p2.x), std::min(cube2.p1.x, cube2.p2.x)));
    double y_overlap = std::max(0.0, std::min(std::max(cube1.p1.y, cube1.p2.y), std::max(cube2.p1.y, cube2.p2.y)) - 
                                std::max(std::min(cube1.p1.y, cube1.p2.y), std::min(cube2.p1.y, cube2.p2.y)));
    double z_overlap = std::max(0.0, std::min(std::max(cube1.p1.z, cube1.p2.z), std::max(cube2.p1.z, cube2.p2.z)) - 
                                std::max(std::min(cube1.p1.z, cube1.p2.z), std::min(cube2.p1.z, cube2.p2.z)));
    
    // 重なる部分の体積を計算
    double overlap_volume = x_overlap * y_overlap * z_overlap;
    
    return overlap_volume;
}

bool is_overlap_volume_greater_or_equal_to_one(const Cube& cube1, const Cube& cube2) {
    return calculate_overlap_volume(cube1, cube2) >= 1.0;
}

int main() {
    vector<int> a(6);
    vector<int> b(6); 
    rep(i,6){
        cin >> a[i];
    }
    rep(i,6){
        cin >> b[i];
    }
    // 例として立方体の座標を設定
    Cube cube1 = {{a[0], a[1], a[2]}, {a[3], a[4], a[5]}};
    Cube cube2 = {{b[0], b[1], b[2]}, {b[3], b[4], b[5]}};
    
    if (is_overlap_volume_greater_or_equal_to_one(cube1, cube2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
