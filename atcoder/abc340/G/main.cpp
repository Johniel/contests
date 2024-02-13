// github.com/Johniel/contests
// atcoder/abc340/G/main.cpp

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

namespace LCA {
  const int N = 2 * 1e5 + 3;
  int parent[N];

  const int LOG2N = log2(N) + 1;
  int T[N][LOG2N], L[N];

  int addLevel(int node)
  {
    if (L[node] != -1) return L[node];
    else return L[node] = addLevel(parent[node]) + 1;
  }

  // ! keep parent[root] = root
  void build(int n)
  {
    const int root = 0;
    fill(L, L + n, -1);
    L[root] = 0;
    for (int i = 0; i < n; ++i) {
      L[i] = addLevel(i);
    }

    fill(&T[0][0], &T[N - 1][LOG2N], -1);
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

// 指定された頂点集合の最小共通祖先関係を保ったまま木を圧縮した補助的な木
// 頂点集合Xに対して構築がO(|X|*log元の木のサイズ)
// a.k.a VirtualTree
namespace auxiliary_tree {
  // ABC340G
  const int N = 2 * 1e5 + 3;
  int preord[N];
  int preord_end[N];
  vec<int> g[N];
  int cnt;
  void rec(int curr, int prev)
  {
    LCA::parent[curr] = prev;
    preord[curr] = cnt++;
    each (next, g[curr]) {
      if (next == prev) continue;
      rec(next, curr);
    }
    preord_end[curr] = cnt;
    return ;
  }

  void init(const int n) {
    fill(g, g + n, vec<int>());
    return ;
  }
  void build(const int n) {
    fill(preord, preord + n, -1);
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (preord[i] == -1) rec(i, i);
    }
    LCA::build(n);
    return ;
  }

  // 圧縮後の木の頂点列（preord順）
  vector<int> vertexes(vector<int> x) {
    sort(x.begin(), x.end(), [&] (int a, int b) { return preord[a] < preord[b]; });
    vector<int> y = x;
    for (int i = 0; i + 1 < x.size(); ++i) {
      y.push_back(LCA::query(x[i], x[i + 1]));
    }
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    sort(y.begin(), y.end(), [&] (int a, int b) { return preord[a] < preord[b]; });
    return y;
  }

  // 圧縮後の木の{根,辺}
  pair<int, vector<pair<int, int>>> edges(vector<int> x) {
    vector<int> vs = vertexes(x);
    vector<int> stk;
    vector<pair<int, int>> es;
    for (const auto& i: vs) {
      while (stk.size() && preord_end[stk.back()] <= preord[i]) {
        stk.pop_back();
      }
      if (stk.size()) {
        es.push_back(make_pair(stk.back(), i));
      }
      stk.push_back(i);
    }
    return make_pair(stk.front(), es);
  }
};

const int N = 2 * 1e5 + 3;
vec<int> g[N];
void rec(int curr, int prev)
{

  each (next, g[curr]) {
    if (next != prev) continue;
    rec(next, curr);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    auxiliary_tree::init(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      auxiliary_tree::g[x].push_back(y);
      auxiliary_tree::g[y].push_back(x);
    }
    rec(0, 0);
    auxiliary_tree::build(n);
    map<int, vec<int>> m;
    for (int i = 0; i < n; ++i) {
      m[a[i]].push_back(i);
    }
    lli z = 0;
    each (k, m) {
      auto [root, es] = auxiliary_tree::edges(k.second);
      map<int, vec<int>> g;
      each (e, es) g[e.first].push_back(e.second);
      map<int, pair<lli, lli>> r;
      function<pair<lli, lli>(int)> rec = [&] (int curr) {
        if (a[curr] == k.first) {
          lli x = 1;
          lli y = 1;
          each (next, g[curr]) {
            auto p = rec(next);
            (x *= p.second + 1) %= mod;
            (y *= p.second + 1) %= mod;
          }
          return r[curr] = make_pair(x, y);
        } else {
          lli x = 1;
          lli y = 1;
          lli w = 0;
          each (next, g[curr]) {
            auto p = rec(next);
            (x *= p.second + 1) %= mod;
            (y *= p.second + 1) %= mod;
            (w += p.second) %= mod;
          }
          (x += mod - w - 1) %= mod;
          (y += mod - 1) %= mod;
          return r[curr] = make_pair(x, y);
        }
        return make_pair(0LL, 0LL);
      };
      rec(root);
      each (i, r) (z += i.second.first) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
