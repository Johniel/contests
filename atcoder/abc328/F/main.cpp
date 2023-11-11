// github.com/Johniel/contests
// atcoder/abc328/F/main.cpp

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

template<typename Weight>
struct WeightedUnionFind {
  // abc280F,
  vector<int> r;
  vector<int> p;
  vector<Weight> dw;

  WeightedUnionFind(int n)
  {
    r.resize(n, 0);
    p.resize(n, -1);
    dw.resize(n, 0);
  }

  int find(int x)
  {
    if (p[x] < 0) return x;
    int y = find(p[x]);
    dw[x] += dw[p[x]];
    return p[x] = y;
  }

  // weight(y) = weight(x) + w
  bool unite(int x, int y, Weight w)
  {
    w = w + weight(x) - weight(y);
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (r[x] < r[y]) {
      swap(x, y);
      w = -w;
    }
    p[y] = x;
    dw[y] = w;
    if (r[x] == r[y]) ++r[y];
    return true;
  }

  Weight weight(int x) { find(x); return dw[x]; }
  // weight(x) - weight(x) if same(x, y)
  Weight diff(int src, int dst) { assert(same(src, dst)); return weight(dst) - weight(src); }
  size_t size(int x) { return -p.at(find(x)); }
  bool same(int x, int y) { return find(x) == find(y); }
};


int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    int x[q];
    int y[q];
    lli w[q];
    for (int i = 0; i < q; ++i) {
      cin >> x[i] >> y[i] >> w[i];
      --x[i];
      --y[i];
    }

    set<int> vis;
    WeightedUnionFind<lli> uf(n);
    for (int i = 0; i < q; ++i) {
      if (!uf.same(x[i], y[i])) {
        uf.unite(x[i], y[i], w[i]);
        vis.insert(i);
      } else {
        if (uf.diff(x[i], y[i]) == w[i]) {
          vis.insert(i);
        }
      }
    }
    each (i, vis) cout << i + 1 << ' '; cout << endl;
  }
  return 0;
}
