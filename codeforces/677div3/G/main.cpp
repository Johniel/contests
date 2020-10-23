// codeforces/677div3/G/main.cpp
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

const int N = 1000 + 5;
vec<pair<int, int>> g[N];
int cost[N][N];

void sssp(int src)
{
  priority_queue<pair<int, int>> q;
  q.push({0, src});
  static bool vis[N];
  fill(vis, vis + N, false);
  vis[src] = true;
  cost[src][src] = 0;

  while (q.size()) {
    pair<int, int> p = q.top();
    q.pop();
    int c = abs(p.first);
    int curr = p.second;
    if (cost[src][curr] != c) continue;
    each (e, g[curr]) {
      if (cost[src][e.first] > c + e.second) {
        cost[src][e.first] = c + e.second;
        q.push({-cost[src][e.first], e.first});
      }
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, k;
  while (cin >> n >> m >> k) {
    fill(g, g + N, vec<pair<int, int>>());
    fill(&cost[0][0], &cost[N - 1][N - 1] + 1, (1 << 28));

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }

    vec<pair<int, int>> v(k);
    cin >> v;
    each (i, v) --i.first, --i.second;

    for (int i = 0; i < n; ++i) {
      sssp(i);
    }

    lli mn = 1LL << 60;
    for (int i = 0; i < n; ++i) {
      each (e, g[i]) {
        lli sum = 0;
        each (j, v) {
          sum += min(
            {
              cost[j.first][j.second],
              cost[j.first][i] + cost[e.first][j.second],
              cost[j.first][e.first] + cost[i][j.second]
            }
            );
        }
        setmin(mn, sum);
      }
    }
    cout << mn << endl;
  }

  return 0;
}
