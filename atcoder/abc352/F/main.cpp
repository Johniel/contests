// github.com/Johniel/contests
// atcoder/abc352/F/main.cpp

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

template<typename Weight>
struct WeightedUnionFind {
  // abc280F,
  vector<int> r;
  vector<int> p;
  vector<Weight> dw;

  WeightedUnionFind(int n) : r(n, 0), p(n, -1), dw(n, 0) {}

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
  int n, m;
  while (cin >> n >> m) {
    WeightedUnionFind<int> uf(n);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      uf.unite(a, b, c);
    }
    vec<int> ms;
    vec<vec<int>> idx;
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }
    set<int> vis;
    for (int i = 0; i < n; ++i) {
      unless (vis.count(uf.find(i))) {
        vec<pair<int, int>> v;
        for (int j = 0; j < n; ++j) {
          if (uf.same(i, j)) {
            v.push_back(make_pair(uf.diff(i, j), j));
            vis.insert(j);
          }
        }
        sort(v.begin(), v.end());
        int mn = v.front().first;
        each (j, v) j.first -= mn;
        int b = 0;
        each (j, v) b += (1 << j.first);
        ms.push_back(b);
        vec<int> u;
        each (i, v) u.push_back(i.second);
        // reverse(u.begin(), u.end());
        idx.push_back(u);
      }
    }
    // cout << ms << endl;
    // cout << idx << endl;

    vec<int> z(n, -(1 << 28));
    const int B = 1 << n;
    lli dp[ms.size() + 1][B];
    const vec<int> tmp = ms;
    for (int src = 0; src < ms.size(); ++src) {
      for (int i = 0; i < ms.size() + 1; ++i) {
        for (int j = 0; j < B; ++j) {
          dp[i][j] = 0;
        }
      }
      vec<int> ms = tmp;
      ms.erase(ms.begin() + src);
      dp[0][0] = 1;
      for (int i = 0; i < ms.size(); ++i) {
        for (int bit = 0; bit < (1 << n); ++bit) {
          for (int s = 0; s < n; ++s) {
            int rem = ((1 << n) - 1) ^ bit;
            int b = (ms[i] << s);
            if ((rem & b) == b && (bit | b) < (1 << n)) {
              dp[i + 1][bit | b] += dp[i][bit];
            }
          }
        }
      }
      vec<int>  w;
      for (int s = 0; s < n; ++s) {
        int all = ((1 << n) - 1);
        int b = (tmp[src] << s);
        int a = (all ^ b);
        if (b <= all && dp[ms.size()][a]) {
          w.push_back(b);
        }
      }
      if (w.size() == 1) {
        vec<int> c;
        for (int i = 0, j = 0; i < n; ++i) {
          if (w[0] & (1 << i)) {
            z[idx[src][j]] = n - i - 1;
            ++j;
          }
        }
      }
    }
    for (int i = 0; i < z.size(); ++i) {
      cout << max(z[i] + 1, -1) << ' ';
    }
    cout << endl;
  }
  return 0;
}
