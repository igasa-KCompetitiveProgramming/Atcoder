#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count_valid_combinations(int N, int K, int M, const vector<vector<int>>& tests, const vector<char>& results) {
    int valid_count = 0;
    int total_combinations = 1 << N; // 2^N

    for (int mask = 0; mask < total_combinations; ++mask) {
        bool is_valid = true;

        for (int i = 0; i < M; ++i) {
            int correct_key_count = 0;
            for (int key : tests[i]) {
                if (mask & (1 << (key - 1))) { // 正しい鍵かどうかをビットマスクで確認
                    correct_key_count++;
                }
            }

            if ((results[i] == 'o' && correct_key_count < K) || (results[i] == 'x' && correct_key_count >= K)) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            valid_count++;
        }
    }

    return valid_count;
}

int main() {
    int N = 3, K = 2, M = 3;
    vector<vector<int>> tests = {
        {1, 2},
        {2, 3},
        {1, 3}
    };
    vector<char> results = {'x', 'o', 'x'};

    int result = count_valid_combinations(N, K, M, tests, results);
    cout << result << endl; // 結果を出力

    return 0;
}
