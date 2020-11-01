// atcoder/abc181/E/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vec<int> h(n);
    vec<int> w(m);
    cin >> h >> w;
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());

    const int N = 2 * 1e5 + 5;
    static lli dp[N][2];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      if (i + 1 < h.size()) {
        setmin(dp[i + 2][0], dp[i][0] + abs(h[i] - h[i + 1]));
        setmin(dp[i + 2][1], dp[i][1] + abs(h[i] - h[i + 1]));
      }
      auto itr1 = lower_bound(w.begin(), w.end(), h[i]);
      auto itr2 = itr1;
      auto itr3 = itr2;
      if (itr1 != w.begin()) --itr2;
      if (itr1 != w.end()) ++itr3;

      if (itr1 != w.end()) setmin(dp[i + 1][1], dp[i][0] + abs(h[i] - *itr1));
      if (itr2 != w.end()) setmin(dp[i + 1][1], dp[i][0] + abs(h[i] - *itr2));
      if (itr3 != w.end()) setmin(dp[i + 1][1], dp[i][0] + abs(h[i] - *itr3));
    }
    cout << dp[n][1] << endl;
  }

  return 0;
}
