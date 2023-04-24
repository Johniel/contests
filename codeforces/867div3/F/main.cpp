// github.com/Johniel/contests
// codeforces/867div3/F/main.cpp

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

template<typename T=long long int>
class LazySegTree {
public:
  using merge_fn = function<T(T,T)>;
  using propagate_fn = function<T(T,T)>;
  using apply_fn = function<T(T,T,size_t)>;

  LazySegTree(int n_, merge_fn m_, propagate_fn p_, apply_fn a_, T em_, T ep_)
    : m(m_), p(p_), a(a_), em(em_), ep(ep_)
  {
    size_ = n_;
    n = 1;
    while (n < n_) n *= 2;
    value.resize(n * 2 - 1, em);
    lazy.resize(n * 2 - 1, ep);
  }

  T query(size_t begin, size_t end)
  {
    assert(begin < end);
    assert(end <= size_);
    return query(begin, end, 0, 0, n);
  }

  T update(size_t begin, size_t end, T x)
  {
    assert(begin < end);
    assert(end <= size_);
    return update(begin, end, x, 0, 0, n);
  }

  static bool verify(void) {
    using input = struct {
      int begin, end, value;
    };
    vector<input> v;
    v.push_back({0, 5, 1 << 0});
    v.push_back({8, 9, 1 << 2});
    v.push_back({3, 6, 1 << 3});

    constexpr int N = 10;

    LazySegTree<int>::merge_fn m = [] (int a, int b) {
      return a + b;
    };
    LazySegTree<int>::propagate_fn p = [] (int a, int b) {
      return a + b;
    };
    LazySegTree<int>::apply_fn a = [] (int a, int b, size_t len) {
      return a + b * len;
    };
    LazySegTree<int> segtree(N, m, p, a, 0, 0);

    int sum[N];
    fill(begin(sum), end(sum), 0);
    for (int i = 0; i < v.size(); ++i) {
      for (int j = v[i].begin; j < v[i].end; ++j) {
        sum[j] += v[i].value;
      }
    }

    for (int i = 0; i < v.size(); ++i) {
      segtree.update(v[i].begin, v[i].end, v[i].value);
    }

    for (int i = 0; i < N; ++i) {
      int expected = 0;
      for (int j = i; j < N; ++j) {
        expected += sum[j];
        if (expected != segtree.query(i, j + 1)) return false;
      }
    }

    return true;
  }

  void show(int idx = 0, int depth = 0) {
    if (idx < value.size()) {
      cout << string(depth, ' ') << make_pair(value[idx], lazy[idx]) << endl;
      show(idx * 2 + 1, depth + 2);
      show(idx * 2 + 2, depth + 2);
    }
    return ;
  }

private:
  vector<T> value;
  vector<T> lazy;
  int n;
  size_t size_;

  merge_fn m;
  apply_fn a;
  propagate_fn p;
  T em;
  T ep;

  void propagate(int k, size_t l, size_t r) {
    if (lazy[k] == ep) return ;
    if(r - l > 1) {
      lazy[2 * k + 1] = p(lazy[2 * k + 1], lazy[k]);
      lazy[2 * k + 2] = p(lazy[2 * k + 2], lazy[k]);
    }
    value[k] = a(value[k], lazy[k], r - l);
    lazy[k] = ep;
    return ;
  }

  T update(size_t begin, size_t end, T x, size_t k, size_t l, size_t r) {
    propagate(k, l, r);
    if (r <= begin || end <= l) return value[k];

    if (begin <= l && r <= end) {
      lazy[k] = p(lazy[k], x);
      propagate(k, l, r);
      return value[k];
    } else {
      T vl = update(begin, end, x, k * 2 + 1, l, (l + r) / 2);
      T vr = update(begin, end, x, k * 2 + 2, (l + r) / 2, r);
      return value[k] = m(vl, vr);
    }
  }

  T query(size_t begin, size_t end, size_t k, size_t l, size_t r) {
    if (r <= begin || end <= l) return em;
    propagate(k, l, r);

    if (begin <= l && r <= end) {
      return value[k];
    } else {
      T vl = query(begin, end, k * 2 + 1, l, (l + r) / 2);
      T vr = query(begin, end, k * 2 + 2, (l + r) / 2, r);
      return m(vl, vr);
    }
  }
};

const int N = 2 * 1e5 + 3;
vec<int> g[N];
int cnt;
int pre[N];
int post[N];
LazySegTree<int>::merge_fn _m = [] (int a, int b) { return max(a, b); };
LazySegTree<int>::propagate_fn _p = [] (int a, int b) { return a + b; };
LazySegTree<int>::apply_fn _a = [] (int a, int b, size_t _) { return a + b; };
LazySegTree<int> seg(2*N, _m, _p, _a, 0, 0);

void rec(int curr, int prev, LazySegTree<int>& seg)
{
  pre[curr] = cnt++;
  each (next, g[curr]) {
    if (next == prev) continue;
    rec(next, curr, seg);
  }
  post[curr] = cnt++;
  seg.update(pre[curr], post[curr] + 1, +1);
  return ;
}

int n;
lli k, c;
lli fn(int curr, int prev, LazySegTree<int>& seg, lli w)
{
  lli z = seg.query(0, 2*n) * k - w;
  each (next, g[curr]) {
    if (next == prev) continue;
    seg.update(0, 2*n, +1);
    seg.update(pre[next], post[next] + 1, -2);
    setmax(z, fn(next, curr, seg, w + c));
    seg.update(0, 2*n, -1);
    seg.update(pre[next], post[next] + 1, +2);
  }
  return z;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  while (cin >> n >> k >> c) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    cnt = 0;
    for (int i = 0; i < 2*n; ++i) {
      seg.update(i, i + 1, -seg.query(i, i + 1));
    }
    rec(0, 0, seg);
    seg.update(0, 2*n, -1);
    cout << fn(0, 0, seg, 0) << endl;
  }
  return 0;
}
