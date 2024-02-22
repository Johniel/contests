// github.com/Johniel/contests
// atcoder/arc019/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int h, w, battle;
  while (cin >> h >> w >> battle) {
    const int H = 50 + 2;
    const int W = 50 + 2;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    pair<int, int> src;
    pair<int, int> dst;
    pair<int, int> dust;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'S') {
          src = make_pair(i, j);
          g[i][j] = '.';
        }
        if (g[i][j] == 'C') {
          dust = make_pair(i, j);
          g[i][j] = '.';
        }
        if (g[i][j] == 'G') {
          dst = make_pair(i, j);
          g[i][j] = '.';
        }
      }
    }

    const int K = 100 + 1;

    const int inf = 1 << 26;

    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};

    // src->*
    static int a[H][W][K];
    {
      fill(&a[0][0][0], &a[H - 1][W - 1][K - 1] + 1, inf);
      a[src.first][src.second][0] = 0;
      queue<tuple<int, int, int>> q;
      for (q.push(make_tuple(src.first, src.second, 0)); q.size(); q.pop()) {
        auto [i, j, k] = q.front();
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == 'T') continue;
          int nk = k + (g[ni][nj] == 'E');
          unless (nk < K) continue;
          if (a[ni][nj][nk] != inf) continue;
          a[ni][nj][nk] = a[i][j][k] + 1;
          q.push(make_tuple(ni, nj, nk));
        }
      }
    }
    // dst->*
    static int b[H][W][K];
    {
      fill(&b[0][0][0], &b[H - 1][W - 1][K - 1] + 1, inf);
      b[dst.first][dst.second][0] = 0;
      queue<tuple<int, int, int>> q;
      for (q.push(make_tuple(dst.first, dst.second, 0)); q.size(); q.pop()) {
        auto [i, j, k] = q.front();
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == 'T') continue;
          int nk = k + (g[ni][nj] == 'E');
          unless (nk < K) continue;
          if (b[ni][nj][nk] != inf) continue;
          b[ni][nj][nk] = b[i][j][k] + 1;
          q.push(make_tuple(ni, nj, nk));
        }
      }
    }
    // dust->*
    static int c[H][W][K];
    {
      fill(&c[0][0][0], &c[H - 1][W - 1][K - 1] + 1, inf);
      c[dust.first][dust.second][0] = 0;
      queue<tuple<int, int, int>> q;
      for (q.push(make_tuple(dust.first, dust.second, 0)); q.size(); q.pop()) {
        auto [i, j, k] = q.front();
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == 'T') continue;
          int nk = k + (g[ni][nj] == 'E');
          unless (nk < K) continue;
          if (c[ni][nj][nk] != inf) continue;
          c[ni][nj][nk] = c[i][j][k] + 1;
          q.push(make_tuple(ni, nj, nk));
        }
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 1; k <= battle; ++k) {
          setmin(a[i][j][k], a[i][j][k - 1]);
          setmin(b[i][j][k], b[i][j][k - 1]);
          setmin(c[i][j][k], c[i][j][k - 1]);
          // if (a[i][j][k] != inf) setmin(a[i][j][k], a[i][j][k - 1]);
          // if (b[i][j][k] != inf) setmin(b[i][j][k], b[i][j][k - 1]);
          // if (c[i][j][k] != inf) setmin(c[i][j][k], c[i][j][k - 1]);
        }
      }
    }

    int z = inf;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'T') continue;
        for (int b1 = 0; b1 <= battle; ++b1) {
          for (int b2 = 0; b1 + b2 <= battle; ++b2) {
            int r = battle - b1 - b2;
            setmin(z, a[i][j][b1] + b[i][j][b2] + c[i][j][r] * 2);
          }
        }
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'E') {
          for (int b1 = 0; b1 <= battle; ++b1) {
            for (int b2 = 0; b2 <= battle; ++b2) {
              int r = battle - b1 - b2;
              if (0 <= r && r <= battle) {
                setmin(z, a[i][j][b1 + 1] + b[i][j][b2 + 1] + c[i][j][r] * 2);
              }
            }
          }
        }
      }
    }
    cout << (z < inf ? z : -1) << endl;
  }
  return 0;
}
