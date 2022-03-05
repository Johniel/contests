// codeforces/774div2/C/main.cpp
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

  vec<lli> v;
  const lli M = 1000000000000LL;
  {
    lli x = 1;
    for (lli i = 1; x <= M; ++i) {
      v.push_back(x *= i);
      if (__builtin_popcount(v.back()) == 1) v.pop_back();
    }
    // cout << v << v.size() << endl;
  }

  lli n;
  while (cin >> n) {

    const int inf = 1 << 29;
    int mn = inf;
    for (int bit = 0; bit < (1 << v.size()); ++bit) {
      lli x = 0;
      for (int i = 0; i < v.size(); ++i) {
        if (bit & (1 << i)) x += v[i];
      }
      if (n < x) continue;
      int z = __builtin_popcount(bit) + __builtin_popcountll(n - x);
      setmin(mn, z);
    }
    cout << mn << endl;
  }

  return 0;
}
