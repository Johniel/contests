// atcoder/typical90/012/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int H = 2000 + 2;
  const int W = 2000 + 2;
  static int color[H][W];
  int cnt = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      color[i][j] = cnt++;
    }
  }

  int h, w, q;
  while (cin >> h >> w >> q) {
    static bool white[H][W];
    fill(&white[0][0], &white[H - 1][W - 1] + 1, true);
    UnionFind uf(cnt);
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (white[a][b]) {
          white[a][b] = false;
          for (int d = 0; d < 4; ++d) {
            int ni = a + di[d];
            int nj = b + dj[d];
            unless (0 <= ni && ni < h) continue;
            unless (0 <= nj && nj < w) continue;
            if (!white[ni][nj]) uf.unite(color[a][b], color[ni][nj]);
          }
        }
      }
      if (op == 2) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --b;
        --c;
        --d;
        cout << (!white[a][b] && !white[c][d] && uf.same(color[a][b], color[c][d]) ? "Yes" : "No") << endl;
      }
    }
  }

  return 0;
}
