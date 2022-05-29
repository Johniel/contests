// atcoder/abc253/E/main.cpp
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
constexpr lli mod = 998244353;

template<typename T = long long int>
struct BIT {
  vector<T> v;
  int n;

  BIT(int n_ = 0) {
    n = n_;
    v.resize(n + 1, 0);
  }

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      (s += v.at(i)) %= mod;
      i -= i & -i;
    }
    return s;
  }

  T operator () (int begin, int end) const {
    assert(begin <= end);
    return ((*this)(end) - (*this)(begin) + mod) % mod;
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      (v.at(i) += x) %= mod;
      i += i & -i;
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, k;
  while (cin >> n >> m >> k) {
    BIT<lli> curr(m+1);
    for (int i = 1; i <= m; ++i) curr.add(i, +1);
    for (int i = 0; i < n - 1; ++i) {
      BIT<lli> next(m+1);
      for (int j = 1; j <= m; ++j) {
        pair<lli, lli> p = make_pair(-1, -1);
        {
          lli mn = 1;
          lli mx = j - k;
          if (mn <= mx) {
            next.add(j, curr(mn, mx + 1));
          }
        }
        {
          lli mn = j + k;
          lli mx = m;
          if (mn <= mx) {
            next.add(j, curr(mn, mx + 1));
          }
        }
        unless (k) {
          next.add(j, -curr(j, j + 1));
        }
      }
      curr = next;
    }
    cout << curr(1, m+1) << endl;
  }

  return 0;
}
