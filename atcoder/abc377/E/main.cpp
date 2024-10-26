#include <iostream>
#include <vector>

using namespace std;

long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int N;
    long long K;
    while(
      cin >> N >> K){
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i]--; // 0 始まりに変換
    }

    vector<vector<int>> cycles;
    vector<bool> visited(N, false);

    // サイクルの検出
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            vector<int> cycle;
            int curr = i;
            do {
                visited[curr] = true;
                cycle.push_back(curr);
                curr = P[curr];
            } while (curr != i);
            cycles.push_back(cycle);
        }
    }

    vector<int> result(N);

    // 各サイクルでの位置の計算
    for (const auto& cycle : cycles) {
        int L = cycle.size();
        long long move = power_mod(2, K, L); // 2^K mod L
        for (int i = 0; i < L; ++i) {
            int new_pos = (i + move) % L;
            result[cycle[i]] = cycle[new_pos];
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] + 1 << " ";
    }
    cout << endl;
    }
    return 0;
}
