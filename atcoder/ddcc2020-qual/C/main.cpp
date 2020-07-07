// atcoder/ddcc2020-qual/C/main.cpp
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

  int h, w, k;
  while (cin >> h >> w >> k) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int x[h][w];
    fill(&x[0][0], &x[h - 1][w - 1] + 1, 0);
    int y = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') x[i][j] = ++y;
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 1; j < w; ++j) {
        if (x[i][j] == 0) {
          x[i][j] =  x[i][j - 1];
        }
      }
      for (int j = w - 2; 0 <= j; --j) {
        if (x[i][j] == 0) {
          x[i][j] = x[i][j + 1];
        }
      }
    }
    for (int i = 1; i < h; ++i) {
      if (x[i][0] == 0) {
        for (int j = 0; j < w; ++j) {
          x[i][j] = x[i - 1][j];
        }
      }
    }
    for (int i = h - 2; 0 <= i; --i) {
      if (x[i][0] == 0) {
        for (int j = 0; j < w; ++j) {
          x[i][j] = x[i + 1][j];
        }
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (j) cout << ' ';
        cout << x[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
