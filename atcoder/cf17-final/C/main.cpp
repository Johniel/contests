// atcoder/cf17-final/C/main.cpp
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
    vec<int> v(n);
    cin >> v;

    int g[25][25];
    for (int i = 0; i < 25; ++i) {
      for (int j = 0; j < 25; ++j) {
        int d = abs(i - j);
        g[i][j] = min(d, 24 - d);
      }
    }

    map<int, int> m;
    each (i, v) ++m[i];

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    const int inf = (1 << 29);
    int mx = 0;

    each (i, m) {
      if (2 < i.second) {
        mx = -1;
      }
    }
    if (mx == -1) {
      cout << 0 << endl;
      continue;
    }

    for (int bit = 0; bit < (1 << v.size()); ++bit) {
      vec<int> u;
      for (int i = 0; i < v.size(); ++i) {
        if (bit & (1 << i)) {
          u.push_back(+v[i]);
          if (1 < m[v[i]]) u.push_back(-v[i]);
        } else {
          u.push_back(-v[i]);
          if (1 < m[v[i]]) u.push_back(+v[i]);
        }
      }
      int mn = inf;
      for (int i = 0; i < u.size(); ++i) {
        setmin(mn, g[12][u[i] + 12]);
        for (int j = i + 1; j < u.size(); ++j) {
          setmin(mn, g[12 + u[i]][u[j] + 12]);
        }
      }
      setmax(mx, abs(mn));
    }

    cout << mx << endl;
  }

  return 0;
}