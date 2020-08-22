// atcoder/abc176/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  pair<int, int> src, dst;
  while (cin >> h >> w >> src >> dst) {
    --src.first;
    --src.second;
    --dst.first;
    --dst.second;

    const int N = 1e3 + 5;
    static char g[N][N];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int inf = 1 << 29;
    static int cost[N][N];
    fill(&cost[0][0], &cost[N - 1][N - 1] + 1, inf);

    deque<pair<int, int>> q;
    cost[src.first][src.second] = 0;
    q.push_back(src);

    while (q.size()) {
      auto curr = q.front();
      q.pop_front();
      if (curr == dst) break;
      for (int i = -2; i <= +2; ++i) {
        for (int j = -2; j <= +2; ++j) {
          int ni = curr.first + i;
          int nj = curr.second + j;
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == '#') continue;

          int x;
          if (abs(i) + abs(j) == 1) {
            x = 0;
          } else {
            x = 1;
          }
          if (cost[ni][nj] > cost[curr.first][curr.second] + x) {
            cost[ni][nj] = cost[curr.first][curr.second] + x;
            if (x) {
              q.push_back({ni, nj});
            } else {
              q.push_front({ni, nj});
            }
          }
        }
      }
    }

    cout << (cost[dst.first][dst.second] == inf ? -1 : cost[dst.first][dst.second]) << endl;
  }

  return 0;
}
