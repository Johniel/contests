// atcoder/agc053/A/main.cpp
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
  str s;
  while (cin >> n >> s) {
    vec<int> a(n + 1);
    cin >> a;

    const int N = 10000 + 3;
    const int M = 100 + 3;
    int x = 0;
    static int g[N][M];
    static int h[N][M];

    auto fn = [&] (int k) {
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < a.size(); ++j) {
          g[i][j] = a[j] / k;
        }
      }
      for (int j = 0; j < a.size(); ++j) {
        for (int i = 0; i < a[j] % k; ++i) {
          ++g[i][j];
        }
      }

      bool f = true;
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < s.size(); ++j) {
          if (s[j] == '<') f = f && (g[i][j] < g[i][j + 1]);
          if (s[j] == '>') f = f && (g[i][j] > g[i][j + 1]);
        }
      }
      if (f) {
        x = k;
        for (int i = 0; i < k; ++i) {
          for (int j = 0; j < a.size(); ++j) {
            h[i][j] = g[i][j];
          }
        }
      }
      return f;
    };

    int small = 1;
    int large = 10000 + 1;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    fn(small);

    cout << x << endl;
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < a.size(); ++j) {
        cout << h[i][j] << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
