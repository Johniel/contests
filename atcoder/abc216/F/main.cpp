// atcoder/abc216/F/main.cpp
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
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<lli> a(n), b(n);
    cin >> a >> b;
    vec<int> idx;
    for (int i = 0; i < n; ++i) {
      idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; } );
    reverse(idx.begin(), idx.end());
    {
      vec<lli> c, d;
      each (i, idx) {
        c.push_back(a[i]);
        d.push_back(b[i]);
      }
      a = c;
      b = d;
    }
    const int N = 5000 + 3;
    static lli dp[N][2][N]; // dp[どこまで見た][決まった][余裕 if 決まっていたら otherwise 和]:=パターン
    fill(&dp[0][0][0], &dp[N - 1][2 - 1][N - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < N; ++j) {
        // 決まってる
        if (0 <= j - b[i]) {
          (dp[i + 1][true][j - b[i]] += dp[i][true][j]) %= mod;
        }
        (dp[i + 1][true][j] += dp[i][true][j]) %= mod;
      }
      // 決まってない
      (dp[i + 1][false][0] += dp[i][false][0]) %= mod;
      // 決めた
      if (0 <= a[i] - b[i]) {
        (dp[i + 1][true][a[i] - b[i]] += dp[i][false][0]) %= mod;
      }
    }
    lli z = 0;
    for (int i = 0; i < N; ++i) {
      (z += dp[n][true][i]) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
