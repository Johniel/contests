// github.com/Johniel/contests
// atcoder/abc315/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  const int M = 100;
  static double w[M];
  w[0] = 0;
  w[1] = 1;
  for (int i = 2; i < M; ++i) {
    w[i] = w[i - 1] * 2.0;
  }

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;

    const double inf = 1e100;
    const int N = 1e4 + 3;
    static double cost[N][M];
    fill(&cost[0][0], &cost[N - 1][M - 1] + 1, inf);
    cost[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int skip = 0; skip < M; ++skip) {
        map<pair<int, int>, int> vis;
        for (int j = max(0, i - M); j < i; ++j) {
          double x = v[i].first - v[j].first;
          double y = v[i].second - v[j].second;
          double c = sqrt(x * x + y * y);
          const int ns = skip + (i - j - 1);
          if (ns < M) {
            setmin(cost[i][ns], cost[j][skip] + c);
          }
        }
      }
    }
    double z = inf;
    for (int skip = 0; skip < M; ++skip) {
      setmin(z, cost[n - 1][skip] + w[skip]);
    }
    cout << z << endl;
  }
  return 0;
}
