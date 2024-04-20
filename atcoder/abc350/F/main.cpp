// github.com/Johniel/contests
// atcoder/abc350/F/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

template<typename F>
struct DualSegTree {
  // ABC017D,ABC347E,ABC342F
  using composition_fn = function<F(F, F)>; // composition(f(x), g(x)):=f(g(x))
  DualSegTree(size_t n_, composition_fn composition_, F e_)
    : n(n_), composition(composition_), e(e_), bit_ceiled_n(bit_ceil(n_)) {
    lazy.resize(2 * bit_ceiled_n, e);
  }
  void apply(size_t begin, size_t end, F f) {
    assert(0 <= begin && begin < n);
    assert(0 <= end && end <= n);
    assert(begin <= end);
    size_t a = begin + bit_ceiled_n;
    size_t b = end + bit_ceiled_n;
    push((a >> __builtin_ctz(a)));
    push((b >> __builtin_ctz(b)) - 1);
    for (; a < b; a /= 2, b /= 2 ) {
      if (a & 1) {
        lazy[a] = composition(f, lazy[a]);
        ++a;
      }
      if (b & 1) {
        --b;
        lazy[b] = composition(f, lazy[b]);
      }
    }
    return ;
  }
  void set(size_t idx, F f) {
    assert(idx < n);
    push(idx + bit_ceiled_n);
    lazy[idx + bit_ceiled_n] = f;
    return ;
  }
  F get(size_t idx) {
    assert(idx < n);
    push(idx + bit_ceiled_n);
    return lazy[idx + bit_ceiled_n];
  }
  void clear(size_t idx) {
    assert(idx < n);
    get(idx);
    set(idx, e);
    return ;
  }
  size_t size(void) const { return n; } ;
  vector<F> lazy;
  const composition_fn composition;
  const F e;
  const size_t n;
  const size_t bit_ceiled_n;
  void push(size_t idx) {
    int depth = bit_width(idx);
    for (int d = depth - 1; 0 < d; --d) {
      size_t i = idx >> d;
      if (lazy[i] != e) {
        lazy[i * 2 + 0] = composition(lazy[i], lazy.at(i * 2 + 0));
        lazy[i * 2 + 1] = composition(lazy[i], lazy.at(i * 2 + 1));
        lazy[i] = e;
      }
    }
    return ;
  }
};

char fn(char c)
{
  if ('a' <= c && c <= 'z') return (int)('A') + c - 'a';
  if ('A' <= c && c <= 'Z') return (int)('a') + c - 'A';
  return 0;
}

int main(int argc, char *argv[])
{
  str s;
  while (cin >> s) {
    DualSegTree<int> seg(s.size(), [] (int a, int b) { return a ^ b; }, 0);
    vec<int> v;
    vec<int> u(s.size(), -1);
    for (int i = 0; i < s.size(); ++i) {
      if ('a' <= s[i] && s[i] <= 'z') continue;
      if ('A' <= s[i] && s[i] <= 'Z') continue;
      if (s[i] == '(') v.push_back(i);
      else if (s[i] == ')') {
        const int j = v.back();
        v.pop_back();
        seg.apply(j + 1, i, 1);
        u[i] = j;
        u[j] = i;
      }
    }
    assert(v.empty());
    str t;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == ')') t += s[i];
      else {
        if (seg.get(i)) {
          if ('a' <= s[i] && s[i] <= 'z') t += (int)('A') + s[i] - 'a';
          if ('A' <= s[i] && s[i] <= 'Z') t += (int)('a') + s[i] - 'A';
        }
        else t += s[i];
      }
    }
    // cout << t << endl; cout << u << endl;
    function<void(int, int, int)> rec = [&] (int mn, int mx, int mode) {
      if (mode) {
        for (int i = mx; mn <= i; --i) {
          if (t[i] == ')') {
            rec(u[i] + 1, i - 1, mode ^ 1);
            i = u[i];
          } else {
            cout << t[i];
          }
        }
      } else {
        for (int i = mn; i <= mx; ++i) {
          if (t[i] == '(') {
            rec(i + 1, u[i] - 1, mode ^ 1);
            i = u[i];
          } else {
            cout << t[i];
          }
        }
      }
      return ;
    };
    rec(0, s.size() - 1, 0);
    cout << endl;
    // break;
  }
  return 0;
}
