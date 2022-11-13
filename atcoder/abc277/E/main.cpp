// github.com/Johniel/contests
// atcoder/abc277/E/main.cpp

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
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{

  int n, m, k;
  while (cin >> n >> m >> k) {
    const int N = 2 * 1e5 + 3;
    static bool y[N];
    static vec<pair<int, int>> g[N];
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }
    fill(y, y + N, false);
    for (int i = 0; i < k; ++i) {
      int z;
      cin >> z;
      --z;
      y[z] = true;
    }
    const int M = 2;
    static int cost[N][M];
    const int inf = 1 << 28;
    fill(&cost[0][0], &cost[N - 1][M - 1] + 1, inf);
    cost[0][0] = 0;
    queue<pair<int, int>> q;
    for (q.push(make_pair(0, 0)); q.size(); q.pop()) {
      auto p = q.front();
      int curr = p.first;
      vec<int> v({p.second});
      if (y[curr]) v.push_back(p.second ^ 1);
      each (e, g[curr]) {
        int next = e.first;
        each (i, v) {
          if (cost[next][i] == inf && ((e.second && !i) || (!e.second && i))) {
            cost[next][i] = cost[curr][p.second] + 1;
            q.push(make_pair(next, i));
          }
        }
      }
    }
    int mn = min(cost[n - 1][0], cost[n - 1][1]);
    cout << (mn == inf ? -1 : mn)  << endl;
  }

  return 0;
}
