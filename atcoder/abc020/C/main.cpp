// atcoder/abc020/C/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  lli t;
  while (cin >> h >> w >> t) {
    pair<int, int> src;
    pair<int, int> dst;
    char g[10][10];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'G') dst = make_pair(i, j);
      }
    }

    auto fn = [&] (lli x) {
      lli cost[10][19];
      fill(&cost[0][0], &cost[9][9] + 1, 1e9+100);
      priority_queue<pair<lli, pair<int, int>>> q;
      q.push(make_pair(0, src));
      cost[src.first][src.second] = 0;
      while (q.size()) {
        auto p = q.top();
        q.pop();
        lli c = -1 * p.first;
        int i = p.second.first;
        int j = p.second.second;
        if (cost[i][j] != c) continue;
        for (int d = 0; d < 4; ++d) {
          int di[4] = {0, 0, -1, +1};
          int dj[4] = {-1, +1, 0, 0};
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          lli z = c + (g[ni][nj] == '#' ? x : 1LL);
          if (cost[ni][nj] > z) {
            cost[ni][nj] = z;
            q.push(make_pair(-1 * z, make_pair(ni, nj)));
          }
        }
      }

      return cost[dst.first][dst.second];
    };

    lli small = 1, large = 1e9 + 10;
    while (small + 1 < large) {
      lli mid = (small + large) / 2LL;
      if (fn(mid) < t) small = mid;
      else large = mid;
    }

    if (fn(large) <= t) cout << large << endl;
    else cout << small << endl;
  }

  return 0;
}
