// github.com/Johniel/contests
// codeforces/943div3/G/main.cpp

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

// s自身とすべてのsuffixとの共通接頭辞の文字数を返す。
// つまり、{|LCP(s[0], s.substring(0))|, |LCP(s[0], s.substring(1))|, |LCP(s[0], s.substring(2))|, ... }
// verified at ABC257G
vector<int> z_algorithm(const string& s)
{
  vector<int> v(s.size());
  v[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
    while(i + j < s.size() && s[j] == s[i + j]) j++;
    v[i] = j;

    if(j == 0){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && k + v[k] < j){
      v[i + k] = v[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return v;
}

template<typename T>
struct SegTree {
  // https://codeforces.com/blog/entry/18051
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  vector<T> v;
  SegTree(size_t n_, T e_, F op_) : e(e_), n(n_), op(op_) {
    assert(op(e, e) == e);
    v.resize(2 * n, e);
  }
  SegTree(const vector<T>& v, T e_, F op_) : SegTree(v.size(), e_, op_) {
    for (int i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    for (v[k += n] = a; k > 1; k >>= 1) v[k >> 1] = op(v[k], v[k ^ 1]);
    return ;
  }
  inline T get(size_t k) const { return v.at(k + n); }
  inline T operator () (void) const { return query(0, n, 0, 0, n); }
  inline T operator () (size_t begin, size_t end) const { return query(begin, end); }
  inline T all_prod(void) const { return query(0, n); }
  inline T prod(size_t begin, size_t end) const { return query(begin, end); }
  T query(size_t l, size_t r) {
    T res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = op(v[l++], res);
      if (r & 1) res = op(res, v[--r]);
    }
    return res;
  }
  size_t size(void) const { return n; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.size(); ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { vector<T> v; for (int i = 0; i < seg.size(); ++i) v.push_back(seg[i]); os << v; return os; }

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, l, r;
  str s;
  while (cin >> n >> l >> r >> s) {
    vec<int> za = z_algorithm(s);
    SegTree<int> seg(za, 0, [] (auto a, auto b) { return max(a, b); });
    vec<int> v(n+1, -1);
    for (int len = 2; len < v.size(); ++len) {
      int prev = 0;
      int k = 0;
      while (true) {
        int small = prev;
        int large = za.size();
        while (small + 1 < large) {
          int mid = (small + large) / 2;
          if (len <= seg.query(prev, mid)) large = mid;
          else small = mid;
        }
        auto p = seg.query(prev, large);
        if (p < len) break;
        ++k;
        prev = large - 1 + len;
      }
      v[len] = k;
    }
    v[1] = count(s.begin(), s.end(), s.front());
    vec<int> w(n+1, 0);
    for (int i = 0; i + 1 < v.size(); ++i) {
      for (int j = v[i]; v[i + 1] <= j; --j) {
        setmax(w[j], i);
      }
    }
    w[1] = n;
    for (int i = l; i <= r; ++i) cout << w.at(i) << ' '; cout << "\n";
  }
  return 0;
}
