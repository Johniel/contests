// atcoder/abc201/D/main.cpp
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

const int H = 2000 + 3;
const int W = 2000 + 3;

char g[H][W];

int memo[H][W];
const int inf = 1 << 29;
int h, w;
int rec(int i, int j)
{
  int& ret = memo[i][j];
  if (ret != inf) return ret;
  if (i == h - 1 && j == w - 1) return 0;
  int a = -inf;
  int b = -inf;
  if (i + 1 < h) {
    int s = g[i + 1][j] == '+' ? +1 : -1;
    a = -1 * rec(i + 1, j) + s;
  }
  if (j + 1 < w) {
    int s = g[i][j + 1] == '+' ? +1 : -1;
    b = -1 * rec(i, j + 1) + s;
  }
  if (a == -inf) return ret = b;
  if (b == -inf) return ret = a;
  return ret = max(a, b);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> h >> w) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    fill(&memo[0][0], &memo[H - 1][W - 1] + 1, inf);
    int f = rec(0, 0);
    if (f == 0) cout << "Draw" << endl;
    else if (f < 0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
  }

  return 0;
}
