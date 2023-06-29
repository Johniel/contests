// github.com/Johniel/contests
// codeforces/881div3/F/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];
namespace HLD {
  // https://atcoder.jp/contests/abc269/editorial/4838
  // https://codeforces.com/blog/entry/53170
  // https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85
  int size[N];
  int pre[N];
  int parent[N];
  int post[N];
  int head[N];

  int dfs_size(int curr, int prev) {
    parent[curr] = prev;
    size[curr] = 1;
    each (next, g[curr]) {
      if (next == curr) continue;
      size[curr] += dfs_size(next, curr);
      if(size[next] > size[g[curr][0]]) {
        swap(next, g[curr][0]);
      }
    }
    return size[curr];
  }

  void dfs_hld(int curr, int prev, int& ord) {
    pre[curr] = ord++;
    each (next, g[curr]) {
      if (prev == next) continue;
      head[next] = (next == g[curr][0] ? head[curr] : next);
      dfs_hld(next, curr, ord);
    }
    post[curr] = ord;
    return ;
  }

  void build(int root, const int N) {
    iota(head, head + N, 0);
    dfs_size(root, root);
    int ord = 0;
    dfs_hld(root, root, ord);
    return ;
  }

  // a,bは頂点番号
  // fnの引数はpre-orderの順序
  void edge_query(int a, int b, const function<void(int, int)>& fn) {
    while (true) {
      unless (pre[a] < pre[b]) swap(a, b);
      fn(max(pre[a], pre[head[b]]), pre[b] + 1);
      if (head[a] == head[b]) break;
      b = parent[head[b]];
    }
    return ;
  }

  void vertex_query(int a, int b, const function<void(int, int)>& fn) {
    while (true) {
      unless (pre[a] < pre[b]) swap(a, b);
      if (head[a] == head[b]) {
        if (a != b) fn(pre[a] + 1, pre[b] + 1);
          break;
      } else {
        fn(pre[head[b]], pre[b] + 1);
        b = parent[head[b]];
      }
    }
    return ;
  }

  int LCA(int a, int b) {
    while (true) {
      unless (pre[a] < pre[b]) swap(a, b);
      if (head[a] == head[b]) return a;
      b = parent[head[b]];
    }
    assert(false);
  }
};

template<typename T>
struct SegTree {
  int n;
  int origin_size;
  vector<T> v;
  using F = function<T(T, T)>;
  F fn;
  T e;
  SegTree(int n_, T e_, F fn_) {
    origin_size = n_;
    e = e_;
    fn = fn_;
    n = 1;
    while (n < n_) n *= 2;
    v.resize(2 * n - 1, e);
  }

  void update(size_t k, T a) {
    k += n - 1;
    v[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      v[k] = fn(v[k * 2 + 1], v[k * 2 + 2]);
    }
    return ;
  }

  T operator [] (size_t idx) const {
    return v.at(idx + n - 1);
  }

  inline T operator () () const {
    return query(0, origin_size, 0, 0, n);
  }

  inline T operator () (size_t a) const {
    return query(a, a+1, 0, 0, n);
  }

  inline T operator () (size_t a, size_t b) const {
    return query(a, b, 0, 0, n);
  }

  inline T query(size_t a, size_t b) const {
    assert(a <= b);
    assert(b <= origin_size);
    return query(a, b, 0, 0, n);
  }

  T query(size_t a, size_t b, size_t k, size_t l, size_t r) const {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return v.at(k);

    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return fn(vl, vr);
  }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.n; ++i) { T t; is >> t; seg.update(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { vector<T> v; for (int i = 0; i < seg.n; ++i) v.push_back(seg[i]); os << v; return os; }

struct Op {
  char c;
  int src, dst, k;
  int parent, x;
};

struct Val {
  int minL, maxL;
  int minR, maxR;
  int minS, maxS;
  int whole;
  Val() {
    minL = maxL = minR =  maxR = minS = maxS = whole = 0;
  }
  Val(int x) {
    whole = x;

    minL = min(x, 0);
    minR = min(x, 0);
    minS = min(x, 0);

    maxL = max(x, 0);
    maxR = max(x, 0);
    maxS = max(x, 0);
  }
};
ostream& operator << (ostream& os, Val& v)
{
  vec<pair<int, int>> u;
  u.push_back(make_pair(v.minL, v.maxL));
  u.push_back(make_pair(v.minR, v.maxR));
  u.push_back(make_pair(v.minS, v.maxS));
  os << '<' << u << "," << v.whole << '>';
  return os;
}

Val merge(Val a, Val b)
{
  Val v;

	v.whole = a.whole + b.whole;

  v.minL = min(a.minL, a.whole + b.minL);
	v.maxL = max(a.maxL, a.whole + b.maxL);

	v.minR = min(b.whole + a.minR, b.minR);
	v.maxR = max(b.whole + a.maxR, b.maxR);

  v.minS = min({a.minS, b.minS, a.minR + b.minL});
  v.maxS = max({a.maxS, b.maxS, a.maxR + b.maxL});


  // res.sum = a.sum + b.sum;
  // res.minPrefL = min(a.minPrefL, a.sum + b.minPrefL);
  // res.maxPrefL = max(a.maxPrefL, a.sum + b.maxPrefL);
  // res.minPrefR = min(a.minPrefR + b.sum, b.minPrefR);
  // res.maxPrefR = max(a.maxPrefR + b.sum, b.maxPrefR);
  // res.minSeg = min({a.minSeg, b.minSeg, a.minPrefR + b.minPrefL});
  // res.maxSeg = max({a.maxSeg, b.maxSeg, a.maxPrefR + b.maxPrefL});

  return v;
}

int mn[N];
int mx[N];
int x[N];

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int q;
  while (cin >> q) {
    const int n = q;
    fill(g, g + n, vec<int>());
    vec<Op> v;
    while (q--) {
      Op op;
      cin >> op.c;
      if (op.c == '+') {
        cin >> op.parent >> op.x;
        --op.parent;
      }
      if (op.c == '?') {
        cin >> op.src >> op.dst >> op.k;
        --op.src;
        --op.dst;
      }
      v.push_back(op);
    }

    int size = 1;
    vec<int> xs({1});
    each (op, v) {
      if (op.c == '+') {
        int src = op.parent;
        int dst = size;
        g[src].push_back(dst);
        xs.push_back(op.x);
        ++size;
      }
    }

    HLD::build(0, size);
    vec<int> rev(size);
    for (int i = 0; i < size; ++i) {
      rev[HLD::pre[i]] = i;
    }

    SegTree<Val> seg(size, Val(), [] (Val a, Val b) { return merge(a, b); });
    for (int i = 0; i < size; ++i) {
      int x = xs[rev[i]];
      seg.update(i, Val(x));
    }

    each (op, v) {
      if (op.c == '?') {
        const int a = op.src;
        const int b = op.dst;
        const int lca = HLD::LCA(a, b);

        Val s;
        HLD::edge_query(a, lca, [&] (int l, int r) { s = merge(seg.query(l, r), s); });

        Val t;
        HLD::vertex_query(b, lca, [&] (int l, int r) { t = merge(seg.query(l, r), t); });

        swap(s.minL, s.minR);
        swap(s.maxL, s.maxR);
        Val z = merge(s, t);

        if (z.minS <= op.k && op.k <= z.maxS) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
  }

  return 0;
}
