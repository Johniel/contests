// atcoder/abc252/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<vec<int>> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back({b, c, i});
      g[b].push_back({a, c, i});
    }

    int path[n];
    priority_queue<pair<lli, int>> q;
    q.push({0, 0});
    lli cost[n];
    const lli inf = 1LL << 60;
    fill(cost, cost + n, inf);
    cost[0] = 0;
    while (q.size()) {
      auto p = q.top();
      q.pop();
      p.first = abs(p.first);
      if (cost[p.second] != p.first) continue;
      each (e, g[p.second]) {
        if (cost[e[0]] > cost[p.second] + e[1]) {
          cost[e[0]] = cost[p.second] + e[1];
          path[e[0]] = e[2];
          q.push({-cost[e[0]], e[0]});
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      cout << path[i] + 1 << ' ';
    }
    cout << endl;
  }

  return 0;
}
