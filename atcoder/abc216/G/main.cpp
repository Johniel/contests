// atcoder/abc216/G/main.cpp
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

const int N = 2 * 1e5 + 3;
vec<pair<int, int>> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int a, b, x;
      cin >> a >> b >> x;
      --a;
      --b;
      g[a].push_back(make_pair(b + 1, b + 1 - a - x));
    }
    for (int i = 0; i < n; ++i) {
      g[i + 1].push_back(make_pair(i, 0));
      g[i].push_back(make_pair(i + 1, 1));
    }

    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    static int cost[N];
    const int inf = 1 << 29;
    fill(cost, cost + N, inf);
    cost[0] = 0;
    while (q.size()) {
      pair<int, int> p = q.top();
      q.pop();
      int c = abs(p.first);
      int curr = p.second;
      if (cost[curr] != c) continue;
      each (e, g[curr]) {
        int next = e.first;
        int w = e.second;
        if (cost[next] > cost[curr] + w) {
          cost[next] = cost[curr] + w;
          q.push(make_pair(-cost[next], next));
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << ((cost[i + 1] - cost[i]) ^ 1) << ' ';
    }
    cout << endl;
  }

  return 0;
}
