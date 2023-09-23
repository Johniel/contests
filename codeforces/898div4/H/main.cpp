// github.com/Johniel/contests
// codeforces/898div4/H/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (const auto p = make_pair(_i, c.at(_i)); true)
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];

bool cycle[N];
int vis[N];
int rec(int curr, int prev)
{
  vis[curr] = vis[prev] + 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    if (vis[next] != -1) {
      cycle[curr] = true;
      return vis[next];
    }
    int x = rec(next, curr);
    if (x != -1) {
      cycle[curr] = (x <= vis[curr]);
      return x;
    }
  }
  return -1;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n, a, b;
  while (cin >> n >> a >> b) {
    --a;
    --b;
    fill(g, g + n, vec<int>());
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    fill(cycle, cycle + n, false);
    fill(vis, vis + n, -1);
    rec(0, 0);

    // for (int i = 0; i < n; ++i) cout << "cycle:" << make_pair(i+1, cycle[i]) << endl;

    // aが追う側
    // bが逃げる側

    int la, lb;
    la = lb = -1;

    map<int, int> costa;
    {
      costa[a] = 0;
      queue<int> q;
      for (q.push(a); q.size(); q.pop()) {
        int curr = q.front();
        if (cycle[curr] && la == -1) la = curr;
        each (next, g[curr]) {
          if (costa.count(next)) continue;
          costa[next] = costa[curr] + 1;
          q.push(next);
        }
      }
    }
    map<int, int> costb;
    {
      costb[b] = 0;
      queue<int> q;
      for (q.push(b); q.size(); q.pop()) {
        int curr = q.front();
        if (cycle[curr] && lb == -1) lb = curr;
        each (next, g[curr]) {
          if (costb.count(next)) continue;
          costb[next] = costb[curr] + 1;
          q.push(next);
        }
      }
    }
    if (a == b) {
      cout << "NO" << endl;
      continue;
    }
    if (cycle[b]) {
      cout << "YES" << endl;
      continue;
    }
    if (costa[lb] <= costb[lb]) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
  }
  return 0;
}
