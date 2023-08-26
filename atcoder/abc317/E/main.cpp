// github.com/Johniel/contests
// atcoder/abc317/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    const int H = 2000 + 3;
    const int W = 2000 + 3;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int di[] = {-1, 0, +1, 0};
    int dj[] = {0, +1, 0, -1};

    pair<int, int> src, dst;
    src = dst = make_pair(-1, -1);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'G') dst = make_pair(i, j);
      }
    }
    g[src.first][src.second] = '.';
    g[dst.first][dst.second] = '.';

    const int D = 4;
    static bool taboo[H][W];
    fill(&taboo[0][0], &taboo[H - 1][W - 1] + 1, false);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') continue;
        if (g[i][j] == '.') continue;
        int d = -1;
        if (g[i][j] == '^') d = 0;
        if (g[i][j] == '>') d = 1;
        if (g[i][j] == 'v') d = 2;
        if (g[i][j] == '<') d = 3;
        assert(d != -1);
        taboo[i][j] = true;
        for (int len = 1; ; ++len) {
          int ni = i + di[d] * len;
          int nj = j + dj[d] * len;
          unless (0 <= ni && ni < h) break;
          unless (0 <= nj && nj < w) break;
          // cout << make_pair(i, j) << ' ' << make_pair(ni, nj) << ' ' << g[ni][nj] << endl;
          if (g[ni][nj] == '.') {
            taboo[ni][nj] = true;
          } else {
            break;
          }
        }
      }
    }

    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) cout << taboo[i][j];
    //   cout << endl;
    // }

    static int cost[H][W];
    fill(&cost[0][0], &cost[H - 1][W - 1] + 1, -(H * W + 3));
    cost[src.first][src.second] = 0;

    queue<pair<int, int>> q;
    for (q.push(src); q.size(); q.pop()) {
      auto curr = q.front();
      for (int d = 0; d < 4; ++d) {
        auto [i, j] = curr;
        int ni = i + di[d];
        int nj = j + dj[d];
        // cout << make_pair(i, j) << ' ' << make_pair(ni, nj) << endl;
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        // cout << make_pair(i, j) << ' ' << make_pair(ni, nj) << ' ' << g[ni][nj] << ' ' << taboo[ni][nj] << endl;
        if (g[ni][nj] == '.' && cost[ni][nj] < 0 && !taboo[ni][nj]) {
          cost[ni][nj] = cost[i][j] + 1;
          q.push(make_pair(ni, nj));
        }
      }
    }

    if (cost[dst.first][dst.second] < 0) cout << -1 << endl;
    else cout << cost[dst.first][dst.second] << endl;
  }
  return 0;
}
