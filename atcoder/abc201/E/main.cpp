// atcoder/abc201/E/main.cpp
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

namespace math {
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
}
const int N = 2 * 1e5 + 5;
vec<pair<int, lli>> g[N];

lli memo1[N];
void rec1(int curr, int prev, lli x)
{
  memo1[curr] = x;
  each (e, g[curr]) {
    if (e.first == prev) continue;
    rec1(e.first, curr, x ^ e.second);
  }
  return ;
}

lli cnt[70];
lli sum;
int n;
int m;
void rec2(int curr, int prev, lli bit)
{
  lli x = 0;
  for (int i = 0; i < m; ++i) {
    if (bit & (1LL << i)) {
      lli w = (1LL << i) % mod;
      x += (w * ((n - 0) - cnt[i])) % mod;
    } else {
      lli w = (1LL << i) % mod;
      x += (w * cnt[i]) % mod;
    }
    x %= mod;
  }
  // cout << vec<lli>({curr+1, bit, x}) << ' ' << vec<lli>(cnt, cnt + m) << endl;
  (sum += x) %= mod;
  each (e, g[curr]) {
    if (e.first == prev) continue;
    rec2(e.first, curr, bit ^ e.second);
  }
  return ;
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n) {
    fill(g, g + N, vec<pair<int, lli>>());
    m = 0;
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      lli w;
      cin >> a >> b >> w;
      --a;
      --b;
      g[a].push_back(make_pair(b, w));
      g[b].push_back(make_pair(a, w));
      for (int j = 0; j < 61; ++j) {
        if (w & (1LL << j)) {
          setmax(m, j + 1);
        }
      }
    }
    rec1(0, 0, 0LL);
    fill(cnt, cnt + 70, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (memo1[i] & (1LL << j)) {
          ++cnt[j];
        }
      }
    }
    // for (int i = 0; i < m; ++i) {
    //   cout << make_pair(i, cnt[i]) << ' ';
    // }
    // cout << endl;
    sum = 0;
    rec2(0, 0, 0);
    cout << (sum * math::mod_inverse(2, mod)) % mod << endl;
  }

  return 0;
}
