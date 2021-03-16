// atcoder/dwango2015-prelims/C/main.cpp
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

  int n;
  while (cin >> n) {
    const int N = 100 + 4;

    double fact[N];
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = fact[i - 1] * i;
    }

    double three[N];
    three[0] = 1;
    for (int i = 1; i < N; ++i) {
      three[i] = three[i - 1] * 3;
    }

    double dp[N];
    fill(dp, dp + N, 0);
    for (int i = 2; i <= n; ++i) {
      double d = 0;
      double o = 0;
      for (int r = 0; r <= i; ++r) {
        for (int p = 0; r + p <= i; ++p) {
          int s = i - r - p;
          double q = fact[i] / three[i] / fact[r] / fact[p] / fact[s];
          if (r == i || p == i || s == i) d += q;
          else if (r == 0) {
            if (p < s) o += (dp[p] + 1) * q;
            else       o += (dp[s] + 1) * q;
          } else if (p == 0) {
            if (r < s) o += (dp[r] + 1) * q;
            else       o += (dp[s] + 1) * q;
          } else if (s == 0) {
            if (p < r) o += (dp[p] + 1) * q;
            else       o += (dp[r] + 1) * q;
          }
          else if (r && r < min(p, s)) o += (dp[r] + 1) * q;
          else if (p && p < min(r, s)) o += (dp[p] + 1) * q;
          else if (s && s < min(p, r)) o += (dp[s] + 1) * q;
          else if (r && r == s && s < p) o += (dp[r] + 1) * q;
          else if (p && r == p && p < s) o += (dp[p] + 1) * q;
          else if (s && p == s && s < r) o += (dp[s] + 1) * q;
          else d += q;
        }
      }
      dp[i] = (d + o) / (1.0 - d);
    }
    cout << dp[n] << endl;
  }

  return 0;
}
