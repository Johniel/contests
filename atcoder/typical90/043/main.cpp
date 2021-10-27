// atcoder/typical90/043/main.cpp
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
  int si, sj;
  int gi, gj;
  while (cin >> h >> w >> si >> sj >> gi >> gj) {
    --si;
    --sj;
    --gi;
    --gj;
    const int H = 1000 + 3;
    const int W = 1000 + 3;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    const int D = 4;
    static int cost[H][W][D];
    const int inf = 1 << 29;
    fill(&cost[0][0][0], &cost[H - 1][W - 1][D - 1] + 1, inf);
    deque<vec<int>> q;
    for (int d = 0; d < D; ++d) {
      cost[si][sj][d] = 0;
      q.push_back({si, sj, d});
    }
    while (q.size()) {
      auto v = q.front();
      q.pop_front();
      const int i = v[0];
      const int j = v[1];
      const int dir = v[2];
      for (int d = 0; d < D; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '#') continue;
        if (d == dir) {
          if (cost[ni][nj][d] > cost[i][j][dir]) {
            cost[ni][nj][d] = cost[i][j][dir];
            q.push_front({ni, nj, d});
          }
        } else {
          if (cost[ni][nj][d] > cost[i][j][dir] + 1) {
            cost[ni][nj][d] = cost[i][j][dir] + 1;
            q.push_back({ni, nj, d});
          }
        }
      }
    }
    int mn = 1 << 29;
    for (int d = 0; d < 4; ++d) {
      setmin(mn, cost[gi][gj][d]);
    }
    cout << mn << endl;
  }

  return 0;
}
