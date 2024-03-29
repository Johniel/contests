// codeforces/777div2/C/main.cpp
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int h, w;
  while (cin >> h >> w) {
    const int H = 100 + 1;
    const int W = 100 + 1;
    int g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }

    if (g[0][0]) {
      cout << -1 << endl;
      continue;
    }

    vec<array<int, 4>> v;
    for (int i = h - 1; 0 <= i; --i) {
      for (int j = w - 1; 0 <= j; --j) {
        if (g[i][j]) {
          if (i) {
            v.push_back({i - 1, j, i, j});
          } else {
            v.push_back({i, j - 1, i, j});
          }
        }
      }
    }

    // reverse(v.begin(), v.end());
    cout << v.size() << endl;
    each (i, v) {
      cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] + 1 << ' ' << i[3] + 1 << endl;
    }
  }

  return 0;
}
