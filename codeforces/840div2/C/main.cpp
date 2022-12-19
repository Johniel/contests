// github.com/Johniel/contests
// codeforces/840div2/C/main.cpp

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

uint32_t xorshift(void)
{
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

void fn(void)
{
  const int N = 8;
  vec<int> ini;
  for (int i = 0; i < N; ++i) {
    ini.push_back((xorshift() % 80) + 1);
  }

  vec<vec<int>> curr;
  curr.push_back(ini);
  for (int _ = 0; _ < 10; ++_) {
    map<int, vec<int>> next;
    each (v, curr) {
      for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
          vec<int> u = v;
          int x = abs(u[i] - u[j]);
          fill(u.begin() + i, u.begin() + j + 1, x);
          int sum = accumulate(u.begin(), u.end(), 0);
          next[sum] = u;
          // if (sum == 272 && u.back()) cout << "272," << make_pair(i, j) << ' ' << u[i] << ' ' << u[j] << ' ' << v << endl;
        }
      }
    }
    curr.clear();
    each (i, next) curr.push_back(i.second);
    reverse(curr.begin(), curr.end());
    while (100 < curr.size()) curr.pop_back();
  }
  while (10 < curr.size()) curr.pop_back();
  cout << "ini:" << ini << endl;
  each (i, curr) cout << i << ": " << accumulate(i.begin(), i.end(), 0) << endl;

  return ;
}

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
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

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  // fn(); return 0;

  lli n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    PrefixSum<lli> sum(a);

    lli mx = accumulate(a.begin(), a.end(), 0LL);

    for (lli i = 0; i < a.size(); ++i) {
      if (2 <= i && i + 2 < n) {
        setmax(mx, a[i] * n);
      }
      if (i + 2 < n) {
        lli z = sum(0, i) + a[i] * (n - i);
        setmax(mx, z);
        setmax(mx, a[i] * n);
      }
      if (2 <= i) {
        lli z = sum(i + 1, n) + a[i] * (i + 1);
        setmax(mx, z);
        setmax(mx, a[i] * n);
      }

      if (1 == i && i + 2 < n) {
        {
          lli z = a[i] * (n - 2) + abs(a[0] - a[1]) * 2;
          setmax(mx, z);
        }
        {
          lli z = a[i] * (n - 2) + a[0] + a[1];
          setmax(mx, z);
        }
      }
      if (2 <= i && i + 2 == n) {
        {
          lli z = a[i] * (n - 2) + abs(a[i] - a[i + 1]) * 2;
          setmax(mx, z);
        }
        {
          lli z = a[i] * (n - 2) + a[i] + a[i + 1];
          setmax(mx, z);
        }
      }
    }

    if (n == 2) {
      setmax(mx, abs(a[0] - a[1]) * 2);
    }
    if (n == 3) {
      setmax(mx, a[0] + abs(a[1] - a[2]) * 2);
      setmax(mx, abs(a[0] - a[1]) * 2 + a[2]);
      {
        lli x = abs(a[0] - a[1]);
        setmax(mx, x + abs(x - a[2]) * 2);
      }
      {
        lli x = abs(a[1] - a[2]);
        setmax(mx, x + abs(x - a[0]) * 2);
      }
      {
        setmax(mx, abs(a[0] - a[1]) * 3);
        setmax(mx, abs(a[1] - a[2]) * 3);
      }
    }

    SegTree<lli> seg(n, 0, [] (auto x, auto y) { return max(x, y); });
    for (int i = 0; i < a.size(); ++i) {
      seg.update(i, a[i]);
    }
    if (4 <= n) {
      lli x = seg(1, n);
      setmax(mx, x * (n - 2) + abs(x - a[0]) * 2);
    }
    if (4 <= n) {
      lli x = seg(0, n - 1);
      setmax(mx, x * (n - 2) + abs(x - a[n - 1]) * 2);
    }
    if (5 <= n) {
      lli x = seg(1, n - 1);
      setmax(mx, x * (n - 4) + abs(x - a.back()) * 2 + abs(x - a.front()) * 2);
    }
    cout << mx << endl;
  }

  return 0;
}
