// github.com/Johniel/contests
// atcoder/abc271/D/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, s;
  while (cin >> n >> s) {
    const int N = 100 + 3;
    const int S = 10000 + 3;
    vec<pair<int, int>> v(n);
    cin >> v;

    static int dp[N][S];
    fill(&dp[0][0], &dp[N - 1][S - 1] + 1, -1);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= s; ++j) {
        if (dp[i][j] == -1) continue;
        if (j + v[i].first  <= s) dp[i + 1][j + v[i].first] = 0;
        if (j + v[i].second <= s) dp[i + 1][j + v[i].second] = 1;
      }
    }

    if (dp[n][s] == -1) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
    str t;
    for (int i = n; 0 < i; --i) {
      if (dp[i][s] == 0) {
        s -= v[i-1].first;
        t += 'H';
      } else {
        s -= v[i-1].second;
        t += 'T';
      }
    }
    reverse(t.begin(), t.end());
    assert(s == 0);
    cout << t << endl;
  }

  return 0;
}
