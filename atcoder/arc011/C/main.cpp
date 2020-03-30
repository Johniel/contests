// atcoder/arc011/C/main.cpp
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

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  str src, dst;
  while (cin >> src >> dst) {
    int n;
    cin >> n;
    vec<str> v(n);
    cin >> v;

    if (src == dst) {
      cout << 0 << endl;
      cout << src << endl;
      cout << dst << endl;
      continue;
    }

    v.push_back(src);
    v.push_back(dst);

    const int N = 1000 + 5;
    static vec<int> g[N];
    fill(g, g + N, vec<int>());
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        int cnt = 0;
        for (int k = 0; k < v[i].size(); ++k) {
          cnt += (v[i][k] != v[j][k]);
        }
        if (cnt == 1) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }

    static int cost[N];
    const int inf = 1 << 29;
    fill(cost, cost + N, inf);
    cost[v.size() - 2] = 0;

    static int path[N];
    fill(path, path + N, -1);

    queue<int> q;
    for (q.push(v.size() - 2); q.size(); q.pop()) {
      int curr = q.front();
      each (next, g[curr]) {
        if (cost[next] != inf) continue;
        cost[next] = cost[curr] + 1;
        q.push(next);
        path[next] = curr;
      }
    }

    vec<int> p;
    int curr = v.size() - 1;
    while (path[curr] != -1) {
      p.push_back(curr);
      curr = path[curr];
    }

    if (p.empty()) cout << -1 << endl;
    else {
      p.push_back(v.size() - 2);
      reverse(p.begin(), p.end());
      cout << p.size() - 2 << endl;
      each (i, p) cout << v[i] << endl;
    }
  }

  return 0;
}
