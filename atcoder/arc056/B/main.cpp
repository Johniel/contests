// atcoder/arc056/B/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, s;
  while (cin >> n >> m >> s) {
    --s;

    const int N = 2 * 1e5 + 5;
    static vector<int> g[N];
    fill(g, g + N, vector<int>());

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    static int cost[N];
    fill(cost, cost + N, -1);
    priority_queue<pair<int, int>> q;
    q.push(make_pair(s, s));
    cost[s] = s;
    while (q.size()) {
      pair<int, int> p = q.top();
      q.pop();
      int curr = p.second;
      int c = p.first;
      if (cost[curr] < c) continue;
      each (next, g[curr]) {
        int d = min({curr, next, c});
        if (cost[next] < d) {
          cost[next] = d;
          q.push(make_pair(d, next));
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i <= cost[i]) {
        cout << i + 1 << endl;
      }
    }
    cout << endl;
  }

  return 0;
}
