// github.com/Johniel/contests
// codeforces/TypeDBForces2023/A/main.cpp

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
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;


lli fn(lli n, lli p)
{
  if (p == 0) return 1;
  if (p == 1) return n;
  lli m = fn(n, p / 2);
  m *= m;
  if (p % 2) m = (m * n);
  return m;
}

lli f(lli x, lli y)
{
  return fn(x, y) * y + fn(y, x) * x;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  map<lli, pair<lli, lli>> m;
  for (lli x = 2; ; ++x) {
    bool f = false;
    for (lli y = x; ; ++y) {
      const int N = 1e9 + 3;
      lli a = fn(x, y) * y;
      lli b = fn(y, x) * x;
      if (N <= a + b) break;
      f = true;
      m[a + b] = make_pair(x, y);
    }
    unless (f) break;
  }

  lli n;
  while (cin >> n) {
    if (n % 2 == 0) cout << 1 << ' ' << n / 2 << endl;
    else {
      if (m.count(n)) cout << m[n].first << ' ' << m[n].second << endl;
      else cout << -1 << endl;
    }
  }

  return 0;
}
