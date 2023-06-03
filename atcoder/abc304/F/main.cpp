// github.com/Johniel/contests
// atcoder/abc304/F/main.cpp

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

vec<int> f(int n)
{
  if (n == 1) return {};
  vec<int> v;
  for (lli i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  v.push_back(1);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}

int main(int argc, char *argv[])
{
  const int N = 1e5 + 3;
  vec<lli> w(N, 0);
  w[0] = 1;
  for (int i = 1; i < w.size(); ++i) {
    w[i] = (w[i - 1]  * 2) % mod;
  }
  int n;
  str s;
  while (cin >> n >> s) {
    vec<int> fact = f(n);
    map<int, int> idx;
    for (int i = 0; i < fact.size(); ++i) {
      idx[fact[i]] = i;
    }
    static lli dp[N];
    fill(dp, dp + N, 0);
    dp[0] = 1 + (count(s.begin(), s.end(), '.') == 0);
    each (nth, fact) {
      const int i = idx[nth];

      vec<int> u;
      for (int j = 0; j < nth; ++j) {
        bool f = false;
        for (int k = 0; k < n / nth; ++k) {
          f = f || (s[j + k * nth] == '.');
        }
        u.push_back(f);
      }
      dp[i] = w[count(u.begin(), u.end(), 0)];

      vec<int> v = f(nth);
      each (mth, v) {
        const int j = idx[mth];
        dp[i] = (dp[i] - dp[j] + mod) % mod;
      }
    }
    lli z = 0;
    for (int i = 0; i < fact.size(); ++i) {
      (z += dp[i]) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
