// atcoder/typical90/072/main.cpp
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

const int H = 16;
const int W = 16;
char g[H][W];
int h, w;
int vis[H][W];
int rec(int i, int j, int depth)
{
  vis[i][j] = depth;
  int mx = -1;
  for (int d = 0; d < 4; ++d) {
    const int ni = i + di[d];
    const int nj = j + dj[d];
    unless (0 <= ni && ni < h) continue;
    unless (0 <= nj && nj < w) continue;
    if (g[ni][nj] == '#') continue;
    if (vis[ni][nj] != -1) {
      const int x = depth - vis[ni][nj] + 1;
      if (3 < x) setmax(mx, x);
    } else {
      setmax(mx, rec(ni, nj, depth + 1));
    }
  }
  vis[i][j] = -1;
  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> h >> w) {
    fill(&vis[0][0], &vis[H - 1][W - 1] + 1, -1);
    fill(&g[0][0], &g[H - 1][W - 1] + 1, '#');
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int mx = -1;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') setmax(mx, rec(i, j, 0));
      }
    }
    cout << mx << endl;
  }

  return 0;
}
