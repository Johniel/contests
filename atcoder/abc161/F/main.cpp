// atcoder/abc161/F/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  lli n;
  while (cin >> n) {
    set<lli> vis;
    for (lli i = 2; i * i <= n; ++i) {
      if ((n - 1) % i == 0) {
        vis.insert(i);
        vis.insert((n - 1) / i);
      }
    }

    for (lli i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        lli j = n / i;

        lli x = n; while (x % i == 0) x /= i;
        lli y = n; while (y % j == 0) y /= j;

        if (x % i == 1) vis.insert(i);
        if (y % j == 1) vis.insert(j);
      }
    }

    vis.insert(n);
    vis.insert(n - 1);
    vis.erase(1);
    // cout << "? " << vis << ", " << vis.size() << endl;

    cout << vis.size() << endl;

    // for (lli k = 2; k <= n; ++k) {
    //   lli x = n;
    //   while (k <= x) {
    //     if (x % k == 0) x /= k;
    //     else x -= k;
    //   }
    //   if (x == 1) cout << k << ", "<< vis.count(k) << endl;
    // }
    // cout << endl;
  }

  return 0;
}
