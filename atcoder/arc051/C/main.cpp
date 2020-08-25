// atcoder/arc051/C/main.cpp
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

namespace math {
  lli mod_pow(lli n, int p)
  {
    if (p == 0) return 1;
    if (p == 1) return n;
    lli m = mod_pow(n, p / 2);
    m *= m;
    m %= mod;
    if (p % 2) m = (m * n) % mod;
    return m;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli mul, times;
  int n;
  while (cin >> n >> mul >> times) {
    vec<lli> a(n);
    cin >> a;

    if (mul == 1) {
      sort(a.begin(), a.end());
      each (i, a) cout << i << endl;
      continue;
    }

    while (times) {
      sort(a.begin(), a.end());
      unless (a.front() * mul <= a.back()) break;
      a[0] *= mul;
      --times;
    }
    sort(a.begin(), a.end());

    vec<lli> b;
    each (i, a) {
      (i *= math::mod_pow(mul, times / a.size())) %= mod;
    }
    for (int i = times % a.size(); i < a.size(); ++i) {
      b.push_back(a[i]);
    }
    for (int i = 0; i < times % a.size(); ++i) {
      b.push_back(a[i] * mul % mod);
    }
    each (i, b) cout << i << endl;
  }

  return 0;
}
