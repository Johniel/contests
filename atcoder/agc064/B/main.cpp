// github.com/Johniel/contests
// atcoder/agc064/B/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

struct UnionFind {
  vector<int> r, p;
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
      if (r[a] == r[b]) ++r[b];
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
};

const int N = 2 * 1e5 + 3;
// const int N = 100;
vec<pair<int, int>> g[N];

int main(int argc, char *argv[])
{
  int n, m;
  str s;
  while (cin >> n >> m) {
    int a[m], b[m];
    char c[m];
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i];
      --b[i];
      g[a[i]].push_back(make_pair(b[i], i));
      g[b[i]].push_back(make_pair(a[i], i));
    }
    cin >> s;

    vec<int> v;

    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      if (s[a[i]] == c[i] && s[b[i]] == c[i] && !uf.same(a[i], b[i])) {
        uf.unite(a[i], b[i]);
        v.push_back(i);
      }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (2 <= uf.size(i)) q.push(i);
    }
    for (; q.size(); q.pop()) {
      int curr = q.front();
      each (e, g[curr]) {
        auto [next, idx] = e;
        if (!uf.same(curr, next) && uf.size(next) == 1 && s[next] == c[idx] && s[curr] != c[idx]) {
          v.push_back(idx);
          uf.unite(curr, next);
          q.push(next);
        }
      }
    }

    if (uf.size(0) != n) {
      for (int i = 0; i < m; ++i) {
        if (!uf.same(a[i], b[i]) && uf.size(a[i]) != 1 && uf.size(b[i]) != 1) {
          uf.unite(a[i], b[i]);
          v.push_back(i);
        }
      }
    }

    if (uf.size(0) != n) {
      cout << "No" << endl;
    } else {
      sort(v.begin(), v.end());
      cout << "Yes" << endl;
      each (i, v) cout << i + 1 << ' '; cout << endl;
    }
  }
  return 0;
}
