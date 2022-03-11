// codeforces/e124/C/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<lli> a(n), b(n);
    cin >> a >> b;

    vec<lli> sa = a;
    vec<lli> sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    auto fn = [] (lli x, vec<lli>& sorted) {
      lli mn = 1LL << 60;
      auto itr = lower_bound(sorted.begin(), sorted.end(), x);
      if (itr != sorted.end()) {
        setmin(mn, abs(x - *itr));
      }
      if (itr != sorted.begin()) {
        --itr;
        setmin(mn, abs(x - *itr));
      }
      return mn;
    };

    lli z =
      fn(a.back(), sb) +
      fn(b.back(), sa) +
      fn(a.front(), sb) +
      fn(b.front(), sa);

    lli x = abs(a.front() - b.front()) + abs(a.back() - b.back());
    lli y = abs(a.front() - b.back()) + abs(a.back() - b.front());

    lli p = abs(a.front() - b.front()) + fn(a.back(), sb) + fn(b.back(), sa);
    lli q = abs(a.back() - b.back()) + fn(a.front(), sb) + fn(b.front(), sa);

    lli s = abs(a.front() - b.back()) + fn(a.back(), sb) + fn(b.front(), sa);
    lli t = abs(a.back() - b.front()) + fn(a.front(), sb) + fn(b.back(), sa);

    cout << min({x, y, z, p, q, s, t}) << endl;
  }

  return 0;
}
