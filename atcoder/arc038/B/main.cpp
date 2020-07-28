// atcoder/arc038/B/main.cpp
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

const int H = 100 + 5;
const int W = 100 + 5;
char g[H][W];

int memo[H][W][2];
int rec(int i, int j, int p)
{
  int& ret = memo[i][j][p];
  if (ret != -1) return ret;

  int mx = 0;
  int di[] = {0, +1, +1};
  int dj[] = {+1, 0, +1};
  int cnt = 0;
  for (int d = 0; d < 3; ++d) {
    int ni = i + di[d];
    int nj = j + dj[d];
    if (g[ni][nj] == '.') {
      ++cnt;
      setmax(mx, rec(ni, nj, p^1)^1);
    }
  }
  if (cnt == 0) return 0;
  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    fill(&g[0][0], &g[H - 1][W - 1] + 1, '#');
    fill(&memo[0][0][0], &memo[H - 1][W - 1][2 - 1] + 1, -1);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    cout << (rec(0, 0, 0) ? "First" : "Second") << endl;
  }

  return 0;
}
