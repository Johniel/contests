// github.com/Johniel/contests
// atcoder/awc0059/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

namespace LCA {
  const int N = 3 * 1e5 + 3;
  int parent[N];

  const int LOG2N = log2(N) + 1;
  int T[N][LOG2N], L[N];

  int addLevel(int node)
  {
    if (L[node] != -1) return L[node];
    else return L[node] = addLevel(parent[node]) + 1;
  }

  // ! keep parent[root] = root
  void build(const int n, const int root = 0)
  {
    assert(1 <= n);
    assert(parent[root] == root);
    fill(L, L + n, -1);
    L[root] = 0;
    for (int i = 0; i < n; ++i) {
      L[i] = addLevel(i);
    }

    // fill(&T[0][0], &T[N - 1][LOG2N], -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < LOG2N; ++j) {
        T[i][j] = -1;
      }
    }
    for (int i = 0; i < n; ++i) {
      T[i][0] = parent[i];
    }
    for (int j = 1; (1 << j) < n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (T[i][j - 1] != -1) {
          T[i][j] = T[T[i][j - 1]][j - 1];
        }
      }
    }
    return ;
  }

  int query(int a, int b)
  {
    if (L[a] < L[b]) swap(a, b);

    int lg = 1;
    while ((1 << lg) <= L[a]) ++lg;
    --lg;

    for (int i = lg; 0 <= i; --i) {
      if (L[a] - (1 << i) >= L[b]) {
        a = T[a][i];
      }
    }

    if (a == b) return a;
    for (int i = lg; 0 <= i; --i) {
      if (T[a][i] != -1 && T[a][i] != T[b][i]) {
        a = T[a][i];
        b = T[b][i];
      }
    }
    return parent[a];
  }
};

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<int> p(n - 1);
    cin >> p;
    each (i, p) --i;
    p.insert(p.begin(), 0);
    for (int i = 0; i < p.size(); ++i) {
      LCA::parent[i] = p[i];
    }
    LCA::build(p.size());
    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      cout << LCA::query(x, y) + 1 << endl;
    }
  }
  return 0;
}
