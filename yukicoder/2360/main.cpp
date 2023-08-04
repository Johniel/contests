// github.com/Johniel/contests
// yukicoder/2360/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

vec<lli> p10;

vec<lli> a;

const int N = 1e5 + 2;
vec<vec<int>> g;
vec<pair<int, lli>> v;
int n;

pair<int, lli> // child, sum
rec(int curr, int prev)
{
  const lli w = p10[to_string(a[curr]).size()];
  lli z = a[curr];
  int c = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    pair<int, lli> p = rec(next, curr);
    c += p.first;
    lli x = p.first * a[curr] % mod;
    lli y = p.second * w % mod;
    (z += x + y) %= mod;
  }
  return v[curr] = make_pair(c, z);
}

lli fn(int curr, int prev, lli p)
{
  lli q = p;
  const lli w = p10[to_string(a[curr]).size()];
  p = (p * w % mod) + ((n - v[curr].first) * (a[curr] % mod) % mod);
  p %= mod;

  lli z = p + v[curr].second;

  each (next, g[curr]) {
    if (next == prev) continue;
    lli whole = (p + v[curr].second) % mod;

    lli x = v[next].first * a[curr] % mod;
    lli y = v[next].second * w % mod;
    lli child = (x + y) % mod;

    lli np = (whole - child + mod) % mod;
    z += fn(next, curr, np);
  }
  return z;
}

int main(int argc, char *argv[])
{
  p10.resize(100);
  p10[0] = 1;
  for (int i = 1; i < p10.size(); ++i) {
    p10[i] = p10[i - 1] * 10 % mod;
  }

  while (cin >> n) {
    v.resize(n);
    g.clear();
    g.resize(n, vec<int>());
    a.resize(n);
    cin >> a;
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    rec(0, 0);
    lli w = fn(0, 0, 0);
    cout << w%mod << endl;
  }
  return 0;
}
