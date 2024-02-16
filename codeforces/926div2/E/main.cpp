// github.com/Johniel/contests
// codeforces/926div2/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
namespace LCA {
  int parent[N];

  const int LOG2N = log2(N) + 1;
  int T[N][LOG2N], L[N];

  int addLevel(int node)
  {
    if (L[node] != -1) return L[node];
    else return L[node] = addLevel(parent[node]) + 1;
  }

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

vec<int> g[N];

void rec(int curr, int prev)
{
  LCA::parent[curr] = prev;
  each (next, g[curr]) {
    if (next == prev) continue;
    rec(next, curr);
  }
  return ;
}

vec<int> add;
vec<int> sub;
vec<int> mask;
int rec2(int curr, int prev)
{
  int b = 0;
  each (next, g[curr]) {
    if (next == prev) continue;
    int c = rec2(next, curr);
    b = b | c;
    if (c) mask.push_back(c);
  }
  b = b | add[curr];
  b = b - (b & sub[curr]);
  return b;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  add.resize(N);
  sub.resize(N);
  int n;
  while (cin >> n) {
    fill(g, g + n, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    rec(0, 0);
    LCA::build(n, 0);
    int q;
    cin >> q;
    vec<pair<int, int>> v(q);
    cin >> v;
    each (i, v) --i.first, --i.second;
    fill(add.begin(), add.begin() + n, 0);
    fill(sub.begin(), sub.begin() + n, 0);
    int k = 0;
    each (i, v) {
      int lca = LCA::query(i.first, i.second);
      add[i.first] |= (1 << k);
      add[i.second] |= (1 << k);
      sub[lca] |= (1 << k);
      ++k;
    }
    mask.clear();
    rec2(0, 0);
    sort(mask.begin(), mask.end());
    mask.erase(unique(mask.begin(), mask.end()), mask.end());
    const int K = 20 + 1;
    const int B = (1 << K);
    static int dp[B];
    const int inf = 1 << 29;
    fill(dp, dp + (1 << k), inf);
    dp[0] = 0;
    for (int i = 0; i < (1 << k); ++i) {
      if (dp[i] == inf) continue;
      each (j, mask) setmin(dp[i | j], dp[i] + 1);
    }
    cout << dp[(1 << k) - 1] << '\n';
  }
  return 0;
}
