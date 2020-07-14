// atcoder/sumitrust2019/F/main.cpp
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

  lli t1, t2, a1, a2, b1, b2;
  while (cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2) {
    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
      cout << "infinity" << endl;
      continue;
    }

    lli x = a1 - b1;
    lli y = a2 - b2;
    if ((0 <= x && 0 <= y) || (x <= 0 && y <= 0)) {
      cout << 0 << endl;
      continue;
    }

    // cout << x << ' ' << y << endl;
    x *= t1;
    y *= t2;
    // cout << x << ' ' << y << endl;
    lli z = abs(abs(x) - abs(y));
    // cout << z << endl;
    // cout << abs(x) / z << endl;
    // cout << abs(y) / z << endl;
    if (abs(x) > abs(y)) {
      cout << "0" << endl;
      continue;
    }
    cout << abs(x) / z * 2 + bool(abs(x) % z) << endl;
  }

  return 0;
}
