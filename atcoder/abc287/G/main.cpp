// github.com/Johniel/contests
// atcoder/abc287/G/main.cpp

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

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n) {
    vec<pair<lli, int>> v;
    for (int i = 0; i < n; ++i) {
      lli a;
      int b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    const int N = 4 * 1e5 + 3;
    static int idx[N];
    iota(idx, idx + n, 0);
    int cnt = n;
    cin >> q;
    vec<vec<lli>> cmds;
    for (int i = 0; i < q; ++i) {
      int op;
      cin >> op;
      if (op == 1) {
        int x;
        lli y;
        cin >> x >> y;
        --x;
        int prev = idx[x];
        x = (idx[x] = cnt++);
        v.push_back(make_pair(y, 0));
        cmds.push_back(vec<lli>({1, prev, x}));
      }
      if (op == 2) {
        int x, y;
        cin >> x >> y;
        --x;
        x = idx[x];
        cmds.push_back(vec<lli>({2, x, y}));
      }
      if (op == 3) {
        int x;
        cin >> x;
        cmds.push_back(vec<lli>({3, x}));
      }
    }
    vec<int> u(v.size());
    iota(u.begin(), u.end(), 0);
    sort(u.begin(), u.end(), [&] (auto a, auto b) { return v[a].first > v[b].first; });
    vec<int> r(u.size());
    for (int i = 0; i < u.size(); ++i) {
      r[u[i]] = i;
    }
    SegTree<lli> seg(cnt+1, 0, [] (auto a, auto b) { return a + b; });
    SegTree<lli> B(cnt+1, 0, [] (auto a, auto b) { return a + b; });
    for (int i = 0; i < v.size(); ++i) {
      seg.update(i, v[u[i]].first * v[u[i]].second);
      B.update(i, v[u[i]].second);
    }

    int j = n;
    for (int _ = 0; _ < cmds.size(); ++_) {
      const vec<lli>& cmd = cmds[_];
      if (cmd.front() == 1) {
        int i = cmd[1];
        int j = cmd[2];
        v[j].second = v[i].second;
        v[i].second = 0;
        seg.update(r[i], v[i].first * v[i].second);
        seg.update(r[j], v[j].first * v[j].second);
        B.update(r[i], v[i].second);
        B.update(r[j], v[j].second);
      }
      if (cmd.front() == 2) {
        int i = cmd[1];
        lli b = cmd[2];
        v[i].second = b;
        seg.update(r[i], v[i].first * v[i].second);
        B.update(r[i], v[i].second);
      }
      if (cmd.front() == 3) {
        const lli x = cmd[1];
        int small = 0;
        int large = u.size();
        while (small + 1 < large) {
          int mid = (small + large) / 2;
          if (x < B.query(0, mid)) large = mid;
          else small = mid;
        }
        if (B() < x) cout << -1 << endl;
        else {
          lli z = seg.query(0, large - 1);
          lli used = B.query(0, large - 1);
          z += (x - used) * v[u[large-1]].first;
          cout << z << endl;
        }
      }
    }
  }
  return 0;
}
