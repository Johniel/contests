// yukicoder/1944/main.cpp
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

  vec<lli> v(4);
  lli n;
  while (cin >> v >> n) {
    vec<lli> a({v[0], 0, 0, 0});
    map<pair<vec<lli>, lli>, lli> m;
    map<lli, pair<vec<lli>, lli>> rev;
    lli z = 0;
    for (lli i = 0; i <= n; ++i) {
      z = i;
      pair<vec<lli>, lli> p = make_pair(a, i % 4);
      if (m.count(p)) {
        z = m[p] + (n - m[p]) % (i - m[p]);
        assert(rev.count(z));
        break;
      }
      m[p] = i;
      rev[i] = p;
      const int j = i % a.size();
      const int k = (j + 1) % a.size();
      lli mn = min(a[j], v[k] - a[k]);
      a[j] -= mn;
      a[k] += mn;
    }
    each (i, rev[z].first) cout << i << ' '; cout << endl;
  }

  return 0;
}
