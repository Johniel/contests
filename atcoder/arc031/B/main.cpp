// atcoder/arc031/B/main.cpp
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
    return -p[find(n)];
  }
private:
  vector<int> r, p;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (true) {
    const int N = 10;
    char g[N][N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        unless (cin >> g[i][j]) return 0;
      }
    }

    int x[N][N];
    int cnt = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (g[i][j] == 'o') x[i][j] = cnt++;
        else x[i][j] = 0;
      }
    }

    bool f = false;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        unless (g[i][j] == 'x') continue;
        g[i][j] = 'o';
        UnionFind uf(cnt);
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < N; ++b) {
            if (a + 1 < N && g[a][b] == 'o' && g[a + 1][b] == 'o') uf.unite(x[a][b], x[a + 1][b]);
            if (b + 1 < N && g[a][b] == 'o' && g[a][b + 1] == 'o') uf.unite(x[a][b], x[a][b + 1]);
          }
        }
        for (int k = 0; k < cnt; ++k) {
          uf.find(k);
        }
        set<int> vis;
        for (int k = 0; k < cnt; ++k) {
          vis.insert(uf.find(k));
        }
        f = f || (vis.size() == 1);
        g[i][j] = 'x';
      }
    }
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
