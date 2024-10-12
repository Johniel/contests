// github.com/Johniel/contests
// atcoder/abc375/F/main.cpp

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

const int N = 300 + 3;

lli g[N][N];

int main(int argc, char *argv[])
{
  int n, m, q;
  while (cin >> n >> m >> q) {
    const lli inf = 1LL << 60;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = inf;
      }
      g[i][i] = 0;
    }
    int a[m], b[m];
    lli c[m];
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i];
      --b[i];
    }
    int op[q];
    int idx[q];
    int src[q], dst[q];
    fill(idx, idx + q, -1);
    fill(src, src + q, -1);
    fill(dst, dst + q, -1);
    for (int i = 0; i < q; ++i) {
      cin >> op[i];
      if (op[i] == 1) {
        cin >> idx[i];
        --idx[i];
      } else {
        cin >> src[i] >> dst[i];
        --src[i];
        --dst[i];
      }
    }

    set<int> vis;
    for (int i = 0; i < m; ++i) vis.insert(i);
    for (int i = 0; i < q; ++i) vis.erase(idx[i]);
    each (k, vis) {
      int x = a[k];
      int y = b[k];
      g[x][y] = g[y][x] = c[k];
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    vec<lli> v;
    for (int k = q - 1; 0 <= k; --k) {
      if (op[k] == 1) {
        int x = a[idx[k]];
        int y = b[idx[k]];
        setmin(g[x][y], c[idx[k]]);
        setmin(g[y][x], c[idx[k]]);
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            setmin(g[i][j], g[i][x] + g[x][y] + g[y][j]);
            setmin(g[i][j], g[i][y] + g[y][x] + g[x][j]);
          }
        }
      } else {
        lli z = g[src[k]][dst[k]];
        if (inf <= z) z = -1;
        v.push_back(z);
      }
    }
    reverse(v.begin(), v.end());
    each (i, v) cout << i << endl;
  }
  return 0;
}
