// github.com/Johniel/contests
// atcoder/abc286/E/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    const int N = 300 + 2;
    static bool x[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        x[i][j] = (c == 'Y');
      }
    }
    static pair<int, lli> g[N][N];
    const int inf = 1 << 28;
    fill(&g[0][0], &g[N - 1][N - 1] + 1, make_pair(inf, 0));
    for (int i = 0; i < n; ++i) {
      g[i][i] = make_pair(0, -a[i]);
      for (int j = 0; j < n; ++j) {
        if (x[i][j]) {
          g[i][j] = make_pair(1, -(a[i] + a[j]));
        }
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          int dist = g[i][k].first + g[k][j].first;
          lli w = abs(g[i][k].second) + abs(g[k][j].second) - a[k];
          setmin(g[i][j], make_pair(dist, -w));
        }
      }
    }

    int q;
    cin >> q;
    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      if (g[x][y].first == inf) cout << "Impossible" << endl;
      else cout << g[x][y].first << ' ' << -g[x][y].second << endl;
    }
  }
  return 0;
}
