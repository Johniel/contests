// atcoder/typical90/079/main.cpp
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
    int a[h][w];
    int b[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> b[i][j];
      }
    }
    lli z = 0;
    for (int i = 0; i + 1 < h; ++i) {
      for (int j = 0; j + 1 < w; ++j) {
        lli d = b[i][j] - a[i][j];
        z += abs(d);
        a[i][j] += d;
        a[i + 1][j] += d;
        a[i][j + 1] += d;
        a[i + 1][j + 1] += d;
      }
    }
    bool f = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        f = f && a[i][j] == b[i][j];
      }
    }
    if (f) {
      cout << "Yes" << endl;
      cout << z << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
