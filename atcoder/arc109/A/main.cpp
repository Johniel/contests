// atcoder/arc109/A/main.cpp
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int a, b, x, y;
  while (cin >> a >> b >> x >> y) {
    --a;
    --b;
    const int N = 100;
    int noa[N];
    int nob[N];
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      noa[i] = cnt++;
      nob[i] = cnt++;
    }
    const int src = noa[a];
    const int dst = nob[b];
    const int M = N * 2;
    vec<pair<int, int>> g[M];
    for (int i = 0; i < N; ++i) {
      g[noa[i]].push_back(make_pair(nob[i], x));
      g[nob[i]].push_back(make_pair(noa[i], x));
      if (i + 1 < N) {
        g[noa[i + 1]].push_back(make_pair(nob[i], x));
        g[nob[i]].push_back(make_pair(noa[i + 1], x));

        g[noa[i]].push_back(make_pair(noa[i + 1], y));
        g[nob[i]].push_back(make_pair(nob[i + 1], y));

        g[noa[i + 1]].push_back(make_pair(noa[i], y));
        g[nob[i + 1]].push_back(make_pair(nob[i], y));
      }
    }
    int cost[M];
    const int inf = 1 << 28;
    fill(cost, cost + M, inf);
    cost[src] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, src));
    while (q.size()) {
      pair<int, int> p = q.top();
      q.pop();
      int curr = p.second;
      int w = abs(p.first);
      if (cost[curr] != w) continue;
      each (e, g[curr]) {
        int c = w + e.second;
        int next = e.first;
        if (cost[next] > c) {
          cost[next] = c;
          q.push(make_pair(-c, next));
        }
      }
    }
    cout << cost[dst] << endl;
  }

  return 0;
}
