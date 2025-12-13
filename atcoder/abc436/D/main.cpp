// github.com/Johniel/contests
// atcoder/abc436/D/main.cpp

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
  int h, w;
  while (cin >> h >> w) {
    char g[h + 30][w];
    for (int i = 0; i < h + 30; ++i) {
      for (int j = 0; j < w; ++j) {
        g[i][j] = '#';
      }
    }

    for (int j = 'a'; j <= 'z'; ++j) {
      g[h + 1 + j - 'a'][0] = 'A' + (j - 'a');
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    // for (int i = 0; i < h + 30; ++i) {
    //   for (int j = 0; j < w; ++j) cout << g[i][j]; cout << endl;
    // }

    map<char, vec<pair<int ,int>>> m1;
    map<char, vec<pair<int ,int>>> m2;
    for (int i = 0; i < h + 30; ++i) {
      for (int j = 0; j < w; ++j) {
        if ('a' <= g[i][j] && g[i][j] <= 'z') m1[g[i][j]].push_back(make_pair(i, j));
        if ('A' <= g[i][j] && g[i][j] <= 'Z') m2[g[i][j]].push_back(make_pair(i, j));
      }
    }

    const int inf = (1 << 29);
    int cost[h + 30][w];
    for (int i = 0; i < h + 30; ++i) {
      for (int j = 0; j < w; ++j) {
        cost[i][j] = inf;
      }
    }
    cost[0][0] = 0;
    deque<pair<int, int>> q;
    for (q.push_back(make_pair(0, 0)); q.size(); ) {
      auto [i, j] = q.front();
      q.pop_front();
      for (int d = 0; d < 4; ++d) {
        constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
        constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '#') continue;
        if (cost[ni][nj] != inf) continue;
        cost[ni][nj] = cost[i][j] + 1;
        q.push_back(make_pair(ni ,nj));
      }
      if ('a' <= g[i][j] && g[i][j] <= 'z') {
        each (k, m2['A' + (g[i][j] - 'a')]) {
          auto [ni, nj] = k;
          if (g[ni][nj] == '#') continue;
          if (cost[ni][nj] != inf) continue;
          cost[ni][nj] = cost[i][j];
          q.push_front(make_pair(ni ,nj));
        }
      }
      if ('A' <= g[i][j] && g[i][j] <= 'Z') {
        each (k, m1['a' + (g[i][j] - 'A')]) {
          auto [ni, nj] = k;
          if (g[ni][nj] == '#') continue;
          if (cost[ni][nj] != inf) continue;
          cost[ni][nj] = cost[i][j] + 1;
          q.push_back(make_pair(ni ,nj));
        }
      }
    }

    // for (int i = 0; i < h + 30; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     if (cost[i][j] == inf) cout << "_ ";
    //     else cout << cost[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    if (cost[h - 1][w - 1] == inf) cout << -1 << endl;
    else cout << cost[h - 1][w - 1] << endl;
    // break;
  }
  return 0;
}
