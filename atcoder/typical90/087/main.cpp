// atcoder/typical90/087/main.cpp
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

  int n, p, k;
  while (cin >> n >> p >> k) {
    const int N = 42;
    const lli inf = 1LL << 60;
    static lli g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);

    auto fn = [&] (lli x) {
      lli a[N][N];
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          a[i][j] = g[i][j];
          if (a[i][j] == -1) a[i][j] = x;
        }
      }
      for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < N; ++j) {
            setmin(a[i][j], a[i][k] + a[k][j]);
          }
        }
      }
      int z = 0;
      for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
          z += (a[i][j] <= p);
        }
      }
      return z;
    };

    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    if (fn(inf) == k) {
      cout << "Infinity" << endl;
      continue;
    }

    lli mn, mx;

    {
      lli small = 1;
      lli large = inf;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        if (k < fn(mid)) small = mid;
        else large = mid;
      }
      if (0) ;
      else if (fn(small) == k) mn = small;
      else if (fn(large) == k) mn = large;
      else {
        cout << 0 << endl;
        continue;
      }
    }
    {
      lli small = 1;
      lli large = inf;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        if (k <= fn(mid)) small = mid;
        else large = mid;
      }
      if (0) ;
      else if (fn(large) == k) mx = large;
      else if (fn(small) == k) mx = small;
      else {
        cout << 0 << endl;
        continue;
      }
    }
    cout << mx - mn + 1 << endl;
  }

  return 0;
}
