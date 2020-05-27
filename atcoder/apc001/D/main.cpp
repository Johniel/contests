// atcoder/apc001/D/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vec<int> a(n);
    cin >> a;

    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      uf.unite(x, y);
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }

    int y = 0;
    map<int, int> color;
    for (int i = 0; i < n; ++i) {
      int j = uf.find(i);
      unless (color.count(j)) color[j] = y++;
      color[i] = color[j];
    }

    if (y == 1) {
      cout << 0 << endl;
      continue;
    }

    const int N = 1e5 + 5;
    priority_queue<int> q[N];
    for (int i = 0; i < n; ++i) {
      q[color[i]].push(-a[i]);
    }

    lli sum = 0;
    for (int i = 0; i < y; ++i) {
      sum += -q[i].top();
      q[i].pop();
    }

    vec<int> v;
    for (int i = 0; i < N; ++i) {
      while (q[i].size()) {
        v.push_back(-q[i].top());
        q[i].pop();
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int z = ((y - 1) * 2) - y;
    unless (z <= v.size()) {
      cout << "Impossible" << endl;
      continue;
    }

    for (int i = 0; i < z; ++i) {
      sum += v.back();
      v.pop_back();
    }
    cout << sum << endl;
  }

  return 0;
}
