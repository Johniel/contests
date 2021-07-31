// atcoder/arc124/C/main.cpp
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

inline vec<lli> f(lli n)
{
  vec<lli> v;
  for (lli i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  return v;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    vec<lli> a = f(v.front().first);
    vec<lli> b = f(v.front().second);

    lli mx = 0;
    each (i, a) {
      each (j, b) {
        lli x = i;
        lli y = j;
        lli z = x * y / __gcd(x, y);
        unless (mx < z) continue;
        bool f = true;
        each (k, v) {
          if (k.first % i == 0 && k.second % j == 0) {
            x = __gcd(x, k.first);
            y = __gcd(y, k.second);
          } else if (k.second % i == 0 && k.first % j == 0) {
            x = __gcd(x, k.second);
            y = __gcd(y, k.first);
          } else {
            f = false;
            break;
          }
        }
        if (f) setmax(mx, z);
      }
    }
    cout << mx << endl;
  }

  return 0;
}
