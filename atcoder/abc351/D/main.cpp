// github.com/Johniel/contests
// atcoder/abc351/D/main.cpp

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
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};
    bool adj[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') {
          adj[i][j] = true;
          continue;
        }
        adj[i][j] = false;
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == '#') adj[i][j] = true;
        }
      }
    }

    int idx[h][w];
    {
      int cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          idx[i][j] = cnt++;
        }
      }
    }
    UnionFind uf(h * w);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (!adj[i][j] && !adj[ni][nj]) uf.unite(idx[i][j], idx[ni][nj]);
        }
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        uf.find(idx[i][j]);
      }
    }

    map<int, set<int>> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          int a = idx[i][j];
          int b = idx[ni][nj];
          if (adj[i][j] && !adj[ni][nj] && g[i][j] == '.' && g[ni][nj] == '.' && !uf.same(a, b)) {
            // if (uf.size(b) == 4) cout << make_pair(i, j) << ' ' << make_pair(ni, nj) << endl;
            m[uf.find(b)].insert(a);
          }
        }
      }
    }

    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << adj[i][j] << ' ' ;
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << uf.size(idx[i][j]) << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << m[uf.find(idx[i][j])] << ' ';
    //   }
    //   cout << endl;
    // }

    int z = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') {
          int s = m[uf.find(idx[i][j])].size();
          setmax<int>(z, s + uf.size(idx[i][j]));
        }
      }
    }
    cout << z << endl;
  }
  return 0;
}
