// github.com/Johniel/contests
// codeforces/927div3/C/main.cpp

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

template<typename T>
struct SegTree {
  const int n;
  const int origin_size;
  vector<T> v;
  using F = function<T(T, T)>;
  const F fn;
  const T e;
  SegTree(size_t n_, T e_, F fn_) : e(e_), origin_size(n_), fn(fn_), n(bit_ceil(n_)) {
    assert(fn(e, e) == e);
    v.resize(2 * n - 1, e);
  }
  SegTree(const vector<T>& v, T e_, F fn_) : SegTree(v.size(), e_, fn_) {
    for (int i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    k += n - 1;
    v[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      v[k] = fn(v[k * 2 + 1], v[k * 2 + 2]);
    }
    return ;
  }
  inline T get(size_t idx) const { return v.at(idx + n - 1); }
  inline T operator [] (size_t idx) const { return get(idx); }
  inline T operator () (void) const { return query(0, origin_size, 0, 0, n); }
  inline T operator () (size_t begin, size_t end) const { return query(begin, end, 0, 0, n); }
  inline T all_prod(void) const { return query(0, origin_size, 0, 0, n); }
  inline T prod(size_t begin, size_t end) const { return query(begin, end, 0, 0, n); }
  inline T query(size_t begin, size_t end) const {
    assert(begin <= end);
    assert(end <= origin_size);
    return query(begin, end, 0, 0, n);
  }
  T query(size_t a, size_t b, size_t k, size_t l, size_t r) const {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return v.at(k);
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return fn(vl, vr);
  }
  size_t size(void) const { return origin_size; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.origin_size; ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { vector<T> v; for (int i = 0; i < seg.n; ++i) v.push_back(seg[i]); os << v; return os; }

template<typename T>
int max_right(SegTree<T>& seg, const int left, function<bool(T)> pred)
{
  // verified: ABC330E
  assert(left <= seg.size());
  assert(pred(seg.e));
  int small = left;
  int large = seg.size();
  while (small + 1 < large) {
    int mid = (small + large) / 2;
    if (pred(seg(left, mid))) small = mid;
    else large = mid;
  }
  return pred(seg(left, large)) ? large : small;
  // MEX:
  // SegTree<int> seg(N, (1 << 29), [] (auto i, auto j) { return min(i, j); });
  // max_right<int>(seg, 0, [] (int x) { return (0 < x); })
}


// from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
lli MOD;
struct Fp {
  long long val;
  Fp(long long v = 0) : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  int getmod() { return MOD; }
  Fp operator - () const {
    return val ? MOD - val : 0;
  }
  Fp operator + (const Fp& r) const { return Fp(*this) += r; }
  Fp operator - (const Fp& r) const { return Fp(*this) -= r; }
  Fp operator * (const Fp& r) const { return Fp(*this) *= r; }
  Fp operator / (const Fp& r) const { return Fp(*this) /= r; }
  Fp& operator += (const Fp& r) {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  Fp& operator -= (const Fp& r) {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  Fp& operator *= (const Fp& r) {
    val = val * r.val % MOD;
    return *this;
  }
  Fp& operator /= (const Fp& r) {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  bool operator == (const Fp& r) const {
    return this->val == r.val;
  }
  bool operator != (const Fp& r) const {
    return this->val != r.val;
  }
};
istream& operator >> (istream& is, Fp& m) { is >> m.val; m.val %= MOD; return is; }
ostream& operator << (ostream& os, const Fp& m) { os << m.val; return os; }
using mint = Fp;

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n >> MOD) {
    vec<mint> a(n);
    str s;
    cin >> a >> s;
    SegTree<mint> seg(a, mint(1), [] (auto x, auto y) { return x * y; });
    int i = 0;
    int j = n;
    each (c, s) {
      cout << seg(i, j) << ' ';
      if (c == 'L') ++i;
      if (c == 'R') --j;
    }
    cout << endl;
  }

  return 0;
}
