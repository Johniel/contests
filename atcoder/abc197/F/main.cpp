// atcoder/abc197/F/main.cpp
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

const int N = 1000 + 3;
vec<pair<int, char>> g[N];


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<pair<int, char>>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      char c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }

    const int inf = 1 << 29;
    static int cost[N][N];
    fill(&cost[0][0], &cost[N - 1][N - 1] + 1, inf);
    cost[0][n - 1] = 0;
    priority_queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, n - 1)));
    while (q.size()) {
      auto p = q.top();
      q.pop();
      int c = abs(p.first);
      int a = p.second.first;
      int b = p.second.second;
      map<char, vec<int>> x, y;
      each (i, g[a]) x[i.second].push_back(i.first);
      each (i, g[b]) y[i.second].push_back(i.first);
      for (char d = 'a'; d <= 'z'; ++d) {
        each (i, x[d]) {
          each (j, y[d]) {
            int nc = c + 2;
            if (cost[i][j] > nc) {
              cost[i][j] = nc;
              q.push(make_pair(-nc, make_pair(i, j)));
            }
          }
        }
      }
    }
    int mn = inf;
    for (int i = 0; i < N; ++i) {
      setmin(mn, cost[i][i]);
    }
    for (int i = 0; i < n; ++i) {
      each (e, g[i]) {
        int j = e.first;
        setmin(mn, cost[i][j] + 1);
      }
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
