// atcoder/m-solutions2020/E/main.cpp
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
    lli x[n], y[n], u[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> u[i];
    }

    const int N = 16;
    const int BIT = 1 << N;
    const lli inf = 1LL << 60;

    static lli mnx[BIT][N];
    static lli mny[BIT][N];

    for (int bit = 0; bit < (1 << n); ++bit) {
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) mnx[bit][i] = mny[bit][i] = 0;
        else {
          mnx[bit][i] = abs(x[i]);
          mny[bit][i] = abs(y[i]);
        }
      }

      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) {
          for (int j = 0; j < n; ++j) {
            unless (bit & (1 << j)) {
              setmin(mnx[bit][j], abs(x[i] - x[j]));
              setmin(mny[bit][j], abs(y[i] - y[j]));
            }
          }
        }
      }
    }

    lli mn[N];
    fill(mn, mn + N, inf);

    for (int bit = 0; bit < (1 << n); ++bit) {
      const int pc = __builtin_popcount(bit);
      for (int A = bit; 0 <= A; --A) {
        A = A & bit;
        int B = bit - A;

        lli sum = 0;
        for (int i = 0; i < n; ++i) {
          sum += min(mnx[A][i], mny[B][i]) * u[i];
        }

        setmin(mn[pc], sum);
      }
    }

    for (int i = 0; i <= n; ++i) {
      cout << mn[i] << endl;
    }
  }

  return 0;
}
