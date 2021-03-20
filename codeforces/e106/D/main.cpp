// codeforces/e106/D/main.cpp
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

inline vec<int> fn(int x)
{
  vec<int> v;
  for (lli i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      // int j = x / i;
      v.push_back(i);
      // if (i != j) v.push_back(j);
    }
  }
  return v;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 2 * 1e7 + 5;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  static int f[N];
  for (lli i = 2; i * i < N; ++i) {
    unless (prime[i]) continue;
    for (lli j = i; j < N; j += i) {
      prime[j] = false;
      f[j] = i;
    }
  }

  static int pf[N];
  for (int i = 2; i < N; ++i) {
    if (prime[i]) pf[i] = 1;
    else {
      int j = i / f[i];
      pf[i] = pf[j] + (__gcd(j, f[i]) == 1);
    }
  }

  int w[100];
  w[0] = 1;
  for (int i = 1; i < 100; ++i) {
    w[i] = w[i - 1] * 2;
  }

  int _;
  // cin >> _;
  scanf("%d", &_);

  int c, d, x;
  // while (cin >> c >> d >> x) {
  while (scanf("%d%d%d", &c, &d, &x) == 3) {
    int y = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i) continue;

      int s = (x / i) + d;
      if (s % c == 0) {
        int t = s / c;
        y += w[pf[t]];
      }

      int j = x / i;
      if (i != j) {
        int s = (x / j) + d;
        if (s % c == 0) {
          int t = s / c;
          y += w[pf[t]];
        }
      }
    }
    // cout << y << endl;
    printf("%d\n", y);
  }

  return 0;
}
