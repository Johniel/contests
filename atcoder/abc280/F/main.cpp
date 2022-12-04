// github.com/Johniel/contests
// atcoder/abc280/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

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

const int N = 2 * 1e5 + 3;
vec<pair<int, lli>> g[N];
lli cost[N];
const lli inf = 1LL << 60;
vec<int> v;
bool rec(int curr, int prev, lli c)
{
  cost[curr] = c;
  v.push_back(curr);
  bool f = false;
  each (e, g[curr]) {
    int next = e.first;
    if (cost[next] != -inf) {
      if (cost[curr] + e.second - cost[next]) f = true;
      continue;
    }
    f = f || rec(next, curr, cost[curr] + e.second);
  }
  return f;
}

int main(int argc, char *argv[])
{
  int n, m, q;
  while (cin >> n >> m >> q) {
    fill(g, g + N, vec<pair<int, lli>>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, +c));
      g[b].push_back(make_pair(a, -c));
    }

    fill(cost, cost + N, -inf);

    set<int> cycle;
    for (int i = 0; i < n; ++i) {
      if (cost[i] == -inf) {
        v.clear();
        if (rec(i, i, 0)) {
          each (j, v) cycle.insert(j);
        }
      }
    }

    UnionFind uf(N);
    for (int i = 0; i < N; ++i) {
      each (e, g[i]) uf.unite(i, e.first);
    }

    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;

      if (!uf.same(x, y)) {
        cout << "nan" << endl;
        continue;
      }

      if (cycle.count(x)) {
        cout << "inf" << endl;
        continue;
      }

      cout << cost[y] - cost[x] << endl;
    }
  }
  return 0;
}
