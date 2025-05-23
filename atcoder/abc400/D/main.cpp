// github.com/Johniel/contests
// atcoder/abc400/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  const int H = 1000 + 3;
  const int W = 1000 + 3;
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    pair<int, int> src, dst;
    cin >> src >> dst;
    --src.first;
    --src.second;
    --dst.first;
    --dst.second;
    priority_queue<pair<int, pair<int, int>>> q;
    int cost[h][w];
    const int inf = (1 << 28);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cost[i][j] = inf;
      }
    }
    cost[src.first][src.second] = 0;
    q.push(make_pair(-0, src));
    while (q.size()) {
      auto p = q.top();
      q.pop();
      int c = abs(p.first);
      auto [i, j] = p.second;
      if (cost[i][j] != c) continue;
      constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
      constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        const int nc = cost[i][j];
        if (g[ni][nj] == '.' && cost[ni][nj] > nc) {
          cost[ni][nj] = nc;
          q.push(make_pair(-cost[ni][nj], make_pair(ni, nj)));
        }
      }
      for (int d = 0; d < 4; ++d) {
        for (int l = 1; l <= 2; ++l) {
          int ni = i + (di[d] * l);
          int nj = j + (dj[d] * l);
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          int nc = cost[i][j] + 1;
          if (cost[ni][nj] > nc) {
            cost[ni][nj] = nc;
            q.push(make_pair(-cost[ni][nj], make_pair(ni, nj)));
          }
        }
      }
    }
    cout << cost[dst.first][dst.second] << endl;
  }
  return 0;
}
