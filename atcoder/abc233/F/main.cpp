// atcoder/abc233/F/main.cpp
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

const int N = 1000 + 3;
vec<int> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    vec<int> v(n);
    cin >> v;
    each (i, v) --i;
    int m;
    cin >> m;
    UnionFind uf(n);
    map<pair<int, int>, int> op;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      if (uf.same(a, b)) continue;
      uf.unite(a, b);
      g[a].push_back(b);
      g[b].push_back(a);
      op[{a, b}] = i;
      op[{b, a}] = i;
    }
    static int deg[N];
    for (int i = 0; i < n; ++i) {
      deg[i] = g[i].size();
    }
    queue<int> leaf;
    vec<int> path;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 1) leaf.push(i);
    }
    while (leaf.size()) {
      // cout << v << endl;
      static int prev[N];
      fill(prev, prev + N, -1);
      const int dst = leaf.front();
      int src = -1;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] == leaf.front()) {
          src = i;
          break;
        }
      }
      if (src == -1) break;
      prev[src] = src;
      queue<int> q;
      for (q.push(src); q.size(); q.pop()) {
        const int curr = q.front();
        if (prev[dst] != -1) break;
        each (next, g[q.front()]) {
          if (prev[next] == -1) {
            prev[next] = curr;
            q.push(next);
          }
        }
      }
      if (prev[dst] == -1) break;
      vec<pair<int, int>> tmp;
      int a = dst;
      while (prev[a] != a) {
        tmp.push_back({a, prev[a]});
        a = prev[a];
      }
      reverse(tmp.begin(), tmp.end());
      each (i, tmp) {
        assert(op.count(i));
        path.push_back(op[i]);
        swap(v[i.first], v[i.second]);
      }
      each (i, g[dst]) {
        if (--deg[i] == 1) leaf.push(i);
      }
      leaf.pop();
    }
    bool f = true;
    for (int i = 0; i < v.size(); ++i) {
      f = f && (v[i] == i);
    }
    unless (f) {
      cout << -1 << endl;
    } else {
      // cout << v << endl;
      cout << path.size() << endl;
      each (i, path) cout << i + 1 << ' '; cout << endl;
    }
  }

  return 0;
}
