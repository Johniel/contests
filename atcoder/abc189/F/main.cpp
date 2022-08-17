// github.com/Johniel/contests
// atcoder/abc189/F/main.cpp

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

  int n, m, k;
  while (cin >> n >> m >> k) {
    vec<int> a(k);
    cin >> a;

    bool f = false;
    for (int i = 0; i + m - 1 < a.size(); ++i) {
      if (a[i] + m - 1 == a[i + m - 1]) {
        f = true;
      }
    }
    if (f) {
      cout << -1 << endl;
      continue;
    }

#define double long double

    vec<bool> b(n, false);
    each (i, a) b[i] = true;

    auto fn = [&] (double x) {
      const int N = 2 * 1e5 + 3;
      static double dp[N];
      static double s[N];
      s[n] = s[n + 1] = 0;
      for (int i = n - 1; 0 <= i; --i) {
        if (b[i]) {
          dp[i] = x;
        } else {
          dp[i] = (s[i + 1] - s[i + m + 1]) / m + 1.0;
        }
        s[i] = s[i + 1] + dp[i];
      }
      return dp[0];
    };

    const double X = 1e20;
    double small = 0;
    double large = X;
    for (int _ = 0; _ < 300; ++_) {
      double mid = (small + large) / 2;
      if (mid < fn(mid)) small = mid;
      else large = mid;
    }
    cout << fn(small) << endl;
  }

  return 0;
}
