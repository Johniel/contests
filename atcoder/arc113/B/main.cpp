// atcoder/arc113/B/main.cpp
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

lli p(lli n, lli m, lli mod)
{
  if (m == 0) return 1;
  if (m == 1) return n;
  lli x = p(n, m / 2, mod);
  (x *= x) %= mod;
  if (m % 2) (x *= n) %= mod;
  return x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli a, b, c;
  while (cin >> a >> b >> c) {
    if (b == 0 && c == 0) {
      cout << a%10 << endl;
      continue;
    }
    if (b == 0) {
      cout << 1 << endl;
      continue;
    }
    if (c == 0) {
      cout << a%10 << endl;
      continue;
    }

    vec<lli> v(10, -1);
    {
      lli n = a;
      for (int i = 0; i < 10; ++i) {
        n %= 10;
        v[i] = n;
        n *= a;
      }
    }
    map<lli, int> m;
    for (int i = 0; i < 10; ++i) {
      if (m.count(v[i])) break;
      if (v[i] == -1) break;
      m[v[i]] = i;
    }

    const lli cycle = m.size();
    lli y = p(b, c, cycle);
    cout << v[(y - 1 + cycle) % cycle] << endl;
  }

  return 0;
}
