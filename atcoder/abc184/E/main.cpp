// atcoder/abc184/E/main.cpp
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
  while (cin >> h >> w) {
    const int N = 2000 + 3;
    static char g[N][N];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    map<char, vec<pair<int, int>>> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.' || g[i][j] == '#') continue;
        m[g[i][j]].push_back(make_pair(i, j));
      }
    }

    // map<pair<int, int>, int> cost;
    const int inf = 1 << 28;
    static int cost[N][N];
    // fill(&cost[0][0], &cost[N - 1][N - 1] + 1, inf);

    const pair<int, int> src = m['S'].front();
    const pair<int, int> dst = m['G'].front();
    cost[src.first][src.second] = 1;

    queue<pair<int, int>> q;
    for (q.push(src); q.size(); q.pop()) {
      // cout << q.size() << endl;
      if (cost[dst.first][dst.second]) break;
      pair<int, int> curr = q.front();
      // cout << curr << endl;
      for (int d = 0; d < 4; ++d) {
        const int ni = curr.first + di[d];
        const int nj = curr.second + dj[d];
        auto next = make_pair(ni, nj);
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (cost[ni][nj]) continue;
        if (g[ni][nj] == '#') continue;
        cost[ni][nj] = cost[curr.first][curr.second] + 1;
        q.push(next);
      }
      char c = g[curr.first][curr.second];
      if (c != '.') {
        each (next, m[c]) {
          // if (cost.count(next)) continue;
          // if (cost[next.first][next.second] != inf) continue;
          if (cost[next.first][next.second]) continue;
          cost[next.first][next.second] = cost[curr.first][curr.second] + 1;
          q.push(next);
        }
      }
    }

    if (cost[dst.first][dst.second]) cout << cost[dst.first][dst.second] - 1 << endl;
    else cout << -1 << endl;
    // cout << (cost.count(dst) ? cost[dst] : -1) << endl;
    break;
  }

  return 0;
}
