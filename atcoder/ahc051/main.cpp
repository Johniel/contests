// github.com/Johniel/contests
// atcoder/ahc051/main.cpp

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

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
  }

  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

namespace geo {
  using point = complex<double>;

  // [-M_PI,+M_PI]の範囲で偏角を返す。
  inline double angle(double x, double y)
  {
    return atan2(y, x);
  }

  template<typename T>
  inline double angle(complex<T> p)
  {
    return atan2(p.imag(), p.real());
  }

  template<typename T>
  inline double angle(pair<T, T> p)
  {
    return atan2(p.second, p.first);
  }

  // 点pを原点中心にthだけ回転させた座標を返す。
  // verified at: abc259/B
  pair<double, double> rot(double x, double y, double th)
  {
    double a = x * cos(th) - y * sin(th);
    double b = x * sin(th) + y * cos(th);
    return make_pair(a, b);
  }

  // verified at: abc259/B
  pair<double, double> rot(pair<double, double> p, double th)
  {
    return rot(p.first, p.second, th);
  }

  // verified at: abc259/B
  point rot(point p, double th)
  {
    auto r = rot(p.real(), p.imag(), th);
    return point(r.first, r.second);
  }

  template<typename T>
  pair<T, T> rot90(T x, T y)
  {
    T a = x * 0 - y * 1;
    T b = x * 1 + y * 0;
    return make_pair(a, b);
  }

  const double eps = 1e-8;
  const double PI = acos(-1);

  bool eq(double a, double b) {
    return abs(a - b) < eps;
  }

  bool eq(point a, point b) {
    return eq(a.real(), b.real()) && eq(a.imag(), b.imag());
  }
};

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

namespace {
  inline int sign(int v)                 // v > 0 → 1, v < 0 → -1, v == 0 → 0
  {
    if (0 < v) return +1;
    if (0 > v) return -1;
    return 0;
  }

// (b - a) × (c - a) を計算（64bit）
  inline int cross(const pair<int,int>& a,
                   const pair<int,int>& b,
                   const pair<int,int>& c)
  {
    return (b.first  - a.first)  * (c.second - a.second) - (b.second - a.second) * (c.first  - a.first);
  }

  inline int orientation(const pair<int,int>& a,
                         const pair<int,int>& b,
                         const pair<int,int>& c)
  {
    return sign(cross(a, b, c));
  }

  inline bool segments_intersect(const pair<int,int>& p1,
                                 const pair<int,int>& p2,
                                 const pair<int,int>& q1,
                                 const pair<int,int>& q2)
  {

    // 軸平行境界箱で早期除外
    if (max(p1.first,  p2.first)  < min(q1.first,  q2.first)  ||
        max(q1.first,  q2.first)  < min(p1.first,  p2.first)  ||
        max(p1.second, p2.second) < min(q1.second, q2.second) ||
        max(q1.second, q2.second) < min(p1.second, p2.second))
      return false;

    int o1 = orientation(p1, p2, q1);
    int o2 = orientation(p1, p2, q2);
    int o3 = orientation(q1, q2, p1);
    int o4 = orientation(q1, q2, p2);
    // 端点共有も交差とみなす
    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
  }
};

namespace {
  using point = complex<int>;

  inline point normal(point v)
  {
    return v * point(0, -1);
  }

  inline lli dot(point a, point b)
  {
    return (a.real() * b.real() + a.imag() * b.imag());
  }

  inline lli cross(point a, point b)
  {
    return (a.real() * b.imag() - a.imag() * b.real());
  }

  namespace CCW{
    enum{ RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
  };

  inline int ccw(point a, point b, point c)
  {
    b -= a;
    c -= a;
    if (cross(b, c) < 0) return CCW::RIGHT;
    if (cross(b, c) > 0) return CCW::LEFT;
    if (dot(b, c) < 0) return CCW::BACK;
    if (norm(b) < norm(c)) return CCW::FRONT;
    return CCW::OTHER;
  }

  inline int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return ccw(
      point(a.first, a.second),
      point(b.first, b.second),
      point(c.first, c.second));
  }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
// find_by_order(k),order_of_key(k)
template<typename T> ostream& operator << (ostream& os, ordered_set<T>& s) { os << "&{"; for (int i = 0; i < s.size(); ++i) { os << *s.find_by_order(i) << ","; } os << "}"; return os; }

pair<int, int> operator - (pair<int, int> a, pair<int, int> b)
{
  return make_pair(a.first - b.first, a.second - b.second);
}

vec<pair<int, int>> processors;
vec<pair<int, int>> sorters;
vec<vec<double>> probability;
vec<pair<double, int>> processor_declinations;
vec<double> sorter_declinations;
vec<int> used_sorters;
vec<int> affected_leaves;

inline int pick_sorter_weighted(void) {
  static vector<int> pool;
  if (pool.empty()) {
    for (int a : used_sorters) {
      int w = __builtin_popcount((unsigned)affected_leaves[a]);
      w = max(1, w);
      while (w--) pool.push_back(a);
    }
  }
  return pool[xorshift() % pool.size()];
}

int N; // 5<=N<=20
int M; // 10*N<=M<=50*N
int K; // N<N<=4N
int root;

inline bool is_processor_index(int idx) {
  return 0 <= idx && idx < N;
}

inline bool is_root_index(int idx) {
  return idx == root;
}

inline bool is_sorter_index(int idx) {
  return idx != -1 && !is_root_index(idx) && !is_processor_index(idx);
}

inline int to_sorter_index(int idx) {
#ifdef LOCAL
  assert(is_sorter_index(idx));
#endif
  return idx - N;
}

inline int to_processor_index(int idx) {
  return idx;
}

inline int random_sorter_index(void) {
  return N + xorshift() % M;
}

inline int random_processor_index(void) {
  return xorshift() % N;
}

const pair<int, int> S = make_pair(0, 5000);

inline lli dist(pair<int, int> a, pair<int, int> b) {
  lli x = a.first - b.first;
  lli y = a.second - b.second;
  x *= x;
  y *= y;
  return x + y;
}

inline pair<int, int> pos(int idx) {
  if (is_processor_index(idx)) return processors[to_processor_index(idx)];
  if (is_sorter_index(idx)) return sorters[to_sorter_index(idx)];
#ifdef LOCAL
  assert(is_root_index(idx));
#endif
  return S;
}

struct State {
  vec<int> parent;
  vec<pair<int, int>> child;
  int intersected;
  vec<int> processor_target;
  vec<int> sorter_target;
  double score;

  State() {
    parent.resize(N + M + 1);
    child.resize(N + M + 1);
  }

  bool rand_declination(void) {
    fill(parent.begin(), parent.end(), -1);
    fill(child.begin(), child.end(), make_pair(-1, -1));

    static vec<pair<double, int>> rest;
    {
      if (rest.size() != N - 1) rest.resize(N - 1);
      static int vis[1111];
      static int timestamp = 0;
      ++timestamp;
      for (int i = 0; i < rest.size(); ) {
        int idx = xorshift() % M + N;
#ifdef LOCAL
        assert(is_sorter_index(idx));
#endif
        if (vis[idx] == timestamp) continue;
        vis[idx] = timestamp;
        rest[i] = make_pair(sorter_declinations[idx - N], idx);
        ++i;
      }
    }
    sort(rest.begin(), rest.end());
    function<int(int, int)> fn = [&] (int begin, int end) {
#ifdef LOCAL
      assert(begin <= end);
#endif
      if (end - begin == 0) return -1;
      if (end - begin == 1) return rest[begin].second;
      const int mid = begin + (end - begin) / 2;
      const int a = fn(begin, mid);
      const int b = fn(mid + 1, end);
      const int c = rest[mid].second;
      child[c] = make_pair(a, b);
      if (a != -1) parent[a] = c;
      if (b != -1) parent[b] = c;
      return c;
    };
    const int top = fn(0, rest.size());
    child[root] = make_pair(top, -1);
    parent[top] = root;

    for (int i = 0, j = 0; i < rest.size(); ++i) {
      const int idx = rest[i].second;

      if (child[idx].first == -1) {
        int a = processor_declinations[j].second;
        child[idx].first = a;
        parent[a] = idx;
        ++j;
      }
      if (child[idx].second == -1) {
        int a = processor_declinations[j].second;
        child[idx].second = a;
        parent[a] = idx;
        ++j;
      }
    }

#ifdef LOCAL
    each (k, rest) {
      assert(child[k.second].first != -1);
      assert(child[k.second].second != -1);
    }
#endif
    return count_intersection() == 0;
  }

  void rand0() {
    fill(parent.begin(), parent.end(), -1);
    fill(child.begin(), child.end(), make_pair(-1, -1));

    vec<int> u(N);
    iota(u.begin(), u.end(), 0);
    sort(u.begin(), u.end(), [&] (auto a, auto b) { return processors.at(a).first < processors.at(b).first; });

    vec<int> v;
    {
      static int vis[1111];
      static int timestamp = 0;
      ++timestamp;
      while (v.size() < N - 1) {
        int idx = xorshift() % M + N;
#ifdef LOCAL
        assert(is_sorter_index(idx));
#endif
        if (vis[idx] == timestamp) continue;
        vis[idx] = timestamp;
        v.push_back(idx);
      }
    }
    sort(v.begin(), v.end(), [&] (auto a, auto b) { return sorters.at(a - N).first < sorters.at(b - N).first; });
#ifdef LOCAL
    assert(v.size() + 1 == u.size());
#endif
    const int tail1 = u.back(); u.pop_back();
    const int tail2 = u.back(); u.pop_back();
    int last = v.front();
    v.erase(v.begin());
    parent[last] = root;
    child[root] = make_pair(last, -1);

    for (int i = 0; i < v.size(); ++i) {
      parent[v.at(i)] = last;
      parent[u.at(i)] = last;
      child[last] = make_pair(v[i], u[i]);
      last = v[i];
    }
    parent[tail1] = last;
    parent[tail2] = last;
    child[last] = make_pair(tail1, tail2);

    count_intersection();
  }

  void validate() {
#ifdef LOCAL
    assert(parent[root] == -1);
    assert(is_sorter_index(child[root].first));
    assert(child[root].second == -1);
    for (int i = 0; i < N; ++i) {
      assert(child[i].first == -1);
      assert(child[i].second == -1);
      assert(parent[i] != -1);
      assert(is_sorter_index(parent[i]));
    }

    UnionFind uf(N + M + 1);
    for (int i = 0; i < N + M + 1; ++i) {
      if (parent[i] != -1) uf.unite(i, parent[i]);
    }
    assert(uf.size(root) == N * 2);
#endif
  }

  int count_intersection() {
    validate();
    vec<pair<pair<int, int>, pair<int, int>>> es;
    {
      static int vis[1111];
      static int timestamp = 0;
      ++timestamp;
      for (int i = 0; i < N; ++i) {
        int x = i;
        while (x != root) {
          if (vis[x] == timestamp) break;
          int y = parent[x];
          es.push_back({pos(x), pos(y)});
          vis[x] = timestamp;
          x = parent[x];
        }
      }
    }
    for (int i = 0; i < es.size(); ++i) {
      for (int j = i + 1; j < es.size(); ++j) {
        if (es[i].first == es[j].first || es[i].first == es[j].second) continue;
        if (es[i].second == es[j].first || es[i].second == es[j].second) continue;
        if (segments_intersect(es[i].first, es[i].second, es[j].first, es[j].second)) {
          return intersected = 1;
        }
      }
    }
    return intersected = 0;
  }

  double expected_score(void) {
    if (processor_target.empty()) {
      processor_target.resize(N);
      sorter_target.resize(M);
      iota(processor_target.begin(), processor_target.end(), 0);
      each (i, sorter_target) i = xorshift() % K;
    }

    score = 0;
    for (int i = 0; i < N; ++i) {
      const int target = processor_target[i];
      int idx = i;
      int prev = idx;
      idx = parent[idx];
      double P = 1.0;
      while (idx != root) {
        if (child[idx].first == prev) {
          P *= probability[sorter_target[idx - N]][target];
        } else {
          P *= 1.0 - probability[sorter_target[idx - N]][target];
        }
        prev = idx;
        idx = parent[idx];
      }
      score += P;
    }
    return score;
  }

  double expected_score_processor_target(int idx, int a, int b) {
    int prev = idx;
    idx = parent[idx];
    double P = 1.0;
    double Q = 1.0;
    while (idx != root) {
#ifdef LOCAL
      assert(child[idx].first == prev || child[idx].second == prev);
#endif
      if (child[idx].first == prev) {
        P *= probability[sorter_target[idx - N]][a];
        Q *= probability[sorter_target[idx - N]][b];
      } else {
        P *= 1.0 - probability[sorter_target[idx - N]][a];
        Q *= 1.0 - probability[sorter_target[idx - N]][b];
      }
      prev = idx;
      idx = parent[idx];
    }
    score -= P;
    score += Q;
    return score;
  }

  vec<tuple<int, double, vec<int>>> histories;
  void revert(void) {
    while (histories.size()) {
      auto [op, old_score, params] = histories.back();
      histories.pop_back();
      score = old_score;
      if (op == 0) {
        auto a = params[0];
        auto b = params[1];
        swap(processor_target[a], processor_target[b]);
      }
      if (op == 1) {
        auto a = params[0];
        auto old_target = params[1];
        sorter_target[a] = old_target;
      }
      if (op == 2) {
        auto a = params[0];
        swap(child[a].first, child[a].second);
      }
    }
    return ;
  }

  void commit(void) {
    histories.clear();
    return ;
  }

  double expected_score_for_sorter_target(int sorter_index, int old_target, int new_target) {
#ifdef LOCAL
    assert(is_sorter_index(sorter_index));
    assert(affected_leaves[sorter_index - N]);
#endif

    double sum = 0;
    unsigned mask = (unsigned)affected_leaves[sorter_index - N];
    while (mask) {
      unsigned lsb = mask & -mask;
      unsigned i = __builtin_ctz(lsb);
      mask ^= lsb;
      int idx = (int)i;
      int prev = idx;
      idx = parent[idx];
      double P = 1.0;
      double Q = 1.0;
      while (idx != root) {
        if (child[idx].first == prev) {
          P *= probability[sorter_target[idx - N]][processor_target[i]];
          if (idx == sorter_index) {
#ifdef LOCAL
            assert(sorter_target[idx - N] == old_target);
#endif
            Q *= probability[new_target][processor_target[i]];
          } else {
            Q *= probability[sorter_target[idx - N]][processor_target[i]];
          }
        } else {
          P *= 1.0 - probability[sorter_target[idx - N]][processor_target[i]];
          if (idx == sorter_index) {
#ifdef LOCAL
            assert(sorter_target[idx - N] == old_target);
#endif
            Q *= 1.0 - probability[new_target][processor_target[i]];
          } else {
            Q *= 1.0 - probability[sorter_target[idx - N]][processor_target[i]];
          }
        }
        prev = idx;
        idx = parent[idx];
      }
      score -= P;
      score += Q;
    }
    return score;
  }

  bool change_sorter_target(void) {
    int a;
    if (used_sorters.size()) {
      a = pick_sorter_weighted();
    } else {
      a = xorshift() % M;
    }

    while (true) {
      int new_target = xorshift() % K;
      if (sorter_target.at(a) == new_target) continue;
      histories.push_back(make_tuple(1, score, vec<int>({a, sorter_target[a]})));
      if (parent[a + N] == root) {
        sorter_target[a] = new_target;
        expected_score();
      } else {
        expected_score_for_sorter_target(a + N, sorter_target[a], new_target);
        sorter_target[a] = new_target;
      }
      break;
    }
    return true;
  }

  double delta_swap_children(int u) { // u は N..N+M-1
    unsigned mask = (unsigned)affected_leaves[u - N];
    int k = sorter_target[u - N];
    double delta = 0.0;
    while (mask) {
      unsigned lsb = mask & -mask; mask ^= lsb;
      int leaf = __builtin_ctz(lsb);

      // まず葉 leaf の現状成功確率 P を計算
      int prev = leaf, cur = parent[leaf];
      double P = 1.0;
      while (cur != root) {
        bool left = (child[cur].first == prev);
        int kk = sorter_target[cur - N];
        double p = probability[kk][processor_target[leaf]];
        P *= left ? p : (1.0 - p);
        prev = cur; cur = parent[cur];
      }

      // u における係数だけを反転（left <-> right）
      // was_left を求める
      prev = leaf; cur = parent[leaf];
      while (cur != u) { prev = cur; cur = parent[cur]; }
      bool was_left = (child[u].first == prev);

      double p = probability[k][processor_target[leaf]];
      double oldf = was_left ? p : (1.0 - p);
      double newf = was_left ? (1.0 - p) : p;

      // P' = P * (newf / oldf)
      delta += P * (newf / oldf - 1.0);
    }
    return delta;
  }

  bool swap_children(void) {
    int a;
    if (used_sorters.size()) {
      a = used_sorters[xorshift() % used_sorters.size()] + N;
    } else {
      a = xorshift() % M + N;
    }
    histories.emplace_back(2, score, vec<int>{a});
    score += delta_swap_children(a);
    swap(child[a].first, child[a].second);
    return true;
  }



  // ★ 追加：貪欲に最良ターゲットへ差し替えるバージョン
  bool improve_sorter_target_greedy(void) {
    int a = used_sorters.empty() ? (xorshift() % M) : pick_sorter_weighted(); // sorter idx in [0..M-1]
    const int u = a + N;                      // ノード番号
    const int oldk = sorter_target[a];

    // 左/右×クラス ごとの合算（u を除外した寄与 B_i を集計）
    vector<double> SL(N, 0.0), SR(N, 0.0);
    uint32_t mask = (uint32_t)affected_leaves[a];
    while (mask) {
      uint32_t lsb = mask & -mask; mask ^= lsb;
      int i = __builtin_ctz(lsb);             // 葉 i

      // i から u 直前まで登って、u に対して left/right を判定
      int prev = i, cur = parent[i];
      while (cur != u) { prev = cur; cur = parent[cur]; }
      bool isLeft = (child[u].first == prev);

      // B_i = (uを除く) 経路の積
      double B = 1.0;
      prev = i; cur = parent[i];
      while (cur != root) {
        if (cur == u) { prev = cur; cur = parent[cur]; continue; }
        int kk = sorter_target[cur - N];
        bool left = (child[cur].first == prev);
        double p = probability[kk][processor_target[i]];
        B *= left ? p : (1.0 - p);
        prev = cur; cur = parent[cur];
      }
      (isLeft ? SL : SR)[processor_target[i]] += B;
    }

    // 現ターゲットの値と、全kの中で最良の値を比較
    auto val_of = [&](int k)->double{
      double v = 0.0;
      for (int j = 0; j < N; ++j) v += SL[j] * probability[k][j] + SR[j] * (1.0 - probability[k][j]);
      return v;
    };
    double oldVal = val_of(oldk);
    int bestk = oldk; double bestVal = oldVal;
    for (int k = 0; k < K; ++k) {
      double v = val_of(k);
      if (v > bestVal) { bestVal = v; bestk = k; }
    }
    if (bestk == oldk) return false; // 改善なし

    // 反映（差分は bestVal - oldVal）
    histories.push_back(make_tuple(1, score, vec<int>({a, sorter_target[a]})));
    score += (bestVal - oldVal);
    sorter_target[a] = bestk;
    return true;
  }

  double assignment(void) {
    const int op = xorshift() % 2;
    if (op == 0) {
      // ランダム変更より貪欲改善を優先
      if (!improve_sorter_target_greedy()) {
        // 改善できないときだけランダムに揺らす
        change_sorter_target();
      }
    }
    if (op == 1) swap_children();
    return score;
  }
};

inline double cooling(double progress) {
  constexpr double START_TEMP   = 1e3;          // 初期温度
  constexpr double END_TEMP     = 1e-3;         // 最終温度
  // progress ∈ [0,1]、指数スケジュール
  return START_TEMP * pow(END_TEMP / START_TEMP, progress);
}

inline double rand01(void)
{
  // return (xorshift() >> 11) * (1.0 / (1ULL << 53));
  return xorshift() * (1.0 / 4294967296.0);
}

inline void show(const State& state, str path) {
  each (i, state.processor_target) cout << i << ' '; cout << "\n";
  cout << state.child[root].first << "\n";
  for (int i = 0; i < M; ++i) {
    if (state.child[N + i].first == -1) {
      cout << -1 << "\n";
    } else {
      cout << state.sorter_target.at(i) << ' ' << state.child[N + i].first << ' ' << state.child[N + i].second << "\n";
      assert(state.child[N + i].first != -1);
      assert(state.child[N + i].second != -1);
    }
  }
#ifdef LOCAL
  if (path.size()) {
    ofstream fout(path, std::fstream::app);
    fout << state.score << endl;
  }
#endif
  return ;
}


namespace GPT {
// Hungarian (Kuhn–Munkres) for MAX assignment on doubles.
// w: N x N matrix (score to maximize)
// matchR[j] = i  (column j is matched to row i), 0-indexed
// returns maximum total score (sum of w[matchR[j]][j])
  double hungarian_max(const vector<vector<double>>& w, vector<int>& matchR) {
    const int n = (int)w.size();
    if (n == 0) { matchR.clear(); return 0.0; }
    for (const auto& row : w) assert((int)row.size() == n);

    // Convert to minimization by negating.
    const double INF = 1e100;
    vector<vector<double>> a(n + 1, vector<double>(n + 1, 0.0));
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        a[i][j] = -w[i - 1][j - 1];

    vector<double> u(n + 1, 0.0), v(n + 1, 0.0);
    vector<int> p(n + 1, 0), way(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      p[0] = i;
      int j0 = 0;
      vector<double> minv(n + 1, INF);
      vector<char> used(n + 1, false);
      do {
        used[j0] = true;
        int i0 = p[j0];
        double delta = INF;
        int j1 = 0;
        for (int j = 1; j <= n; ++j) if (!used[j]) {
            double cur = a[i0][j] - u[i0] - v[j];
            if (cur < minv[j]) { minv[j] = cur; way[j] = j0; }
            if (minv[j] < delta) { delta = minv[j]; j1 = j; }
          }
        for (int j = 0; j <= n; ++j) {
          if (used[j]) { u[p[j]] += delta; v[j] -= delta; }
          else minv[j] -= delta;
        }
        j0 = j1;
      } while (p[j0] != 0);
      // augmenting
      do {
        int j1 = way[j0];
        p[j0] = p[j1];
        j0 = j1;
      } while (j0);
    }

    matchR.assign(n, -1);
    for (int j = 1; j <= n; ++j) {
      int i = p[j] - 1;      // row (0-indexed)
      int col = j - 1;       // column (0-indexed)
      matchR[col] = i;
    }

    double max_sum = 0.0;
    for (int j = 0; j < n; ++j) {
      int i = matchR[j];
      assert(i >= 0);
      max_sum += w[i][j];
    }
    return max_sum;
  }




  vector<vector<double>> Q;
  void run(State& best) {
    if (best.processor_target.empty()) {
      best.processor_target.resize(N);
      best.sorter_target.resize(M);
      iota(best.processor_target.begin(), best.processor_target.end(), 0);
      each (i, best.sorter_target) i = xorshift() % K;
    }

// 1) まず今の木・sorter_target 固定で、全 (i, j) の成功確率を作る
// path(i): i→root の親チェインを辿るだけなので O(N * 平均深さ)
    if (Q.empty()) {
      Q.resize(N, vector<double>(N, 0.0));
    }
    for (auto& r: Q) std::fill(r.begin(), r.end(), 0.0);

    for (int i = 0; i < N; ++i) {
      int cur = i, prev = i;
      // 各 j に対する確率を並行して更新する
      vector<double> v(N, 1.0);
      cur = best.parent[cur];
      while (cur != root) {
        int k = best.sorter_target[cur - N];
        bool left = (best.child[cur].first == prev);
        for (int j = 0; j < N; ++j) {
          double p = probability[k][j];
          v[j] *= left ? p : (1.0 - p);
        }
        prev = cur; cur = best.parent[cur];
      }
      for (int j = 0; j < N; ++j) Q[i][j] = v[j];
    }

// 2) ハンガリアン（最大化）
// NOTE: 実装済みがあれば流用。ここでは典型 O(N^3) を想定
    vector<int> matchR(N, -1); // 列側にどの行が入るか
    hungarian_max(Q, matchR);

// 3) 反映
    for (int col = 0; col < N; ++col) {
      int i = matchR[col];          // 行 i にタイプ col を割当
      best.processor_target[i] = col;
    }
// スコア再計算
    best.expected_score();
  }
};

constexpr double TIME_LIMIT = 1.93; // 実行時間（提出 TL − α）
constexpr double SA_T0      = 3.0;  // 焼き鈍し初期温度
constexpr double SA_T1      = 1e-3; // 焼き鈍し最終温度

int main(int argc, char *argv[])
{
  cin >> N >> M >> K;
  root = N + M;

  processors.resize(N);
  sorters.resize(M);
  probability.resize(K, vec<double>(N));
  cin >> processors >> sorters >> probability;

  // ★ 数値安定化：確率をクリップ
  for (int k = 0; k < K; ++k) for (int j = 0; j < N; ++j) {
    probability[k][j] = min(1.0 - 1e-9, max(1e-9, probability[k][j]));
  }

  for (int i = 0; i < processors.size(); ++i) {
    processor_declinations.push_back(make_pair(geo::angle(pos(i) - pos(root)), i));
  }
  sort(processor_declinations.begin(), processor_declinations.end());

  for (int i = 0; i < sorters.size(); ++i) {
    sorter_declinations.push_back(geo::angle(sorters[i] - pos(root)));;
  }

  const auto time_start = chrono::steady_clock::now();

  State best;
  if (1) {
    State curr;
    while (true) {
      double t = chrono::duration<double>(chrono::steady_clock::now() - time_start).count();
      if (t >= TIME_LIMIT / 2.0) break;
      curr.rand0();
      if (curr.intersected == 0) {
        best = curr;
        break;
      }
    }
#ifdef LOCAL
    GPT::run(best);
    cerr << (chrono::duration<double, std::milli>(chrono::steady_clock::now() - time_start)) << ",intersected:"<< best.intersected << ",expected:" << best.score << endl;
    assert(best.intersected == 0);
#endif
  }

  if (1) {
    State curr;
    while (true) {
      double t = chrono::duration<double>(chrono::steady_clock::now() - time_start).count();
      if (t >= TIME_LIMIT * 2.0 / 3.0) break;
      curr.rand_declination();
      if (curr.intersected == 0) {
        best = curr;
        break;
      }
    }
#ifdef LOCAL
    GPT::run(best);
    cerr << (chrono::duration<double, std::milli>(chrono::steady_clock::now() - time_start)) << ",intersected:"<< best.intersected << ",expected:" << best.score << endl;
    assert(best.intersected == 0);
#endif
  }

  {
    used_sorters.clear();
    for (int i = 0; i < N; ++i) {
      int x = i;
      while (x != root) {
        if (is_sorter_index(x)) used_sorters.push_back(x - N);
        x = best.parent[x];
      }
    }
    sort(used_sorters.begin(), used_sorters.end());
    used_sorters.erase(unique(used_sorters.begin(), used_sorters.end()), used_sorters.end());
  }
  {
    affected_leaves.resize(M);
    fill(affected_leaves.begin(), affected_leaves.end(), 0);
    for (int i = 0; i < N; ++i) {
      int x = best.parent[i];
      while (x != root) {
        if (is_sorter_index(x)) affected_leaves[x - N] |= (1 << i);
        x = best.parent[x];
      }
    }
  }

  int loop = 0, updated = 0;
  GPT::run(best);
  State curr = best;
  for (; ; ++loop) {
    double t = chrono::duration<double>(chrono::steady_clock::now() - time_start).count();
    if (t >= TIME_LIMIT) break;
    double progress = t / TIME_LIMIT;
    double temp = cooling(progress);
    const double old_score = curr.score;
    curr.assignment();
    GPT::run(curr);
    double diff = curr.score - old_score;
    bool accept = (diff > 0);
    unless (accept) {
      double x = diff / temp;
      // オーバー/アンダーフロー回避
      if (x < -50.0) x = -50.0;
      if (x >  50.0) x =  50.0;
      double prob = exp(x);
      accept = (rand01() < prob);
    }

    if (accept) {
      curr.commit();
      if (best.score < curr.score) {
        best = curr;
        ++updated;
      }
    } else {
      curr.revert();
    }
  }
  str path = "";
  if (argc == 2) path = str(argv[1]);
  show(best, path);
#ifdef LOCAL
  cerr << "loop:" << loop << ",intersected:"<< best.intersected << ",expected:" << best.score << ",updated:=" << updated << ",score:=" << (lli)round(1e9 * (N - best.score) / N) << endl;
  assert(best.intersected == 0);
#endif

  return 0;
}
