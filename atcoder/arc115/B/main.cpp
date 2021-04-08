// atcoder/arc115/B/main.cpp
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

  int n;
  while (cin >> n) {
    int g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    vec<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
      int mn = 1 << 30;
      for (int j = 0; j < n; ++j) {
        setmin(mn, g[i][j]);
      }
      a[i] = mn;
    }

    bool f = true;

    vec<int> b(n, 0);
    for (int j = 0; j < n; ++j) {
      set<int> vis;
      for (int i = 0; i < n; ++i) {
        vis.insert(g[i][j] - a[i]);
      }
      if (vis.size() == 1) {
        b[j] = *vis.begin();
      } else {
        f = false;
      }
    }

    if (!f || *min_element(b.begin(), b.end()) < 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      each (i, a) cout << i << ' '; cout << endl;
      each (i, b) cout << i << ' '; cout << endl;
    }
  }

  return 0;
}
