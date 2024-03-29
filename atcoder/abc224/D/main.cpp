// atcoder/abc224/D/main.cpp
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

const int N = 9;
vec<int> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int m;
  while (cin >> m) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<int> v(8);
    cin >> v;
    each (i, v) --i;
    vec<int> ini(9, -1);
    for (int i = 0; i < v.size(); ++i) {
      ini[v[i]] = i;
    }
    map<vec<int>, int> cost;
    cost[ini] = 0;
    queue<vec<int>> q;
    for (q.push(ini); q.size(); q.pop()) {
      vec<int> u = q.front();
      int curr = find(u.begin(), u.end(), -1) - u.begin();
      each (next, g[curr]) {
        vec<int> v = u;
        swap(v[curr], v[next]);
        unless (cost.count(v)) {
          cost[v] = cost[u] + 1;
          q.push(v);
        }
      }
    }
    vec<int> dst;
    for (int i = 0; i < 8; ++i) {
      dst.push_back(i);
    }
    dst.push_back(-1);
    if (cost.count(dst)) cout << cost[dst] << endl;
    else cout << -1 << endl;
  }

  return 0;
}
