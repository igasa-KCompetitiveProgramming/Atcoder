#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
#include <cmath>

using namespace std;

typedef pair<int, int> Point;
typedef pair<Point, Point> Segment;

int sign(long long x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int orientation(const Point& a, const Point& b, const Point& c) {
    long long cross = (long long)(b.first - a.first) * (c.second - a.second) - 
                      (long long)(b.second - a.second) * (c.first - a.first);
    return sign(cross);
}

bool checker(const Segment& seg1, const Segment& seg2) {
    Point p1 = seg1.first;
    Point p2 = seg1.second;
    Point q1 = seg2.first;
    Point q2 = seg2.second;

    // 端点一致の数を数える
    int same_cnt = 0;
    if (p1 == q1) same_cnt++;
    if (p1 == q2) same_cnt++;
    if (p2 == q1) same_cnt++;
    if (p2 == q2) same_cnt++;

    if (same_cnt == 2) {
        // 両端が一致 → 同じ線分
        return true;
    }
    if (same_cnt == 1) {
        // 1点だけ一致 → 端点接触とみなして交差なし
        return false;
    }

    // バウンディングボックスで早期排除
    if (max(p1.first, p2.first) < min(q1.first, q2.first) ||
        max(q1.first, q2.first) < min(p1.first, p2.first) ||
        max(p1.second, p2.second) < min(q1.second, q2.second) ||
        max(q1.second, q2.second) < min(p1.second, p2.second)) {
        return false;
    }

    int o1 = orientation(p1, p2, q1);
    int o2 = orientation(p1, p2, q2);
    int o3 = orientation(q1, q2, p1);
    int o4 = orientation(q1, q2, p2);

    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

class Solver {
private:
    size_t kind_num;
    size_t machine_num;
    size_t machine_kind_num;
    vector<pair<Point, int>> machine_pos;
    vector<pair<Point, int>> goal_pos;
    vector<vector<double>> prob;
    vector<bool> used;
    vector<Segment> senbun;

public:
    Solver() : kind_num(0), machine_num(0), machine_kind_num(0) {}

    void input() {
        cin >> kind_num >> machine_num >> machine_kind_num;

        goal_pos.resize(kind_num);
        machine_pos.resize(machine_num);
        prob.assign(machine_kind_num, vector<double>(kind_num, 0.0));
        used.assign(machine_num, false);

        for (size_t i = 0; i < kind_num; i++) {
            int x, y;
            cin >> x >> y;
            goal_pos[i] = make_pair(make_pair(x, y), i + kind_num);
        }

        for (size_t i = 0; i < machine_num; i++) {
            int x, y;
            cin >> x >> y;
            machine_pos[i] = make_pair(make_pair(x, y), i + kind_num);
        }

        for (size_t i = 0; i < machine_kind_num; i++) {
            for (size_t j = 0; j < kind_num; j++) {
                cin >> prob[i][j];
            }
        }
    }

    int max_prob() {
        double m = 0.0;
        int index = -1;
        
        for (size_t i = 0; i < prob.size(); i++) {
            auto max_it = max_element(prob[i].begin(), prob[i].end());
            auto min_it = min_element(prob[i].begin(), prob[i].end());
            size_t max_idx = distance(prob[i].begin(), max_it);
            size_t min_idx = distance(prob[i].begin(), min_it);
            
            double tmp = prob[i][max_idx] + (1.0 - prob[i][min_idx]);
            if (tmp > m) {
                m = tmp;
                index = i;
            }
        }
        return index;
    }

    pair<int, int> correct_index(size_t index) {
        auto max_it = max_element(prob[index].begin(), prob[index].end());
        auto min_it = min_element(prob[index].begin(), prob[index].end());
        int max_idx = distance(prob[index].begin(), max_it);
        int min_idx = distance(prob[index].begin(), min_it);
        return make_pair(max_idx, min_idx);
    }

    int nearest_machine_position(int x, int y) {
        int distance = INT_MAX;
        int nearest_index = -1;
        
        for (size_t i = 0; i < machine_pos.size(); i++) {
            if (used[i]) continue;
            int d = abs(machine_pos[i].first.first - x) + abs(machine_pos[i].first.second - y);
            if (d < distance) {
                distance = d;
                nearest_index = i;
            }
        }
        return nearest_index;
    }

    void guess() {
        for (size_t i = 0; i < kind_num; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        int nearest_index = nearest_machine_position(0, 5000);
        cout << nearest_index + kind_num << endl;
        
        vector<tuple<int, int, int>> ans(machine_num, make_tuple(-1, -1, -1));
        int max_prob_index = max_prob();
        auto correct_index_result = correct_index(max_prob_index);
        ans[nearest_index] = make_tuple(max_prob_index, correct_index_result.first, correct_index_result.second);
        
        for (size_t i = 0; i < machine_num; i++) {
            if (get<0>(ans[i]) == -1) {
                cout << "-1" << endl;
            } else {
                cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
            }
        }
    }

    vector<double> next_prob(const vector<double>& now, size_t index) {
        vector<double> next(kind_num, 0.0);
        for (size_t i = 0; i < kind_num; i++) {
            next[i] = now[i] * prob[index][i];
        }
        return next;
    }

    double calculate_score(const vector<double>& now, const vector<double>& before) {
        double max_prob_0 = -1.0, max_prob_1 = -1.0;
        
        for (size_t i = 0; i < kind_num; i++) {
            if (now[i] > max_prob_0) {
                max_prob_0 = now[i];
            }
            if (before[i] - now[i] > max_prob_1) {
                max_prob_1 = before[i] - now[i];
            }
        }
        return max_prob_0 + max_prob_1;
    }

    tuple<int, int, int> random() {
        vector<double> probability(kind_num, 1.0);
        double max_score = 0.0;
        tuple<int, int, int> best_machine_kind = make_tuple(-1, -1, -1);
        
        for (size_t i = 0; i < machine_kind_num; i++) {
            vector<double> next = next_prob(probability, i);
            int max_index_0 = -1, max_index_1 = -1;
            double max_prob_val = 0.0;
            double max_sum;
            
            for (size_t j = 0; j < machine_kind_num; j++) {
                vector<double> tmp = next_prob(next, j);
                double score = calculate_score(tmp, next);
                if (score > max_prob_val) {
                    max_prob_val = score;
                    max_index_0 = j;
                }
            }
            max_sum = max_prob_val;
            max_prob_val = 0.0;
            
            vector<double> res(next.size());
            for (size_t k = 0; k < next.size(); k++) {
                res[k] = 1.0 - next[k];
            }
            
            for (size_t j = 0; j < machine_kind_num; j++) {
                vector<double> tmp = next_prob(res, j);
                double score = calculate_score(tmp, res);
                if (score > max_prob_val) {
                    max_prob_val = score;
                    max_index_1 = j;
                }
            }
            max_sum += max_prob_val;
            
            if (max_sum > max_score) {
                max_score = max_sum;
                best_machine_kind = make_tuple(i, max_index_0, max_index_1);
            }
        }
        return best_machine_kind;
    }

    pair<int, int> connect_machine(size_t index, vector<tuple<int, int, int>>& answer, int ans_index) {
        used[index] = true;
        int next_fi = nearest_machine_position(
            machine_pos[index].first.first,
            machine_pos[index].first.second
        );
        
        if (next_fi == -1) {
            return make_pair(-1, -1);
        }
        
        used[next_fi] = true;
        
        int next_se = nearest_machine_position(
            machine_pos[index].first.first,
            machine_pos[index].first.second
        );
        
        if (next_se == -1) {
            return make_pair(next_fi, -1);
        }
        
        used[next_se] = true;
        
        answer[index] = make_tuple(ans_index, next_fi + kind_num, next_se + kind_num);
        
        senbun.push_back(make_pair(
            machine_pos[index].first,
            machine_pos[next_fi].first
        ));
        senbun.push_back(make_pair(
            machine_pos[index].first,
            machine_pos[next_se].first
        ));
        
        return make_pair(next_fi, next_se);
    }

    bool is_valid(const vector<Segment>& senbun_vec, const vector<Segment>& index) {
        vector<Segment> copy = senbun_vec;
        for (const auto& seg : index) {
            for (const auto& copy_seg : copy) {
                if (checker(copy_seg, seg)) {
                    return false;
                }
            }
            copy.push_back(seg);
        }
        return true;
    }

    bool connect_goal(size_t index, vector<tuple<int, int, int>>& answer, int ans_index, 
                     const pair<int, int>& next_index, const tuple<int, int, int>& best_machine_kind, 
                     vector<pair<int, int>>& last_change) {
        for (size_t i = 0; i < kind_num; i++) {
            for (size_t j = 0; j < kind_num; j++) {
                for (size_t k = 0; k < kind_num; k++) {
                    for (size_t l = 0; l < kind_num; l++) {
                        if (i == j || i == k || i == l || j == k || j == l || k == l) {
                            continue;
                        }
                        
                        vector<Segment> tmp;
                        tmp.push_back(make_pair(
                            goal_pos[i].first,
                            machine_pos[next_index.first].first
                        ));
                        tmp.push_back(make_pair(
                            goal_pos[j].first,
                            machine_pos[next_index.first].first
                        ));
                        tmp.push_back(make_pair(
                            goal_pos[k].first,
                            machine_pos[next_index.second].first
                        ));
                        tmp.push_back(make_pair(
                            goal_pos[l].first,
                            machine_pos[next_index.second].first
                        ));

                        if (is_valid(senbun, tmp)) {
                            answer[next_index.first] = make_tuple(get<1>(best_machine_kind), i, j);
                            answer[next_index.second] = make_tuple(get<2>(best_machine_kind), k, l);
                            
                            last_change[0].first = i;
                            last_change[1].first = j;
                            last_change[2].first = k;
                            last_change[3].first = l;
                            
                            senbun.insert(senbun.end(), tmp.begin(), tmp.end());
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool final_check(const vector<Segment>& senbun_vec) {
        for (size_t i = 0; i < senbun_vec.size(); i++) {
            for (size_t j = 0; j < senbun_vec.size(); j++) {
                if (i == j) continue;
                if (checker(senbun_vec[i], senbun_vec[j])) {
                    return false;
                }
            }
        }
        return true;
    }

    void calculate_prob_with_indices(const pair<int, int>& index1, int index2, 
                                   vector<pair<int, int>>& last_change, size_t la) {
        vector<double> now(kind_num, 1.0);
        vector<double> next = next_prob(now, index1.first);
        
        if (index1.second == 1) {
            for (size_t i = 0; i < next.size(); i++) {
                next[i] = 1.0 - next[i];
            }
        }
        
        now = next_prob(next, index2);
        double max_prob_0 = -1.0, max_prob_1 = -1.0;
        int index_0 = -1, index_1 = -1;
        
        for (size_t i = 0; i < now.size(); i++) {
            if (max_prob_0 < now[i]) {
                max_prob_0 = now[i];
                index_0 = i;
            }
            if (max_prob_1 < next[i] - now[i]) {
                max_prob_1 = next[i] - now[i];
                index_1 = i;
            }
        }
        
        last_change[la].second = index_0;
        last_change[la + 1].second = index_1;
    }

    void test(const tuple<int, int, int>& best_machine_kind) {
        vector<pair<int, int>> last_change(4, make_pair(-1, -1));
        vector<tuple<int, int, int>> ans(machine_num, make_tuple(-1, -1, -1));
        int nearest_index = nearest_machine_position(0, 5000);
        
        if (nearest_index == -1) {
            guess();
            return;
        }
        
        size_t cnt = 0;

        while (true) {
            // 状態をリセット
            last_change.assign(4, make_pair(-1, -1));
            ans.assign(machine_num, make_tuple(-1, -1, -1));
            senbun.clear();
            used.assign(machine_num, false);
            
            senbun.push_back(make_pair(make_pair(0, 5000), machine_pos[nearest_index].first));
            
            pair<int, int> next_index = connect_machine(nearest_index, ans, get<0>(best_machine_kind));
            
            if (next_index.first != -1 && next_index.second != -1) {
                if (connect_goal(nearest_index, ans, get<0>(best_machine_kind), 
                               next_index, best_machine_kind, last_change)) {
                    if (final_check(senbun)) {
                        break;
                    }
                }
            }
            
            nearest_index = cnt;
            cnt++;
            if (cnt >= machine_num) {
                guess();
                return;
            }
        }

        calculate_prob_with_indices(make_pair(get<0>(best_machine_kind), 0), get<1>(best_machine_kind), last_change, 0);
        calculate_prob_with_indices(make_pair(get<0>(best_machine_kind), 1), get<2>(best_machine_kind), last_change, 2);

        vector<size_t> select(kind_num);
        for (size_t i = 0; i < kind_num; i++) {
            select[i] = i;
        }
        
        for (const auto& change : last_change) {
            if (change.first >= 0 && change.second >= 0) {
                size_t change_0 = change.first;
                size_t change_1 = change.second;
                if (change_0 < kind_num && change_1 < kind_num && select[change_0] != change_1) {
                    size_t tmp_idx = SIZE_MAX;
                    for (size_t j = 0; j < kind_num; j++) {
                        if (select[j] == change_1) {
                            tmp_idx = j;
                            break;
                        }
                    }
                    if (tmp_idx != SIZE_MAX) {
                        swap(select[change_0], select[tmp_idx]);
                    }
                }
            }
        }

        for (size_t i = 0; i < kind_num; i++) {
            cout << select[i] << " ";
        }
        cout << endl;
        cout << nearest_index + kind_num << endl;
        
        for (size_t i = 0; i < ans.size(); i++) {
            if (get<0>(ans[i]) == -1) {
                cout << "-1" << endl;
            } else {
                cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
            }
        }
    }
};

int main() {
    auto start = chrono::high_resolution_clock::now();
    Solver solver;
    solver.input();
    auto best_machine_kind_tuple = solver.random();
    solver.test(best_machine_kind_tuple);
    return 0;
}