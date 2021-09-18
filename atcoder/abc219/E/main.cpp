// atcoder/abc219/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

class UnionFind {
public:
  UnionFind(int n) {
    r.resize(n, 0);
    p.resize(n, -1);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (r[a] > r[b]) {
      p[a] += p[b];
      p[b] = a;
    } else {
      p[b] += p[a];
      p[a] = b;
      if(r[a] == r[b]) r[b]++;
    }
    return ;
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
private:
  vector<int> r, p;
};

const int N = 4;
int g[N][N];
int h[N][N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int no[N][N];

  while (true) {
    bool f = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        f = f && (cin >> g[i][j]);
      }
    }
    unless (f) break;

    lli z = 0;

    for (int bit = 1; bit < (1 << (N * N)); ++bit) {
      int b = bit;
      int cnt = 0;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          h[i][j] = b % 2;
          b /= 2;
        }
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (h[i][j]) no[i][j] = cnt++;
        }
      }
      const int one = cnt;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          unless (h[i][j]) no[i][j] = cnt++;
        }
      }
      bool f = true;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (g[i][j]) f = f && h[i][j];
        }
      }

      UnionFind uf(N * N);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          for (int d = 0; d < 4; ++d) {
            int ni = i + di[d];
            int nj = j + dj[d];
            unless (0 <= ni && ni < N) continue;
            unless (0 <= nj && nj < N) continue;
            if (h[i][j] && h[ni][nj]) uf.unite(no[i][j], no[ni][nj]);
            if (!h[i][j] && !h[ni][nj]) uf.unite(no[i][j], no[ni][nj]);
          }
        }
      }

      set<int> vis;
      int x = uf.size(0);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (!h[i][j] && (i == 0 || j == 0 || i == N - 1 || j == N - 1)) {
            int k = uf.find(no[i][j]);
            unless (vis.count(k)) {
              x += uf.size(k);
              vis.insert(k);
            }
          }
        }
      }
      z += f && (uf.size(0) == one) && (x == N * N);
    }
    cout << z << endl;
  }

  return 0;
}
