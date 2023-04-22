// github.com/Johniel/contests
// atcoder/abc299/E/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2000 + 3;
vec<int> g[N];
bool white[N];

void bfs(int src, int d)
{
  queue<int> q;
  const int inf = 1 << 28;
  static int cost[N];
  fill(cost, cost + N, inf);
  cost[src] = 0;
  for (q.push(src); q.size(); q.pop()) {
    int curr = q.front();
    each (next, g[curr]) {
      if (cost[next] == inf) {
        cost[next] = cost[curr] + 1;
        q.push(next);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    if (cost[i] < d) {
      white[i] = true;
    }
  }
  return ;
}

bool verify(int src, int d)
{
  queue<int> q;
  const int inf = 1 << 28;
  static int cost[N];
  fill(cost, cost + N, inf);
  cost[src] = 0;
  for (q.push(src); q.size(); q.pop()) {
    int curr = q.front();
    each (next, g[curr]) {
      if (cost[next] == inf) {
        cost[next] = cost[curr] + 1;
        q.push(next);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    if (cost[i] == d && !white[i]) return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int k;
    cin >> k;
    fill(white, white + N, false);
    vec<pair<int, int>> v(k);
    cin >> v;
    each (i, v) --i.first;
    each (i, v) bfs(i.first, i.second);
    bool f = true;
    each (i, v) f = f && verify(i.first, i.second);
    if (!f) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      for (int i = 0; i < n; ++i) {
        cout << int(!white[i]);
      }
      cout << endl;
    }
  }
  return 0;
}
