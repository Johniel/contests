// atcoder/typical90/011/main.cpp
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

  const int N = 5000 + 5;

  int n;
  while (cin >> n) {
    using Job = struct {
      int d, c;
      lli s;
    };
    vec<Job> v;
    for (int i = 0; i < n; ++i) {
      int d, c;
      lli s;
      cin >> d >> c >> s;
      v.push_back(Job{d, c, s});
    }
    sort(v.begin(), v.end(), [] (auto a, auto b) { return a.d < b.d; });
    const int D = 5000 + 5;
    static lli dp[N][D];
    const lli inf = 1LL << 61;
    fill(&dp[0][0], &dp[N - 1][D - 1] + 1, 0);
    for (int i = 0; i < n; ++i) {
      if (i) {
        for (int j = 0; j + v[i].c <= v[i].d; ++j) {
          setmax(dp[i][j + v[i].c], dp[i - 1][j] + v[i].s);
        }
      } else {
        for (int j = 0; j + v[i].c <= v[i].d; ++j) {
          setmax(dp[i][j + v[i].c], v[i].s);
        }
      }
      if (i) {
        for (int j = 0; j < D; ++j) {
          setmax(dp[i][j], dp[i - 1][j]);
        }
      }
      for (int j = 0; j + 1 < D; ++j) {
        setmax(dp[i][j + 1], dp[i][j]);
      }
    }
    cout << *max_element(&dp[0][0], &dp[N - 1][D - 1] + 1) << endl;
  }

  return 0;
}
