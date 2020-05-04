// atcoder/cf16-final/D/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vec<int> x(n);
    cin >> x;

    map<int, int> freq;
    each (i, x) ++freq[i];

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    map<int, vec<int>> y;
    each (i, x) y[i % m].push_back(freq[i]);

    each (i, x) i %= m;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    map<int, int> z;
    each (i, y) each (j, i.second) z[i.first] += j;

    int r = (z[0] / 2);
    z.erase(0);
    y.erase(0);
    if (m % 2 == 0) {
      r += (z[m / 2] / 2);
      z.erase(m / 2);
      y.erase(m / 2);
    }

    each (_i, x) {
      if (_i == 0 || _i * 2 == m) continue;
      int i = _i;
      int j = m - _i;
      unless (z[i] < z[j]) swap(i, j);
      int p = (z[j] - z[i]) / 2;
      r += z[i];
      z[j] -= z[i];
      z.erase(i);
      y.erase(i);
      each (k, y[j]) {
        int mn = min(p, k / 2);
        p -= mn;
        r += mn;
        z[j] -= mn * 2;
        k -= mn * 2;
      }
    }

    cout << r << endl;
  }

  return 0;
}
