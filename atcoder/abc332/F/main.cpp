// github.com/Johniel/contests
// atcoder/abc332/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }

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

// from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
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
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
template<int MOD> istream& operator >> (istream& is, Fp<MOD>& m) { is >> m.val; m.val %= MOD; return is; }
template<int MOD> ostream& operator << (ostream& os, const Fp<MOD>& m) { os << m.val; return os; }
using mint = Fp<mod>;

template<typename S, typename F>
class LazySegTree {
public:
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>;

  LazySegTree(int n_, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : size(n_), op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_) {
    n = 1;
    lgn = 0;
    while (n < n_) {
      ++lgn;
      n *= 2;
    }
    value.resize(n * 2 - 1, e);
    lazy.resize(n * 2 - 1, id);
  }

  void set(size_t i, S x) {
    assert(0 <= i && i < size);
    get(i);
    i += n - 1;
    value[i] = x;
    while (0 < i) {
      i = (i - 1) / 2;
      value[i] = op(value.at(i * 2 + 1), value.at(i * 2 + 2));
    }
    return ;
  }

  inline S get(size_t i) { return query(i, i + 1); }
  inline S query(void) { return query(0, size); };
  S query(size_t begin, size_t end) {
    assert(begin <= end);
    assert(end <= size);
    return query(begin, end, 0, 0, n);
  }

  inline S apply(size_t i, F f) { return apply(i, i + 1, f); }
  S apply(size_t begin, size_t end, F f) {
    assert(begin <= end);
    assert(end <= size);
    return apply(begin, end, f, 0, 0, n);
  }

  void show(int idx = 0, int depth = 0) const {
    if (idx < value.size()) {
      cout << string(depth, ' ') << make_pair(value[idx], lazy[idx]) << endl;
      show(idx * 2 + 1, depth + 2);
      show(idx * 2 + 2, depth + 2);
    }
    return ;
  }

  int max_right(int i, function<bool(S)> pred) {
    assert(pred(e));
    int small = i;
    int large = size;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (pred(query(i, mid))) small = mid;
      else large = mid;
    }
    // unless (pred(query(i, small))) return i;
    return small;
  }

  int min_left() {
    assert("not implemented");
    return 0;
  }

private:
  vector<S> value;
  vector<F> lazy;
  int n;
  int lgn;
  const size_t size;

  op_fn op;
  composition_fn composition;
  mapping_fn mapping;
  const S e;
  const F id;

  inline void push(int k) {
    if(2 * k + 2 < lazy.size()) {
      lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
      lazy[2 * k + 2] = composition(lazy[k], lazy[2 * k + 2]);
    }
    value[k] = mapping(lazy[k], value[k]);
    lazy[k] = id;
    return ;
  }

  S apply(size_t begin, size_t end, F f, size_t k, size_t l, size_t r) {
    push(k);
    if (r <= begin || end <= l) return value[k];

    if (begin <= l && r <= end) {
      lazy[k] = composition(f, lazy[k]);
      push(k);
      return value[k];
    } else {
      S vl = apply(begin, end, f, k * 2 + 1, l, (l + r) / 2);
      S vr = apply(begin, end, f, k * 2 + 2, (l + r) / 2, r);
      return value[k] = op(vl, vr);
    }
  }

  S query(size_t begin, size_t end, size_t k, size_t l, size_t r) {
    if (r <= begin || end <= l) return e;
    push(k);

    if (begin <= l && r <= end) {
      return value[k];
    } else {
      S vl = query(begin, end, k * 2 + 1, l, (l + r) / 2);
      S vr = query(begin, end, k * 2 + 2, (l + r) / 2, r);
      return op(vl, vr);
    }
  }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<mint> a(n);
    vec<int> begin(m);
    vec<int> end(m);
    vec<mint> x(m);
    cin >> a;
    for (int i = 0; i < m; ++i) {
      cin >> begin[i] >> end[i] >> x[i];
      --begin[i];
    }

    LazySegTree<mint, pair<mint, mint>>::op_fn op = [] (auto a, auto b) {
      return a + b;
    };
    LazySegTree<mint, pair<mint, mint>>::mapping_fn mapping = [] (auto f, auto s) {
      return s * f.first + f.second;
    };
    LazySegTree<mint, pair<mint, mint>>::composition_fn composition = [] (auto l, auto r) {
      return make_pair(l.first * r.first, r.second * l.first + l.second);
    };

    LazySegTree<mint, pair<mint, mint>> seg(a.size(), op, mapping, composition, mint(0), pair<mint, mint>(mint(1), mint(0)));
    for (int i = 0; i < a.size(); ++i) {
      seg.set(i, a[i]);
    }

    for (int i = 0; i < m; ++i) {
      const mint p = mint(1) / mint(end[i] - begin[i]);
      const mint s = (mint(1) - p);
      const mint t = x[i] * p;
      seg.apply(begin[i], end[i], make_pair(s, t));
    }
    for (int i = 0; i < n; ++i) cout << seg.get(i) << ' '; cout << endl;
  }
  return 0;
}
