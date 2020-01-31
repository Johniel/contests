// codeforces/e81/D/main.cpp
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
template<typename T> inline pair<T, T> reverse(pair<T, T> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;

constexpr lli mod = 1e9 + 7;

lli fn(lli a, lli m)
{
  int cnt = 0;
  for (lli x = 0; x  < m; ++x) {
    cnt += __gcd(a, m) == __gcd(a + x, m);
  }
  return cnt;
}

lli solve(const lli a, const lli m)
{
  const lli g = __gcd(a, m);
  // lli x = a / g * m;
  lli x = m / g;
  vector<lli> v;
  for (lli i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      v.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x != 1) v.push_back(x);

  lli sum = 0;
  for (int bit = 0; bit < (1 << v.size()); ++bit) {
    lli p = 1;
    for (int i = 0; i < v.size(); ++i) {
      if (bit & (1 << i)) {
        p *= v[i];
      }
    }
    lli q = ((a + m - 1) / (p * g)) - ((a - 1) / (p * g));
    // cout << a+m-1 << "/" << p * g << " - " << a-1 << "/" << p*g << " = " << q << endl;
    if (__builtin_popcount(bit) % 2) sum -= q;
    else sum += q;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // for (int i = 1; i < 1000; ++i) {
  //   for (int j = i + 1; j < 1000; ++j) {
  //     cout << i << ' ' << j << ": " << fn(i, j) << ' ' << solve(i, j) << endl;
  //     assert(fn(i, j) == solve(i, j));
  //   }
  // }

  int tc;
  cin >> tc;
  lli a, m;
  while (cin >> a >> m) {
    cout << solve(a, m) << endl;
  }

  return 0;
}
