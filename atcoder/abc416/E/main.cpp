// github.com/Johniel/contests
// atcoder/abc416/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

const int N = 500 + 3;
lli g[N][N];
const lli inf = (1LL << 60);

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);
    for (int i = 0; i < N; ++i) g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      --a;
      --b;
      setmin(g[a][b], c);
      setmin(g[b][a], c);
    }
    int k;
    lli t;
    cin >> k >> t;
    vec<int> d(k);
    cin >> d;
    each (i, d) --i;
    const int A = n;
    each (i, d) {
      g[i][A] = 0;
      g[A][i] = t;
    }
    for (int k = 0; k <= n; ++k) {
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    auto z = [&] (void) {
      lli z = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (g[i][j] < inf) z += g[i][j];
        }
      }
      return z;
    };

    int q;
    cin >> q;
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int x, y;
        lli t;
        cin >> x >> y >> t;
        --x;
        --y;
        setmin(g[x][y], t);
        setmin(g[y][x], t);
        for (int a = 0; a <= n; ++a) {
          for (int b = 0; b <= n; ++b) {
            setmin(g[a][b], min(g[a][y] + g[y][x] + g[x][b],
                                g[a][x] + g[x][y] + g[y][b]));
          }
        }
      }
      if (op == 2) {
        int x;
        cin >> x;
        --x;
        g[x][A] = 0;
        g[A][x] = t;
        for (int i = 0; i <= n; ++i) {
          for (int j = 0; j <= n; ++j) {
            setmin(g[i][j], g[i][x] + g[x][j]);
            setmin(g[i][j], g[i][A] + g[A][j]);
            setmin(g[i][j], g[i][x] + g[x][A] + g[A][j]);
            setmin(g[i][j], g[i][A] + g[A][x] + g[x][j]);
          }
        }
      }
      if (op == 3) {
        cout << z() << endl;
      }
    }
  }
  return 0;
}
