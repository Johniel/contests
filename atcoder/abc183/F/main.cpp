// atcoder/abc183/F/main.cpp
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

  int n, q;
  while (cin >> n >> q) {
    vec<int> v(n);
    cin >> v;
    each (i, v) --i;

    map<int, int> cnt[n];
    for (int i = 0; i < n; ++i) {
      cnt[i][v[i]] = 1;
    }
    int idx[n];
    for (int i = 0; i < n; ++i) {
      idx[i] = i;
    }

    UnionFind uf(n);
    while (q--) {
      // for (int i = 0; i < n; ++i) cout << cnt[i] << endl;
      int op;
      cin >> op;
      if (op == 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (uf.same(a, b)) continue;
        a = uf.find(a);
        b = uf.find(b);
        uf.unite(a, b);
        int c = uf.find(a);
        int idx_a = idx[a];
        int idx_b = idx[b];
        if (cnt[idx_a].size() < cnt[idx_b].size()) {
          each (i, cnt[idx_a]) cnt[idx_b][i.first] += i.second;
          cnt[idx_a].clear();
          idx[c] = idx_b;
        } else {
          each (i, cnt[idx_b]) cnt[idx_a][i.first] += i.second;
          cnt[idx_b].clear();
          idx[c] = idx_a;
        }
      }
      if (op == 2) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout << cnt[idx[uf.find(x)]][y] << endl;
      }
    }
  }

  return 0;
}
