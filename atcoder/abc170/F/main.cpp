// atcoder/abc170/F/main.cpp
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

struct S {
  int i, j, d;
  pair<int, int> c;
};
bool operator < (S a, S b)
{
  return a.c > b.c;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, k;
  int si, sj, gi, gj;
  while (cin >> h >> w >> k >> si >> sj >> gi >> gj) {
    --si;
    --sj;
    --gi;
    --gj;
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int inf = 1 << 29;
    const int D = 4;
    pair<int, int> cost[h][w][D];
    fill(&cost[0][0][0], &cost[h - 1][w - 1][D - 1] + 1, make_pair(inf, 0));

    priority_queue<S> q;
    for (int d = 0; d < 4; ++d) {
      q.push({si, sj, d, cost[si][sj][d] = {0, 0}});
    }

    for (; q.size();) {
      auto s = q.top();
      q.pop();
      if (cost[s.i][s.j][s.d] != s.c) continue;
      for (int d = 0; d < 4; ++d) {
        int ni = s.i + di[d];
        int nj = s.j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '@') continue;
        pair<int, int> x = s.c;
        if (d == s.d) {
          ++x.second;
          x.first += x.second / k;
          x.second %= k;
        } else {
          x.first += !!x.second;
          x.second = 1;
        }
        if (cost[ni][nj][d] > x) {
          cost[ni][nj][d] = x;
          q.push({ni, nj, d, x});
        }
      }
    }

    int mn = inf;
    for (int d = 0; d < 4; ++d) {
      setmin(mn, cost[gi][gj][d].first + bool(cost[gi][gj][d].second));
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
