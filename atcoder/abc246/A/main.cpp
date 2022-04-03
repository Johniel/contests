// atcoder/abc246/A/main.cpp
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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  vec<pair<int, int>> v(3);
  while (cin >> v) {
    const int inf = 1 << 29;
    int mn_x = +inf;
    int mn_y = +inf;
    int mx_x = -inf;
    int mx_y = -inf;
    each (i, v) {
      setmin(mn_x, i.first);
      setmin(mn_y, i.second);
      setmax(mx_x, i.first);
      setmax(mx_y, i.second);
    }
    vec<pair<int, int>> u;
    u.push_back({mn_x, mn_y});
    u.push_back({mx_x, mn_y});
    u.push_back({mn_x, mx_y});
    u.push_back({mx_x, mx_y});
    each (i, u) {
      unless (count(v.begin(), v.end(), i)) {
        cout << i.first << ' ' << i.second << endl;
      }
    }
  }

  return 0;
}
