// github.com/Johniel/contests
// atcoder/abc413/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  int h, w, k;
  while (cin >> h >> w >> k) {
    vec<pair<int, int>> v(k);
    cin >> v;
    each (i, v) --i.first, --i.second;

    // queue<pair<int, pair<int, int>>> q;
    // each (i, v) q.push(make_pair(0, i));

    int g[h][w];
    int b[2][h][w];
    const int inf = 1 << 29;
    fill(&g[0][0], &g[h - 1][w - 1] + 1, inf);
    fill(&b[0][0][0], &b[2 - 1][h - 1][w - 1] + 1, inf);
    each (i, v) g[i.first][i.second] = 0;
    priority_queue<vec<int>> q;
    each (i, v) q.push(vec<int>({0, i.first, i.second}));

    for (; q.size(); q.pop()) {
      vec<int> u = q.top();
      int cost = abs(u[0]);
      int i = u[1];
      int j = u[2];
      if (g[i][j] != cost) continue;
      constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
      constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
      for (int d = 0; d < 4; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;

        if (b[0][ni][nj] > cost + 1) {
          b[1][ni][nj] = b[0][ni][nj];
          b[0][ni][nj] = cost + 1;
        } else if (b[1][ni][nj] > cost + 1) {
          b[1][ni][nj] = cost + 1;
        }
        if (b[1][ni][nj] < inf) {
          if (g[ni][nj] > b[1][ni][nj]) {
            g[ni][nj] = b[1][ni][nj];
            q.push(vec<int>({-g[ni][nj], ni, nj}));
          }
        }
      }
    }

    lli z = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] < inf) z += g[i][j];
      }
    }
    cout << z << endl;
  }
  return 0;
}
