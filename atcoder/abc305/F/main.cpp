// github.com/Johniel/contests
// atcoder/abc305/F/main.cpp

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

const int N = 100 + 3;
vec<int> g[N];
bool vis[N];
set<int> reach;

bool w[N][N];

void read(int curr)
{
  int k;
  cin >> k;
  vec<int> v(k);
  cin >> v;
  each (i, v) --i;
  each (i, v) reach.insert(i);

  each (next, v) {
    if (!w[curr][next]) g[curr].push_back(next);
    if (!w[next][curr]) g[next].push_back(curr);
  }
  return ;
}

vec<int> bfs(int src)
{
  vec<int> v;
  queue<int> q;
  q.push(src);
  static int cost[N];
  fill(cost, cost + N, -1);
  static int path[N];
  cost[src] = true;
  for (q.push(src); q.size(); q.pop()) {
    int curr = q.front();
    each (next, g[curr]) {
      if (cost[next] == -1) {
        cost[next] = cost[curr] + 1;
        q.push(next);
        path[next] = curr;
        if (!vis[next]) {
          for (int k = next; k != src; k = path[k]) {
            v.push_back(k);
          }
          reverse(v.begin(), v.end());
          return v;
        }
      }
    }
  }
  return v;
}

int main(int argc, char *argv[])
{
  fill(&w[0][0], &w[N - 1][N - 1] + 1, false);

  int n, m;
  cin >> n >> m;
  {
    fill(g, g + N, vec<int>());
    fill(vis, vis + N, false);
    reach.clear();
    int curr = 0;
    while (curr != n - 1) {
      // cout << make_pair(curr, n-1) << endl;
      if (curr == n - 1) break;
      vis[curr] = true;
      read(curr);
      int next = -1;
      each (adj, g[curr]) {
        unless (vis[adj]) {
          next = adj;
          if (next == n - 1) break;
        }
      }
      if (next != -1) {
        curr = next;
        cout << curr + 1 << endl;
      } else {
        vec<int> path = bfs(curr);
        // cout << path << endl;
        for (int i = 0; i < path.size() - 1; ++i) {
          curr = path[i];
          cout << curr + 1 << endl;
          read(curr);
        }
        curr = path.back();
        cout << curr + 1 << endl;
      }
    }
    { str s; cin >> s; }
  }
  return 0;
}
