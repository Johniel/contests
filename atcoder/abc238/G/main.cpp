// atcoder/abc238/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

struct Mo {
  // ABC238G
  using Add = function<void(int)>;
  using Del = function<void(int)>;
  using Report = function<void(int)>;
  // ある区間の解が分かっている状態で、その両端のどちらかを±1した区間の解がO(α)で求まるときに
  // 区間に対するクエリ列てに対してO(αQ√N)で答える。
  // ※クエリは半開区間。
  void run(
    const int N,
    const vec<pair<int, int>>& qs,
    Add add_left,
    Del del_left,
    Add add_right,
    Del del_right,
    Report report
    ) {
    vec<int> ord(qs.size());
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (auto i, auto j) {
      if (qs[i].first / N < qs[j].first / N) return true;
      if (qs[i].first / N == qs[j].first / N && qs[i].second < qs[j].second) return true;
      return false;
    });
    int begin = 0;
    int end = 0;
    each (i, ord) {
      while (begin > qs[i].first) add_left(--begin);
      while (begin < qs[i].first) del_left(begin++);
      while (end < qs[i].second) add_right(end++);
      while (end > qs[i].second) del_right(--end);
      report(i);
    }
    return ;
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
    assert(a < b);
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

int main(int argc, char *argqs[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 1e6 + 5;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<int> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }
  map<int, vec<int>> zobrist;
  srand(0);
  each (i, p) {
    int a = rand();
    int b = rand();
    zobrist[i].push_back(a);
    zobrist[i].push_back(b);
    zobrist[i].push_back(a ^ b);
  }

  int n, q;
  while (cin >> n >> q) {
    vec<lli> a(n);
    cin >> a;
    vec<pair<int, int>> v(q);
    cin >> v;
    each (i, v) --i.first;

    int m[n];
    fill(m, m + n, 0);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      for (int j = 2; j * j <= x; ++j) {
        while (x % j == 0) {
          x /= j;
          assert(zobrist.count(j));
          assert(zobrist[j].size() == 3);
          m[i] ^= zobrist[j][cnt[j]++];
          cnt[j] %= zobrist[j].size();
        }
      }
      if (x != 1) {
        m[i] ^= zobrist[x][cnt[x]++];
        cnt[x] %= 3;
      }
    }

    SegTree<int> seg(n, 0, [] (auto a, auto b) { return a ^ b; });
    for (int i = 0; i < n; ++i) {
      seg.update(i, m[i]);
    }
    each (i, v) {
      cout << (seg(i.first, i.second) == 0 ? "Yes" : "No") << endl;
    }
  }

  return 0;
}
