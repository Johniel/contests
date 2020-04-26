// atcoder/code-festival-2015-quala/D/main.cpp
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

  lli n, m;
  while (cin >> n >> m) {
    vec<lli> v(m);
    cin >> v;
    sort(v.begin(), v.end());

    auto fn = [&] (lli x) {
      lli y = 1;
      each (i, v) {
        lli z = -1;
        // ->, <-, <-
        const lli a = x - abs(i - y);
        if (0 <= a) {
          setmax(z, i + a / 2 + 1);
        }
        // <-, ->, ->
        const lli b = x - abs(i - y) * 2;
        if (0 <= b) {
          setmax(z, i + b + 1);
        }
        if (i < y) {
          setmax(z, i + x + 1);
        }
        if (z == -1) return false;
        y = z;
      }
      return n < y;
    };

    lli small = 0;
    lli large = 3 * 1e9 + 5;
    while (small + 1 < large) {
      const lli mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(small)) cout << small << endl;
    else cout << large << endl;
  }

  return 0;
}
