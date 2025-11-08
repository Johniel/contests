// github.com/Johniel/costests
// atcoder/abc431/E/main.cpp

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
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int inf = (1 << 29);
    const int H = h + 1;
    const int W = w + 1;
    int cost[H][W][4];
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        for (int k = 0; k < 4; ++k) {
          cost[i][j][k] = inf;
        }
      }
    }

    deque<tuple<int, int, int>> q; // i, j, dir
    q.push_back(make_tuple(0, 0, 0));
    cost[0][0][0] = 0;

    while (q.size()) {
      auto [i, j, dir] = q.front();
      q.pop_front();
      if (i == h || j == w) continue;
      // cout << i << ' ' << j  << ' ' << dir << ' ' << cost[i][j][dir] << endl;
      constexpr array<int, 4> di({0, -1, 0, +1});
      constexpr array<int, 4> dj({1, 0, -1, 0});
      // R, U, L, D
      const int R = 0;
      const int U = 1;
      const int L = 2;
      const int D = 3;
      if (g[i][j] == 'A') {
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < H) continue;
          unless (0 <= nj && nj < W) continue;
          const int modify = (d != dir);
          const int nc = cost[i][j][dir] + modify;
          if (cost[ni][nj][d] <= nc) continue;
          cost[ni][nj][d] = nc;
          if (modify) q.push_back(make_tuple(ni, nj, d));
          else        q.push_front(make_tuple(ni, nj, d));
        }
      }
      if (g[i][j] == 'B') {
        map<int, int> m;
        m[R] = D;
        m[D] = R;
        m[L] = U;
        m[U] = L;
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < H) continue;
          unless (0 <= nj && nj < W) continue;
          const int modify = (m[d] != dir);
          const int nc = cost[i][j][dir] + modify;
          if (cost[ni][nj][d] <= nc) continue;
          cost[ni][nj][d] = nc;
          if (modify) q.push_back(make_tuple(ni, nj, d));
          else        q.push_front(make_tuple(ni, nj, d));
        }
      }
      if (g[i][j] == 'C') {
        map<int, int> m;
        m[R] = U;
        m[U] = R;
        m[L] = D;
        m[D] = L;
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < H) continue;
          unless (0 <= nj && nj < W) continue;
          const int modify = (m[d] != dir);
          const int nc = cost[i][j][dir] + modify;
          if (cost[ni][nj][d] <= nc) continue;
          cost[ni][nj][d] = nc;
          if (modify) q.push_back(make_tuple(ni, nj, d));
          else        q.push_front(make_tuple(ni, nj, d));
        }
      }
    }

    // cout << endl;
    // for (int k = 0; k < 4; ++k) {
    //   for (int i = 0; i < H; ++i) {
    //     for (int j = 0; j < W; ++j) {
    //       if (cost[i][j][k] != inf) cout << cost[i][j][k] << ' ';
    //       else cout << "_ ";
    //     }
    //     cout << endl;
    //   }
    //   cout << endl;
    // }

    cout << cost[h - 1][w][0] << endl;
    // break;
  }
  return 0;
}
