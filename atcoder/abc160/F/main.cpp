// atcoder/abc160/F/main.cpp
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

const int N = 2 * 1e5 + 5;

namespace math {
  lli fact[N], finv[N], inv[N];

  void init()
  {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++){
      fact[i] = fact[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }

  lli mod_comb(int n, int k)
  {
    assert(n < N && k < N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
  }

  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }
};

vec<int> g[N];
int s[N];
lli p[N];

int rec1(int curr, int prev)
{
  s[curr] = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    s[curr] += rec1(next, curr);
  }
  return s[curr];
}

lli rec2(int curr, int prev)
{
  int x = s[curr] - 1;
  p[curr] = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    p[curr] *= (rec2(next, curr) * math::mod_comb(x, s[next])) % mod;
    p[curr] %= mod;
    x -= s[next];
  }
  return p[curr];
}

lli q[N];
void rerooting(int curr, int prev, pair<int, lli> r)
{
  int x = 0;
  lli y = 1;
  each (next, g[curr]) {
    if (next == prev) {
      x += r.first;
    } else {
      x += s[next];
    }
  }
  int z = x;
  each (next, g[curr]) {
    if (next == prev) {
      y *= (r.second * math::mod_comb(z, r.first)) % mod;
      z -= r.first;
    } else {
      y *= (p[next] * math::mod_comb(z, s[next])) % mod;
      z -= s[next];
    }
    y %= mod;
  }
  q[curr] = y;

  each (next, g[curr]) {
    if (next == prev) continue;
    int z = x - s[next] + 1;
    lli u = p[next] * math::mod_comb(x, s[next]);
    auto w = y * math::mod_inverse(u, mod);
    w %= mod;
    rerooting(next, curr, make_pair(z, w));
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  math::init();

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    rec1(0, -1);
    rec2(0, -1);
    rerooting(0, -1, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
      cout << q[i] << endl;
    }
  }

  return 0;
}
