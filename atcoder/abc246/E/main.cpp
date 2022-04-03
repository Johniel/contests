// atcoder/abc246/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  pair<int, int> src, dst;
  while (cin >> n >> src >> dst) {
    --src.first;
    --src.second;
    --dst.first;
    --dst.second;
    const int N = 1500 + 3;
    static char g[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    const int D = 4;
    static int w[N][N][D];
    const int inf = 1 << 29;
    fill(&w[0][0][0], &w[N - 1][N - 1][D - 1] + 1, inf);
    deque<vec<int>> q;
    for (int d = 0; d < D; ++d) {
      q.push_back(vec<int>({src.first, src.second, d}));
      w[src.first][src.second][d] = 1;
    }
    for (; q.size(); ) {
      const auto v = q.front();
      q.pop_front();
      const int i = v[0];
      const int j = v[1];
      const int dir = v[2];
      for (int d = 0; d < D; ++d) {
        const int di[] = {-1, -1, +1, +1};
        const int dj[] = {-1, +1, -1, +1};
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < n) continue;
        unless (0 <= nj && nj < n) continue;
        if (g[ni][nj] == '#') continue;
        const lli c = (d != dir);
        const lli nw = w[i][j][dir] + c;
        if (w[ni][nj][d] > nw) {
          w[ni][nj][d] = nw;
          if (c) {
            q.push_back(vec<int>({ni, nj, d}));
          } else {
            q.push_front(vec<int>({ni, nj, d}));
          }
        }
      }
    }
    int mn = inf;
    for (int d = 0; d < D; ++d) {
      setmin(mn, w[dst.first][dst.second][d]);
    }
    if (mn == inf) mn = -1;
    cout << mn << endl;
  }

  return 0;
}
