// github.com/Johniel/contests
// atcoder/abc369/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    const int N = 400 + 2;
    const lli inf = 1LL << 60;
    static lli g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);
    vec<vec<int>> bs;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      // cout << a << ' ' << b << ' ' << c << endl;
      bs.push_back(vec<int>({a, b, c}));
      setmin<lli>(g[a][b], c);
      setmin<lli>(g[b][a], c);
    }
    for (int i = 0; i < n; ++i) {
      g[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int k;
      cin >> k;
      vec<int> v(k);
      cin >> v;
      // cout << v << endl;
      each (i, v) --i;

      const int K = 5;
      const int B = 1 << K;
      static lli dp[B][N];
      fill(&dp[0][0], &dp[B - 1][N - 1], inf);
      dp[0][0] = 0;

      for (int bit = 0; bit < (1 << k); ++bit) {
        for (int j = 0; j < n; ++j) {
          if (inf <= dp[bit][j]) continue;
          for (int i = 0; i < v.size(); ++i) {
            int a = bs[v[i]][0];
            int b = bs[v[i]][1];
            lli c = bs[v[i]][2];
            setmin(dp[bit | (1 << i)][b], dp[bit][j] + g[j][a] + c);
            setmin(dp[bit | (1 << i)][a], dp[bit][j] + g[j][b] + c);
          }
        }
      }
      lli z = inf;
      for (int i = 0; i < n; ++i) {
        // cout << i+1 << ' ' << dp[(1 << k) - 1][i] << "+" << g[i][n - 1] << endl;
        setmin(z, dp[(1 << k) - 1][i] + g[i][n - 1]);
      }
      cout << z << endl;
    }
    // break;
  }
  return 0;
}
