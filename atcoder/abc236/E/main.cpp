// atcoder/abc236/E/main.cpp
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

const int N = 1e5 + 3;

double fn1(vec<int> a)
{
  static double dp[N][2];
  auto fn = [&] (double k) {
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, -(1e128));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < a.size(); ++i) {
      setmax(dp[i + 1][0], dp[i][1]);
      setmax(dp[i + 1][1], dp[i][1] + (a[i] - k));
      setmax(dp[i + 1][1], dp[i][0] + (a[i] - k));
    }
    return max(dp[a.size()][0], dp[a.size()][1]);
  };

  double small = 0;
  double large = 1e128;
  for (int _ = 0; _ < 1000; ++_) {
    double mid = (small + large) / 2;
    if (0 <= fn(mid)) small = mid;
    else large = mid;
  }
  return small;
}

int fn2(vec<int> a)
{
  static int dp[N][2];
  auto fn = [&] (double k) {
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, -(1e128));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < a.size(); ++i) {
      int x = (k <= a[i]) ? +1 : -1;
      setmax(dp[i + 1][0], dp[i][1]);
      setmax(dp[i + 1][1], dp[i][1] + x);
      setmax(dp[i + 1][1], dp[i][0] + x);
    }
    return 0 < max(dp[a.size()][0], dp[a.size()][1]);
  };

  lli small = 0;
  lli large = 1LL << 60;
  while (small + 1 < large) {
    lli mid = (small + large) / 2;
    if (fn(mid)) small = mid;
    else large = mid;
  }
  return small;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    cout << fn1(a) << endl;
    cout << fn2(a) << endl;
  }

  return 0;
}
