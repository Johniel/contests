// github.com/Johniel/contests
// atcoder/abc307/F/main.cpp

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

const int N = 3 * 1e5 + 3;
vec<pair<int, lli>> g[N];

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
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<pair<int, lli>>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }

    vec<int> src;
    {
      int k;
      cin >> k;
      src.resize(k);
      cin >> src;
      each (i, src) --i;
    }
    const lli inf = 1LL << 60;
    vec<lli> x;
    {
      int d;
      cin >> d;
      x.resize(d);
      cin >> x;
      x.insert(x.begin(), -1);
      x.push_back(-1);
    }
    SegTree<lli> seg(x.size(), -inf, [] (auto a, auto b) { return max(a, b); });
    for (int i = 0; i < x.size(); ++i) {
      seg.update(i, x[i]);
    }
    auto fn = [&] (int begin, lli atleast) {
      int small = begin;
      int large = x.size();
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (atleast <= seg.query(begin, mid)) large = mid;
        else small = mid;
      }
      if (atleast <= seg.query(begin, small)) return small - 1;
      if (atleast <= seg.query(begin, large)) return large - 1;
      return -1;
    };

    using Cost = pair<int, lli>;
    vec<Cost> dist(n, make_pair(1 << 29, inf));
    // {{何日目, 距離}, どこ}
    using State = pair<Cost, int>;
    priority_queue<State, vector<State>, greater<State>> q;
    each (i, src) {
      Cost ini = make_pair(0, inf-1);
      q.push(make_pair(ini, i));
      dist[i] = ini;
    }
    vec<int> ns;
    while (q.size()) {
      State p = q.top();
      q.pop();
      int curr = p.second;
      int day = p.first.first;
      lli c = p.first.second;
      if (dist[curr] != make_pair(day, c)) continue;
      each (e, g[curr]) {
        const int next = e.first;
        const lli cost = e.second;
        Cost aaa = make_pair(day, c + cost);
        if (c + cost <= x[day] && aaa < dist[next]) {
          dist[next] = aaa;
          q.push(make_pair(aaa, next));
        } else {
          const int nday = fn(day + 1, cost);
          Cost bbb = make_pair(nday, cost);
          if (nday != -1 && cost <= x[nday] && bbb < dist[next]) {
            dist[next] = bbb;
            q.push(make_pair(bbb, next));
          }
        }
      }
    }
    // cout << dist << endl;
    for (int i = 0; i < n; ++i) {
      if (dist[i].second < inf) {
        cout << dist[i].first << endl;
      } else {
        cout << -1 << endl;
      }
    }
    // break;
  }
  return 0;
}
