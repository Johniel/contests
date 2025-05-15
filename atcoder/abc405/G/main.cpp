// github.com/Johniel/contests
// atcoder/abc405/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

namespace Mo {
  // ABC242G,ABC293G

  // MEMO: pair<int,int>にせずとも外に状態を持てるから注意すること。ただしmapへのアクセスは避ける。
  using Push = function<void(int)>;
  using Pop = function<void(int)>;
  using Report = function<void(int)>;

  inline bool cmp(const int& N, const pair<int, int>& a, const pair<int, int>& b)
  {
    if (a.first / N != b.first / N) return a.first / N < b.first / N;
    if ((a.first / N) % 2) {
      return a.second < b.second;
    } else {
      return a.second > b.second;
    }
  }

  // ある区間の解が分かっている状態で、その両端のどちらかを±1した区間の解がO(α)で求まるときに
  // 区間に対するクエリ列てに対してO(αQ√N)で答える。
  // ※クエリは半開区間。
  void run(
    const int N,
    const vec<pair<int, int>>& qs,
    const Push& pushFront,
    const Pop& popFront,
    const Push& pushBack,
    const Pop& popBack,
    const Report& report)
  {
    vec<int> idx(qs.size());
    iota(idx.begin(), idx.end(), 0);
    const int n = N / min<int>(N, sqrt(N));
    sort(idx.begin(), idx.end(), [&] (auto i, auto j) {
      return cmp(n, qs[i], qs[j]);
    });
    int begin = 0;
    int end = 0;
    // 演算次第ではあるが、インデックスを１ずつ動かすのではなく平方分割のバケットサイズで動かせれば高速化の余地がある。
    each (i, idx) {
      while (begin > qs[i].first) pushFront(--begin);
      while (end < qs[i].second) pushBack(end++);
      while (begin < qs[i].first) popFront(begin++);
      while (end > qs[i].second) popBack(--end);
      report(i);
    }
    return ;
  }
};

namespace math {
  // gcd(a,b)を返す。xとyにはax+by=±gcd(a,b)を満たす数を設定する。
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }

  constexpr lli constexpr_mod_inverse(lli a, lli mod)
  {
    lli inv = 1;
    lli p = mod - 2;
    while (p > 0) {
      if (p & 1) (inv *= a) %= mod;
      (a *= a) %= mod;
      p >>= 1;
    }
    return inv;
  }
};

const int N = 250000 + 3;

template<typename T>
struct SqrtDecomposition {
  using OP = function<void(T&, T)>; // 要結合法則
  const OP op;
  vector<T> bucket;
  vector<T> v;
  const T e;
  const int b;
  SqrtDecomposition(vector<T> values, OP op_, T e_) : e(e_), op(op_), v(values), b(max<int>(1, sqrt(v.size()))) {
    assert(v.size());
    bucket.resize((v.size() + b - 1) / b, e);
    for (size_t i = 0; i < v.size(); ++i) {
      op(bucket[i / b], v[i]);
    }
  }
  T query(size_t begin, size_t end) {
    assert(begin <= end);
    assert(end <= v.size());
    T res = e;
    size_t i = begin;
    for (; i < end && i % b; ++i) {
      op(res, v[i]);
    }
    for (; i + b < end; i += b) {
      op(res, bucket[i / b]);
    }
    for (; i < end; ++i) {
      op(res, v[i]);
    }
    return res;
  }
  size_t size(void) const { return v.size(); }
};

SqrtDecomposition<pair<lli, int>> xxx(
  vec<pair<lli, int>>(N, make_pair(1LL, 0)),
  [] (auto& a, auto b) {
    (a.first *= b.first) %= mod;
    a.second += b.second;
  },
  make_pair(1LL, 0));

static int a[N];
static lli fact[N];
static lli fact_inverse[N];
void push(const int& i) {
  lli mul = fact_inverse[xxx.v[a[i]].second];

  ++xxx.bucket[a[i] / xxx.b].second;
  ++xxx.v[a[i]].second;

  const int x = fact[xxx.v[a[i]].second];
  (mul *= x) %= mod;

  (xxx.bucket[a[i] / xxx.b].first *= mul) %= mod;
  xxx.v[a[i]].first = x;
}

void pop(const int& i) {
  lli mul = fact_inverse[xxx.v[a[i]].second];

  --xxx.bucket[a[i] / xxx.b].second;
  --xxx.v[a[i]].second;

  const int x = fact[xxx.v[a[i]].second];
  (mul *= x) %= mod;

  (xxx.bucket[a[i] / xxx.b].first *= mul) %= mod;
  xxx.v[a[i]].first = x;
}

static int x[N];
static int c[N];
void rep(const int& i)
{
  const auto p = xxx.query(0, x[i]);
  int k = p.second;
  lli z = fact[k];
  lli d = p.first;
  (z *= math::constexpr_mod_inverse(d, mod)) %= mod;
  c[i] = z;
}

int main(int argc, char *argv[])
{
  fact[0] = 1;
  for (size_t i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  for (int i = 0; i < N; ++i) {
    fact_inverse[i] = math::constexpr_mod_inverse(fact[i], mod);
  }

  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }

    vec<pair<int, int>> v;
    for (int i = 0; i < q; ++i) {
      int begin, end;
      scanf("%d%d%d", &begin, &end, x + i);
      --begin;
      v.emplace_back(make_pair(begin, end));
    }

    if (1) {
      static int rename[N];
      // fill(rename, rename + N, 0);
      for (int i = 0; i < n; ++i) {
        rename[a[i]] = 1;
      }
      for (int i = 0; i < q; ++i) {
        rename[x[i]] = 1;
      }
      for (int i = 1; i < N; ++i) {
        rename[i] += rename[i - 1];
      }
      for (int i = 0; i < q; ++i) {
        x[i] = rename[x[i]];
      }
      for (int i = 0; i < n; ++i) {
        a[i] = rename[a[i]];
      }
    }

    Mo::run(N - 1, v, ::push, ::pop, ::push, ::pop, ::rep);
    for (size_t i = 0; i < q; ++i) {
      printf("%d\n", c[i]);
    }
  }
  return 0;
}
