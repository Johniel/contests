// codeforces/GoodBye2020/E/main.cpp
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

  int _;
  // cin >> _;
  scanf("%d", &_);

  int n;
  while (scanf("%d", &n) != EOF) {
  // while (cin >> n) {
    // vec<lli> v(n);
    // cin >> v;
    const int N = 5 * 1e5 + 3;
    static lli v[N];
    for (int i = 0; i < n; ++i) {
      scanf("%lld", v + i);
    }

    const int M = 60 + 2;
    static int cnt[M];
    fill(cnt, cnt + M, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 60; ++j) {
        if (v[i] & (1LL << j)) ++cnt[j];
      }
    }

    lli x = 0;
    for (int _i = 0; _i < n; ++_i) {
      const lli i = v[_i];
      lli a = 0;
      lli b = 0;
      for (int j = 0; j <= 60; ++j) {
        const lli p = (1LL << j);
        if (i & p) {
          a += (p % mod * cnt[j]) % mod;
          a %= mod;
        }
      }

      for (int j = 0; j <= 60; ++j) {
        const lli w = (1LL << j);
        if (i & w) {
          b += (w % mod * n % mod) % mod;
        } else {
          b += (w % mod * cnt[j] % mod) % mod;
        }
        b %= mod;
      }
      x += (a * b) % mod;
      x %= mod;
    }
    printf("%lld\n", x);
    // cout << x << endl;
  }

  return 0;
}
