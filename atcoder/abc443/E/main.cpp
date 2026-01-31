// github.com/Johniel/contests
// atcoder/abc443/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, c;
  while (cin >> n >> c) {
    char g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    vec<int> v[n];
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (g[i][j] == '#') v[j].push_back(i);
      }
    }
    const int inf = 1 << 29;
    bool vis[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        vis[i][j] = false;
      }
    }
    vec<int> head(n, -inf);
    queue<pair<int, int>> q;
    q.push(make_pair(n - 1, c - 1));
    vis[n - 1][c - 1] = true;
    head[c - 1] = n - 1;
    while (q.size()) {
      auto [i, j] = q.front();
      setmax(head[j], i);
      q.pop();
      int di[] = {-1, -1, -1};
      int dj[] = {-1,  0, +1};
      for (int d = 0; d < 3; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < n) continue;
        unless (0 <= nj && nj < n) continue;
        if (vis[ni][nj]) {
          continue;
        }
        if (g[ni][nj] == '.') {
          q.push(make_pair(ni, nj));
          vis[ni][nj] = true;
          continue;
        }
        if (g[ni][nj] == '#' && v[nj].back() == ni) {
          q.push(make_pair(ni, nj));
          vis[ni][nj] = true;
          continue;
        }
        if (g[ni][nj] == '#' && 0 <= head[nj] && v[nj].back() <= head[nj]) {
          q.push(make_pair(ni, nj));
          vis[ni][nj] = true;
          continue;
        }
      }
    }
    // cout << head << endl;
    for (int j = 0; j < n; ++j) {
      cout << vis[0][j];
    }
    cout << endl;
    // for (int j = 0; j < n; ++j) {
    //   if (head[j] == -inf) cout << 0;
    //   else if (v[j].empty()) cout << 1;
    //   else if (head[j] <= v[j].front()) cout << 1;
    //   else if (v[j].back() <= head[j]) cout << 1;
    //   else if (vis[0][j]) cout << 1;
    //   else cout << 0;
    // }
    // cout << endl;
  }
  return 0;
}
