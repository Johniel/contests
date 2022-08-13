// github.com/Johniel/contests
// atcoder/abc264/G/main.cpp

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

  int n;
  while (cin >> n) {
    vec<pair<str, int>> v(n);
    cin >> v;

    const int N = 30;
    const int T = 'z' - 'a' + 1;

    static lli m[N][N][N];
    fill(&m[0][0][0], &m[N - 1][N - 1][N - 1] + 1, 0);
    auto get = [&] (int a, int b, int c) { return m[a][b][c]; };

    each (i, v) {
      str s = i.first;
      while (s.size() < 3) s += (char)(T + 'a');
      each (j, s) j -= 'a';
      m[s[0]][s[1]][s[2]] = i.second;
    }

    const lli inf = 1LL << 61;
    static lli g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, -inf);
    g[T][T] = 0;

    auto fn = [&] () {
      for (int k = 0; k < T; ++k) {
        for (int i = 0; i <= T; ++i) {
          for (int j = 0; j <= T; ++j) {
            lli p = get(k, T, T) + get(j, k, T) + get(i, j, k);
            setmax(g[j][k], min(g[i][j] + p, inf));
          }
        }
      }
      lli mx = -inf;
      for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) setmax(mx, g[i][j]);
      }
      return mx;
    };

    lli z = -inf;
    for (int _ = 0; _ < T * T; ++_) z = fn();
    const lli tmp = z;
    for (int _ = 0; _ < T * T; ++_) z = fn();
    if (tmp < z) {
      cout << "Infinity" << endl;
      continue;
    }
    for (int i = 0; i <= T; ++i) {
      for (int j = 0; j < T; ++j) {
        lli p = get(i, j, T) + get(i, T, T) + get(j, T, T);
        setmax(z, p);
      }
    }
    cout << z << endl;
  }

  return 0;
}
