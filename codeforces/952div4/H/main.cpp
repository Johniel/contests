// github.com/Johniel/contests
// codeforces/952div4/H/main.cpp

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

template<typename T>
struct PrefixSum2D {
  vector<vector<T>> sum;
  PrefixSum2D() {}
  PrefixSum2D(vector<vector<T>> v) {
    const int H = v.size() + 1;
    const int W = v[0].size() + 1;
    sum.resize(H);
    fill(sum.begin(), sum.end(), vector<T>(W, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        sum[i + 1][j + 1] = v[i][j];
      }
    }
    for (int i = 1; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for (int i = 0; i < H; ++i) {
      for (int j = 1; j < W; ++j) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  T operator () (int ai, int aj, int bi, int bj) const { return this->query(ai, aj, bi, bj); }
  T query(int ai, int aj, int bi, int bj) const {
    assert(0 <= ai && ai < sum.size());
    assert(0 <= bi && bi < sum.size());
    assert(0 <= aj && aj < sum[0].size());
    assert(0 <= bj && bj < sum[0].size());
    assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
  pair<size_t, size_t> size(void) const { return make_pair(sum.size() - 1, sum[0].size() - 1); }
};

template<typename T = long long int>
struct BIT {
  vector<T> v;
  const int n;

  BIT(int n_ = 0) : n(n_), v(n_ + 1, 0) {}

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      s += v.at(i);
      i -= i & -i;
    }
    return s;
  }

  T query(int begin, int end) const {
    assert(begin <= end);
    return (*this)(end) - (*this)(begin);
  }

  T operator () (int begin, int end) const {
    return query(begin, end);
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v.at(i) += x;
      i += i & -i;
    }
    return ;
  }

  size_t lower_bound(const T query) const {
    int small = 0;
    int large = v.size();
    while (small + 1 < large) {
      auto mid = (small + large) / 2;
      if ((*this)(mid) <= query) small = mid;
      else large = mid;
    }
    if (query <= (*this)(small)) return small;
    if (query <= (*this)(large)) return large;
    return size();
  }

  size_t size(void) const { return n; }
};

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int name[h][w];
    {
      int cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          name[i][j] = cnt++;
        }
      }
    }
    constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
    constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
    UnionFind uf(h * w);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[i][j] == '#' && g[ni][nj] == '#') uf.unite(name[i][j], name[ni][nj]);
        }
      }
    }

    for (int i = 0; i < h * w; ++i) {
      uf.find(i);
    }

    map<int, vec<pair<int, int>>> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') {
          m[uf.find(name[i][j])].push_back(make_pair(i, j));
        }
      }
    }
    vec<int> keys;
    each (i, m) keys.push_back(i.first);
    map<int, int> mni, mnj, mxi, mxj;
    each (k, keys) {
      mni[k] = mnj[k] = +(1 << 29);
      mxi[k] = mxj[k] = -(1 << 29);
    }
    each (w, m) {
      each (k, w.second) {
        setmin(mni[w.first], k.first);
        setmin(mnj[w.first], k.second);
        setmax(mxi[w.first], k.first);
        setmax(mxj[w.first], k.second);
      }
    }

    BIT<int> A(h+2);
    BIT<int> B(w+2);
    vec<vec<int>> C(h+2, vec<int>(w+2, 0));
    each (k, keys) {
      int ni = max(mni[k] - 1, 0);
      int xi = min(mxi[k] + 2, h+1);
      int nj = max(mnj[k] - 1, 0);
      int xj = min(mxj[k] + 2, w+1);
      // cout << make_pair(ni, xi) << ' ' << make_pair(nj, xj) << endl;

      const int sz = uf.size(k);

      A.add(ni, +sz);
      A.add(xi, -sz);
      B.add(nj, +sz);
      B.add(xj, -sz);

      C[ni][nj] += sz;
      C[xi][nj] -= sz;
      C[ni][xj] -= sz;
      C[xi][xj] += sz;
    }
    PrefixSum2D<int> AB(C);

    int H[w+1], W[h+1];
    fill(H, H + w + 1, 0);
    fill(W, W + h + 1, 0);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        W[i+1] += (g[i][j] == '.');
      }
    }
    for (int j = 0; j < w; ++j) {
      for (int i = 0; i < h; ++i) {
        H[j+1] += (g[i][j] == '.');
      }
    }

    // for (int i = 0; i <= h; ++i) cout << A.query(0, i) << ' '; cout << endl;
    // for (int i = 0; i <= w; ++i) cout << B.query(0, i) << ' '; cout << endl;
    // cout << endl;
    // for (int i = 0; i <= h; ++i) {
    //   for (int j = 0; j <= w; ++j) {
    //     cout << AB.query(0, 0, i, j) << ' ';
    //   }
    //   cout << endl;
    // }
    // for (int i = 0; i <= h; ++i) cout << W[i] << ' '; cout << endl;
    // for (int i = 0; i <= w; ++i) cout << H[i] << ' '; cout << endl;

    int z = 0;
    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        setmax(z, (H[j] + W[i] - (g[i - 1][j - 1] == '.')) + (A.query(0, i) + B.query(0, j) - AB.query(0, 0, i, j)));
      }
    }
    cout << z << endl;
    // cout << endl;
  }
  return 0;
}
