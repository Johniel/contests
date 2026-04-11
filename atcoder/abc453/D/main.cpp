// github.com/Johniel/contests
// atcoder/abc453/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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
    const int H = 1000 + 3;
    const int W = 1000 + 3;
    char g[H][W];
    pair<int, int> src;
    pair<int, int> dst;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'G') dst = make_pair(i, j);
      }
    }
    const int inf = (1 << 29);
    const int D = 5;
    static int cost[H][W][D];
    static char path[H][W][D];
    static tuple<int, int, int> prev[H][W][D];
    fill(&cost[0][0][0], &cost[H - 1][W - 1][D - 1] + 1, inf);
    cost[src.first][src.second][0] = 0;
    queue<tuple<int, int, int>> q;
    for (q.push(make_tuple(src.first,src.second, 0)); q.size(); q.pop()) {
      auto [i, j, d] = q.front();
      for (int dir = 0; dir < 4; ++dir) {
        constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
        constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
        const str DS = "RDUL";
        const int ni = i + di[dir];
        const int nj = j + dj[dir];
        if (g[i][j] == 'o' && d != dir) continue;
        if (g[i][j] == 'x' && d == dir) continue;
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '#') continue;
        if (cost[ni][nj][dir] != inf) continue;
        cost[ni][nj][dir] = cost[i][j][d] + 1;
        q.push(make_tuple(ni, nj, dir));
        prev[ni][nj][dir] = q.front();
        path[ni][nj][dir] = DS[dir];
      }
    }

    tuple<int, int, int> curr = make_tuple(-1, -1, -1);
    for (int d = 0; d < D; ++d) {
      if (cost[dst.first][dst.second][d] != inf) {
        curr = make_tuple(dst.first, dst.second, d);
        break;
      }
    }
    if (curr == make_tuple(-1, -1, -1)) {
      cout << "No" << endl;
      continue;
    }

    cout << "Yes" << endl;
    str s;
    while (true) {
      auto [i, j, d] = curr;
      if (src == make_pair(i, j)) break;
      s += path[i][j][d];
      assert(curr != prev[i][j][d]);
      curr = prev[i][j][d];
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}
