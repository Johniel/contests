// atcoder/agc020/B/main.cpp
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

  int k;
  while (cin >> k) {
    vec<lli> a(k);
    cin >> a;
    reverse(a.begin(), a.end());

    lli x = 2;
    each (i, a) {
      if (x % i == 0) ;
      else x = ((x / i) + 1) * i;
    }

    lli y = 4;
    each (i, a) {
      if (y % i == 0) ;
      else y = ((y / i) + 1) * i;
    }
    --y;

    reverse(a.begin(), a.end());
    bool f = (a.back() == 2);
    {
      lli z = x;
      each (i, a) z = z - z % i;
      f = f && (z == 2);
    }
    {
      lli z = y;
      each (i, a) z = z - z % i;
      f = f && (z == 2);
    }

    if (f) cout << x << ' ' << y << endl;
    else cout << -1 << endl;
  }

  return 0;
}
