// atcoder/abc035/D/main.cpp
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

const int N = 1e5 + 5;
vector<pair<int, int>> g1[N];
vector<pair<int, int>> g2[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  lli t;
  while (cin >> n >> m >> t) {
    fill(g1, g1 + N, vector<pair<int, int>>());
    fill(g2, g2 + N, vector<pair<int, int>>());

    vector<int> v(n);
    cin >> v;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g1[a].push_back({b, c});
      g2[b].push_back({a, c});
    }

    const lli inf = 1LL << 60;
    static lli cost1[N];
    fill(cost1, cost1 + N, inf);
    static lli cost2[N];
    fill(cost2, cost2 + N, inf);

    auto fn = [] (vector<pair<int, int>> g[], lli cost[]) {
      priority_queue<pair<lli, int>> q;
      q.push({0, 0});
      cost[0] = 0;

      while (q.size()) {
        pair<lli, int> p = q.top();
        q.pop();
        int curr = p.second;
        lli c = -p.first;
        if (c > cost[curr]) continue;
        each (e, g[curr]) {
          int next = e.first;
          lli w = e.second;
          if (cost[next] > cost[curr] + w) {
            cost[next] = cost[curr] + w;
            q.push({-cost[next], next});
          }
        }
      }
    };
    fn(g1, cost1);
    fn(g2, cost2);

    lli mx = 0;
    for (int i = 0; i < n; ++i) {
      if (cost1[i] == inf) continue;
      if (cost2[i] == inf) continue;
      setmax(mx, (t - (cost1[i] + cost2[i])) * v[i]);
    }
    cout << mx << endl;
  }

  return 0;
}
